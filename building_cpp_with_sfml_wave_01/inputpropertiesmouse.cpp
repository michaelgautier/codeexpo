#include "inputpropertiesmouse.h"
using namespace Gautier::SFMLApp;

const Point InputPropertiesMouse::GetLastMouseCoordinates()
{
	return _LastMouseCoordinates;
}

const MouseButton InputPropertiesMouse::GetLastMouseButtonPressed()
{
	return _LastMouseButtonPressed;
}

const SFMLEventType InputPropertiesMouse::GetLastMouseEvent()
{
	return _LastMouseEvent;
}

const Point InputPropertiesMouse::GetMouseCoordinates()
{
	return _MouseCoordinates;
}

const MouseButton InputPropertiesMouse::GetMouseButtonPressed()
{
	return _MouseButtonPressed;
}

const SFMLEventType InputPropertiesMouse::GetMouseEvent()
{
	return _MouseEvent;
}

const bool InputPropertiesMouse::GetMouseClicked()
{
	return _MouseClicked;
}

void InputPropertiesMouse::InterpretInteractionEvent(const SFMLEvent& interactionEvent)
{
	bool MouseButtonWasPressed = (interactionEvent.type == SFMLEventType::MouseButtonPressed);
	bool MouseButtonWasReleased = (interactionEvent.type == SFMLEventType::MouseButtonReleased);

	if(
	    MouseButtonWasPressed ||
	    MouseButtonWasReleased
	)
	{
		_MouseEvent = interactionEvent.type;
		_MouseCoordinates = Point(interactionEvent.mouseButton.x, interactionEvent.mouseButton.y);
		_MouseButtonPressed = interactionEvent.mouseButton.button;
	}
}
