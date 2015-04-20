#include "central.hpp"
#include "confv.hpp"
#include "interactionexplore.hpp"
#include "interactionhold.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>

gautier::central::central() {
	_desktopwidth = 0;
	_desktopheight = 0;
	_desktopbitsperpixel = 0;
	_acceptingkeyingtotarget = 0;
	_allowconsoleoutputwindowandframelayoutstate = 0;

	/*
	    Objects to render and interact with.

	    The main elements are here and the functions below coordinate and manage all aspects.

	    The elements should be stateless.
	*/
	_defaultfont = sf::Font();/*This is tested to work on Ubuntu 14.04 but we will need a more generic way to get the font.*/

	if(_defaultfont.loadFromFile("/usr/share/fonts/truetype/droid/DroidSans.ttf")) {
		std::cout << "font loaded" << std::endl;
	}

	createcentralwindow();
	_currentframe = interactionexplore(sf::Vector2f(0, 0));;/*glorified background with custom padding and equidistant reorientation.*/

	_field1 = sf::RectangleShape(sf::Vector2f(0,0));
	_field1textforrender = sf::Text();
}
void gautier::central::createcentralwindow() {
	_centralwindow = new sf::RenderWindow(createdefaultvideomode(),confv::centralwindowname);
	_centralwindow->setPosition(sf::Vector2i(0,0));/*center this later*/

	return;
}
const sf::VideoMode gautier::central::createdefaultvideomode() {
	sf::VideoMode desktopmode = sf::VideoMode::getDesktopMode();

	_desktopbitsperpixel = desktopmode.bitsPerPixel;
	_desktopheight = desktopmode.height;
	_desktopwidth = desktopmode.width;

	uint preferredwidth = confv::centralwindowdefaultwidth;
	uint preferredheight = confv::centralwindowdefaultheight;

	if(preferredheight > _desktopheight) {
		preferredheight = _desktopheight;
	}

	if(preferredwidth > _desktopwidth) {
		preferredwidth = _desktopwidth;
	}

	if(preferredheight == _desktopheight) {
		preferredheight -= 8;
	}

	if(preferredwidth == _desktopwidth) {
		preferredwidth -= 8;
	}

	desktopmode = sf::VideoMode(preferredwidth, preferredheight, _desktopbitsperpixel);

	return desktopmode;
}
int gautier::central::execute() {
	cyclethroughevents();

	return EXIT_SUCCESS;
}
/*
    Standard platform event query, event data capture, and event acknowledgement.
*/
void gautier::central::cyclethroughevents() {
	while (_centralwindow->isOpen()) {
		sf::Event currentevent;
		while (_centralwindow->pollEvent(currentevent)) {
			_interactionstate.trackevent(currentevent.type, currentevent);

			processeventstate();
			buildrenderstate();
		}

		if(_interactionstate.windowisvalid()) {
			processrenderstate();
		} else {
			break;
		}
	}
}
/*
    STEP 1: Event Interpretation.
*/
void gautier::central::processeventstate() {
	_interactionstate.decidemouseeventstate();

	if(_interactionstate.mouseclicked()) {
		std::cout << "mouse clicked" << std::endl;

		_acceptingkeyingtotarget = _field1.getGlobalBounds().contains(_interactionstate.currentmousebuttoncoords());

		if(_acceptingkeyingtotarget) {
			std::cout << "clicked within field1" << std::endl;
			_keyboardrendertarget = _field1;
		}
	}

}
/*
    STEP 2: Output Construction.
*/
void gautier::central::buildrenderstate() {
	/*Place and arrange the window first if necessary.*/
	if(_interactionstate.resized()) {
		sf::FloatRect visiblearea(0,0, _interactionstate.width(), _interactionstate.height());
		_centralwindow->setView(sf::View(visiblearea));

		showprimaryframeconsoleoutput();
	}

	_currentframe.buildrenderstate(sf::Vector2u(_interactionstate.width(), _interactionstate.height()));

	/*This is definitely not the way to do it, but we are marching quickly towards testing a certain idea around input.*/
	_field1.setFillColor(sf::Color::White);
	_field1.setSize(sf::Vector2f(200, 20));
	_field1.setPosition(sf::Vector2f(100.05, 100.05));
	_field1.setOutlineColor(sf::Color::Black);
	_field1.setOutlineThickness(1);

	_field1textforrender.setFont(_defaultfont);
	_field1textforrender.setCharacterSize(12);
	_field1textforrender.setColor(sf::Color::Black);
	_field1textforrender.setPosition(_field1.getPosition());

    _interactionstate.buildfieldtext(_field1, _field1textforrender);
}
/*
    STEP 3: Concrete Display Mechanics.
*/
void gautier::central::processrenderstate() {
	_centralwindow->clear(sf::Color::Blue);
	_centralwindow->draw(_currentframe);
	_centralwindow->draw(_field1);
	_centralwindow->draw(_field1textforrender);
	_centralwindow->display();
}
/*
    Diagnostic support.
*/
void gautier::central::showprimaryframeconsoleoutput() {
	if(_allowconsoleoutputwindowandframelayoutstate) {
		sf::View windowview = _centralwindow->getView();

		std::cout << "window _width " << _interactionstate.width() << " _height " << _interactionstate.height() << std::endl;
		std::cout << "window   w " << _centralwindow->getSize().x << "  h " << _centralwindow->getSize().y << std::endl;

		std::cout << "window   pos x " << _centralwindow->getPosition().x << "  pos y " << _centralwindow->getPosition().y << std::endl;

		std::cout << "view x " << windowview.getCenter().x << " view y " << windowview.getCenter().y << std::endl;
		std::cout << "view w " << windowview.getSize().x << " view h " << windowview.getSize().y << std::endl;
		std::cout << "viewport top " << windowview.getViewport().top << "  bounds l left " << windowview.getViewport().left << "  bounds l width " << windowview.getViewport().width << "  bounds l height " << windowview.getViewport().height << std::endl;

		std::cout << "frame   w " << _currentframe.getSize().x << "  h " << _currentframe.getSize().y << std::endl;

		std::cout << "frame   pos x " << _currentframe.getPosition().x << "  pos y " << _currentframe.getPosition().y << std::endl;
		std::cout << "frame   ori x " << _currentframe.getOrigin().x << "  ori y " << _currentframe.getOrigin().y << std::endl;

		std::cout << "frame   scl x " << _currentframe.getScale().x << "  scl y " << _currentframe.getScale().y << std::endl;

		std::cout << "frame bounds l top " << _currentframe.getLocalBounds().top << "  bounds l left " << _currentframe.getLocalBounds().left << "  bounds l width " << _currentframe.getLocalBounds().width << "  bounds l height " << _currentframe.getLocalBounds().height << std::endl;
		std::cout << "frame bounds g top " << _currentframe.getGlobalBounds().top << "  bounds g left " << _currentframe.getGlobalBounds().left << "  bounds g width " << _currentframe.getGlobalBounds().width << "  bounds g height " << _currentframe.getGlobalBounds().height << std::endl;
	}
}
gautier::central::~central() {
	delete _centralwindow;
}
