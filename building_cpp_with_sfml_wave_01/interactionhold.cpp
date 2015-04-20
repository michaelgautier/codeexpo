#include "central.hpp"
#include "confv.hpp"
#include "interactionexplore.hpp"
#include "interactionhold.hpp"
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
gautier::interactionhold::interactionhold() {
	/*
	    Global status, data, and information.
	*/
	_width = 0;
	_height = 0;
	_resized = 0;
	_windowisvalid = true;

	/*
	    Input state: Mouse
	*/
	_mouseclicked = 0;

	/*
	    Input state: Mouse
	*/
	_lastmouseevent = sf::Event::Count;
	_lastmousebuttonpressed = sf::Mouse::ButtonCount;
	_lastmousebuttoncoords = sf::Vector2f(-1,-1);

	_currentmouseevent = sf::Event::Count;
	_currentmousebuttonpressed = sf::Mouse::ButtonCount;
	_currentmousebuttoncoords = sf::Vector2f(-1,-1);

	/*
	    Input state: Keyboard
	*/
	_cursoractive = 0;

	_lastkeyboardkey = sf::Keyboard::Unknown;
	_currentkeyboardkey = sf::Keyboard::Unknown;

	_textbuffer = "";
	_field1textmaxlength = 0;

	/*
	    Diagnostic support.
	*/
	_allowconsoleoutputwindowandframelayoutstate = 0;
	_allowconsoleoutputmouseeventstate = 0;
	_allowconsoleoutputkeyboardeventstate = 0;
	_allowconsoleoutputinputeffectivestate = 0;
}

gautier::interactionhold::~interactionhold() {
	//dtor
}
void gautier::interactionhold::trackevent(sf::Event::EventType eventtype, sf::Event& eventdata) {
	char currentchar;
	switch (eventtype) {
	case sf::Event::Resized:
		_resized = true;

		_width = eventdata.size.width;
		_height = eventdata.size.height;

		break;
	case sf::Event::Closed:
		_windowisvalid = false;
		break;
	case sf::Event::TextEntered: 
		currentchar = (const char)eventdata.text.unicode;
		_textbuffer += currentchar;

		if(_allowconsoleoutputkeyboardeventstate) {
			std::cout << "value:     " << currentchar << std::endl;
			std::cout << _textbuffer << std::endl;
		}
		break;
	case sf::Event::KeyPressed: 
		_currentkeyboardkey = eventdata.key.code;

		if(_allowconsoleoutputkeyboardeventstate) {
			std::cout << "key down:  " << _currentkeyboardkey << std::endl;
		}
		break;
	case sf::Event::KeyReleased: 
		_currentkeyboardkey = eventdata.key.code;

		if(_allowconsoleoutputkeyboardeventstate) {
			std::cout << "key up:    " << _currentkeyboardkey << std::endl;
		}
		break;
	case sf::Event::MouseButtonPressed: 
	case sf::Event::MouseButtonReleased: 
		_currentmouseevent = eventdata.type;
		_currentmousebuttoncoords = sf::Vector2f(eventdata.mouseButton.x, eventdata.mouseButton.y);
		_currentmousebuttonpressed = eventdata.mouseButton.button;

		if(_allowconsoleoutputmouseeventstate) {
			std::cout << "mouse x " << _currentmousebuttoncoords.x << " mouse y " << _currentmousebuttoncoords.y << std::endl;
			std::cout << "mouse button " << (_currentmousebuttonpressed == sf::Mouse::Left ? "left " : "") << (_currentmousebuttonpressed == sf::Mouse::Right ? "right " : "") << std::endl;
		}
		break;
	case sf::Event::MouseWheelMoved: /*not implemented yet*/
		break;
	case sf::Event::MouseMoved: /*not implemented yet*/
		break;
	case sf::Event::MouseEntered: /*not implemented yet*/
		break;
	case sf::Event::MouseLeft: /*not implemented yet*/
		break;
	case sf::Event::LostFocus: /*not implemented yet*/
		break;
	case sf::Event::GainedFocus: /*not implemented yet*/
		break;
	case sf::Event::JoystickButtonPressed: /*not implemented yet*/
		break;
	case sf::Event::JoystickButtonReleased: /*not implemented yet*/
		break;
	case sf::Event::JoystickMoved: /*not implemented yet*/
		break;
	case sf::Event::JoystickConnected: /*not implemented yet*/
		break;
	case sf::Event::JoystickDisconnected: /*not implemented yet*/
		break;
	case sf::Event::Count: /*not implemented yet*/
		break;
	}
}
void gautier::interactionhold::decidemouseeventstate() {
//_allowconsoleoutputinputeffectivestate
	_mouseclicked = (_lastmouseevent == sf::Event::MouseButtonPressed && _currentmouseevent == sf::Event::MouseButtonReleased);
}
void gautier::interactionhold::endprocesseventstate() {
	_lastmouseevent = _currentmouseevent;
	_lastmousebuttonpressed = _currentmousebuttonpressed;
	_lastmousebuttoncoords = _currentmousebuttoncoords;

	_lastkeyboardkey = _currentkeyboardkey;
}

sf::Event::EventType gautier::interactionhold::lastmouseevent() {
	return _lastmouseevent;
}
sf::Mouse::Button gautier::interactionhold::lastmousebuttonpressed() {
	return _lastmousebuttonpressed;
}
sf::Vector2f gautier::interactionhold::lastmousebuttoncoords() {
	return _lastmousebuttoncoords;
}

sf::Event::EventType gautier::interactionhold::currentmouseevent() {
	return _currentmouseevent;
}
sf::Mouse::Button gautier::interactionhold::currentmousebuttonpressed() {
	return _currentmousebuttonpressed;
}
sf::Vector2f gautier::interactionhold::currentmousebuttoncoords() {
	return _currentmousebuttoncoords;
}

bool gautier::interactionhold::resized() {
	bool resizedvalue = _resized;
	_resized=false;

	return resizedvalue;
}
float gautier::interactionhold::width() {
	return _width;
}

float gautier::interactionhold::height() {
	return _height;

}
std::string& gautier::interactionhold::textbuffer() {
	return _textbuffer;
}
bool gautier::interactionhold::mouseclicked() {
	return _mouseclicked;
}
bool gautier::interactionhold::windowisvalid() {
	return _windowisvalid;
}
void gautier::interactionhold::buildfieldtext(sf::RectangleShape& fieldvisual, sf::Text& fieldtext) {
	bool textisempty = textbuffer().empty();

	if(!textisempty && _field1textmaxlength == 0) {
		int fieldwidth = fieldvisual.getSize().x;

		sf::FloatRect textbounds = fieldtext.getGlobalBounds();

		if(textbounds.width >= fieldwidth) {
			if(_field1textmaxlength == 0) {
				_field1textmaxlength = textbuffer().size();
			}
		}
	}

	if(!textisempty && _field1textmaxlength > 0) {
		fieldtext.setString(textbuffer());
	} else {
		fieldtext.setString(textbuffer());
	}
}
