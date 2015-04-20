#include "inputpropertieskeyboard.h"
using namespace Gautier::SFMLApp::InteractionDeviceFundamentals;

const KeyboardKey InputPropertiesKeyboard::GetLastKeyboardKeyPressed() const
{
    return _LastKeyboardKeyPressed;
}

const SFMLEventType InputPropertiesKeyboard::GetLastKeyboardEvent() const
{
    return _LastKeyboardEvent;
}

const KeyboardKey InputPropertiesKeyboard::GetKeyboardKeyPressed() const
{
    return _KeyboardKeyPressed;
}

const SFMLEventType InputPropertiesKeyboard::GetKeyboardEvent() const
{
    return _KeyboardEvent;
}

void InputPropertiesKeyboard::InterpretInteractionEvent(const SFMLEvent& interactionEvent)
{
    auto KeyWasPressed = (interactionEvent.type == SFMLEventType::KeyPressed);
    auto KeyWasReleased = (interactionEvent.type == SFMLEventType::KeyReleased);
    auto TextWasEntered = (interactionEvent.type == SFMLEventType::TextEntered);

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
        auto TextValue = (const char)interactionEvent.text.unicode;

        _TextBuffer += TextValue;
    }
}
