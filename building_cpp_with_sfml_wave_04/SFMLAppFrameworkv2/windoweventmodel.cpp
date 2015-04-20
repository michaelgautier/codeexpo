#include "windoweventmodel.h"
using namespace Gautier::SFMLApp::MVCModels;

const InputPropertiesWindow& WindowEventModel::GetInputPropertiesWindow() const
{
    return _InputPropertiesWindow;
}

const InputPropertiesMouse& WindowEventModel::GetInputPropertiesMouse() const
{
    return _InputPropertiesMouse;
}

const InputPropertiesKeyboard& WindowEventModel::GetInputPropertiesKeyboard() const
{
    return _InputPropertiesKeyboard;
}

void WindowEventModel::InterpretInteractionEvent(const SFMLEvent& interactionEvent)
{
    _InputPropertiesWindow.InterpretInteractionEvent(interactionEvent);
    _InputPropertiesMouse.InterpretInteractionEvent(interactionEvent);
    _InputPropertiesKeyboard.InterpretInteractionEvent(interactionEvent);
}
