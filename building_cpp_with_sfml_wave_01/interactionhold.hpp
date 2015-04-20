#ifndef INTERACTIONHOLD_HPP
#define INTERACTIONHOLD_HPP
#include <string>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
namespace gautier {
class interactionhold {
public:
	interactionhold();
	~interactionhold();

	void trackevent(sf::Event::EventType eventtype, sf::Event& eventdata);
	void decidemouseeventstate();
	void endprocesseventstate();

	bool resized();
	float width();
	float height();
	std::string& textbuffer();

	sf::Event::EventType lastmouseevent();
	sf::Mouse::Button lastmousebuttonpressed();
	sf::Vector2f lastmousebuttoncoords();

	sf::Event::EventType currentmouseevent();
	sf::Mouse::Button currentmousebuttonpressed();
	sf::Vector2f currentmousebuttoncoords();

	bool mouseclicked();
	bool windowisvalid();
	void buildfieldtext(sf::RectangleShape& fieldvisual, sf::Text& fieldtext);
protected:
private:
	/*
	    Global status, data, and information.
	*/
	float _width;
	float _height;
	bool _resized;
	bool _windowisvalid;

	/*
	    Input state: Mouse
	*/
	bool _mouseclicked;

	/*
	    Input state: Mouse
	*/
	sf::Event::EventType _lastmouseevent;
	sf::Mouse::Button _lastmousebuttonpressed;
	sf::Vector2f _lastmousebuttoncoords;

	sf::Event::EventType _currentmouseevent;
	sf::Mouse::Button _currentmousebuttonpressed;
	sf::Vector2f _currentmousebuttoncoords;

	/*
	    Input state: Keyboard
	*/
	bool _cursoractive;

	sf::Keyboard::Key _lastkeyboardkey;
	sf::Keyboard::Key _currentkeyboardkey;

	std::string _textbuffer;
    int _field1textmaxlength;

	/*
	    Diagnostic support.
	*/
	bool _allowconsoleoutputwindowandframelayoutstate;
	bool _allowconsoleoutputmouseeventstate;
	bool _allowconsoleoutputkeyboardeventstate;
	bool _allowconsoleoutputinputeffectivestate;
};
}
#endif // INTERACTIONHOLD_HPP
