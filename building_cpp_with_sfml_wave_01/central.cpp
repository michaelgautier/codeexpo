#include "central.hpp"
#include "confv.hpp"
#include "interactionexplore.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
central::central() {
	_width = 0;
	_height = 0;
	_resized = false;
	_allowconsoleoutput = true;

	centralwindow = new sf::RenderWindow(createdefaultvideomode(),confv::centralwindowname());
	currentframe = interactionexplore(sf::Vector2f(0, 0));
}
const sf::VideoMode central::createdefaultvideomode() {
	sf::VideoMode desktopmode = sf::VideoMode::getDesktopMode();

	_desktopbitsperpixel = desktopmode.bitsPerPixel;
	_desktopheight = desktopmode.height;
	_desktopwidth = desktopmode.width;

	desktopmode = sf::VideoMode(800, 600, _desktopbitsperpixel);

	return desktopmode;
}
int central::execute() {
	buildeventstate();

	return EXIT_SUCCESS;
}
void central::buildeventstate() {
	while (centralwindow->isOpen()) {
		sf::Event currentevent;
		while (centralwindow->pollEvent(currentevent)) {
			if (currentevent.type == sf::Event::Closed) {
				centralwindow->close();
				break;
			} else {
				if(currentevent.type == sf::Event::Resized) {
					_resized = true;

					_width = currentevent.size.width;
					_height = currentevent.size.height;
				}
				processeventstate();
				buildrenderstate();
			}
		}
		processrenderstate();
	}
}
void central::buildrenderstate() {
	currentframe.setFillColor(sf::Color::Black);
	currentframe.setSize(sf::Vector2f(_width, _height));
	currentframe.setPosition(sf::Vector2f(0,0));
}
void central::processeventstate() {
	if(_resized) {
		_resized=false;

        sf::FloatRect visiblearea(0,0, _width, _height);
		centralwindow->setView(sf::View(visiblearea));

		showconsoleoutput();
	}
}
void central::processrenderstate() {
	centralwindow->clear(sf::Color::Blue);
	centralwindow->draw(currentframe);
	centralwindow->display();
}
void central::showconsoleoutput(){
    if(_allowconsoleoutput) {
        sf::View windowview = centralwindow->getView();

        std::cout << "window _width " << _width << " _height " << _height << "\n";
        std::cout << "window   w " << centralwindow->getSize().x << "  h " << centralwindow->getSize().y << "\n";

        std::cout << "window   pos x " << centralwindow->getPosition().x << "  pos y " << centralwindow->getPosition().y << "\n";

        std::cout << "view x " << windowview.getCenter().x << " view y " << windowview.getCenter().y << "\n";
        std::cout << "view w " << windowview.getSize().x << " view h " << windowview.getSize().y << "\n";
        std::cout << "viewport top " << windowview.getViewport().top << "  bounds l left " << windowview.getViewport().left << "  bounds l width " << windowview.getViewport().width << "  bounds l height " << windowview.getViewport().height << "\n";

        std::cout << "frame   w " << currentframe.getSize().x << "  h " << currentframe.getSize().y << "\n";

        std::cout << "frame   pos x " << currentframe.getPosition().x << "  pos y " << currentframe.getPosition().y << "\n";
        std::cout << "frame   ori x " << currentframe.getOrigin().x << "  ori y " << currentframe.getOrigin().y << "\n";

        std::cout << "frame   scl x " << currentframe.getScale().x << "  scl y " << currentframe.getScale().y << "\n";

        std::cout << "frame bounds l top " << currentframe.getLocalBounds().top << "  bounds l left " << currentframe.getLocalBounds().left << "  bounds l width " << currentframe.getLocalBounds().width << "  bounds l height " << currentframe.getLocalBounds().height << "\n";
        std::cout << "frame bounds g top " << currentframe.getGlobalBounds().top << "  bounds g left " << currentframe.getGlobalBounds().left << "  bounds g width " << currentframe.getGlobalBounds().width << "  bounds g height " << currentframe.getGlobalBounds().height << "\n";
    }
}
central::~central() {
	delete centralwindow;
}
