#include "inputpropertiesmouse.h"
using namespace Gautier::SFMLApp::InteractionDeviceFundamentals;

const Point InputPropertiesMouse::GetLastMouseCoordinates() const
{
    return _LastMouseCoordinates;
}

const MouseButton InputPropertiesMouse::GetLastMouseButtonPressed() const
{
    return _LastMouseButtonPressed;
}

const SFMLEventType InputPropertiesMouse::GetLastMouseEvent() const
{
    return _LastMouseEvent;
}

const Point InputPropertiesMouse::GetMouseCoordinates() const
{
    return _MouseCoordinates;
}

const MouseButton InputPropertiesMouse::GetMouseButtonPressed() const
{
    return _MouseButtonPressed;
}

const SFMLEventType InputPropertiesMouse::GetMouseEvent() const
{
    return _MouseEvent;
}

const bool InputPropertiesMouse::GetMouseClicked() const
{
    return _MouseClicked;
}

void InputPropertiesMouse::InterpretInteractionEvent(const SFMLEvent& interactionEvent)
{
    auto MouseButtonWasPressed = (interactionEvent.type == SFMLEventType::MouseButtonPressed);
    auto MouseButtonWasReleased = (interactionEvent.type == SFMLEventType::MouseButtonReleased);

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
