#ifndef central_hpp
#define central_hpp
#include "confv.hpp"
#include "interactionexplore.hpp"
#include "interactionhold.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <string>
namespace gautier {
class central {
public:
	central();
	~central();
	/*
	    Primary entry point.
	*/
	int execute();
private:
	/*
	    Global status, data, and information.
	*/
	interactionhold _interactionstate;

	uint _desktopwidth;
	uint _desktopheight;
	uint _desktopbitsperpixel;

	/*
	    Input target
	*/
	sf::RectangleShape _keyboardrendertarget;
	bool _acceptingkeyingtotarget;

	/*
	    Diagnostic support.
	*/
	bool _allowconsoleoutputwindowandframelayoutstate;

	/*
	    Objects to render and interact with.

	    The main elements are here and the functions below coordinate and manage all aspects.

	    The elements should be stateless.
	*/
	sf::RenderWindow* _centralwindow;/*visually contains everything*/
	interactionexplore _currentframe;/*glorified background with custom padding and equidistant reorientation.*/
	sf::RectangleShape _field1;
	sf::Text _field1textforrender;

	sf::Font _defaultfont;

	/*
	    default window size.
	*/
	const sf::VideoMode createdefaultvideomode();

	/*
	    Controls the status, data and rendering.
	*/
	void createcentralwindow();

	/*
	    Standard platform event query, event data capture, and event acknowledgement.
	*/
	void cyclethroughevents();
	/*
	    STEP 1: Event Interpretation.
	*/
	void processeventstate();
	/*
	    STEP 2: Output Construction.
	*/
	void buildrenderstate();
	/*
	    STEP 3: Concrete Display Mechanics.
	*/
	void processrenderstate();

	/*
	    Diagnostic support.
	*/
	void showprimaryframeconsoleoutput();
};
}
#endif
