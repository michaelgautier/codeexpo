#include "inputpropertieskeyboard.h"
using namespace Gautier::SFMLApp;

const KeyboardKey InputPropertiesKeyboard::GetLastKeyboardKeyPressed()
{
	return _LastKeyboardKeyPressed;
}

const SFMLEventType InputPropertiesKeyboard::GetLastKeyboardEvent()
{
	return _LastKeyboardEvent;
}

const KeyboardKey InputPropertiesKeyboard::GetKeyboardKeyPressed()
{
	return _KeyboardKeyPressed;
}

const SFMLEventType InputPropertiesKeyboard::GetKeyboardEvent()
{
	return _KeyboardEvent;
}

void InputPropertiesKeyboard::InterpretInteractionEvent(const SFMLEvent& interactionEvent)
{
	bool KeyWasPressed = (interactionEvent.type == SFMLEventType::KeyPressed);
	bool KeyWasReleased = (interactionEvent.type == SFMLEventType::KeyReleased);
	bool TextWasEntered = (interactionEvent.type == SFMLEventType::TextEntered);

	if(
	    KeyWasPressed ||
	    KeyWasReleased
	)
	{
		_KeyboardEvent = interactionEvent.type;
		_KeyboardKeyPressed = interactionEvent.key.code;
	}

	if(TextWasEntered)
	{
		char TextValue = (const char)interactionEvent.text.unicode;

		_TextBuffer += TextValue;
	}
}
