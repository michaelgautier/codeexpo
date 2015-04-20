#include "windoweventmodel.h"
using namespace Gautier::SFMLApp;

const InputPropertiesWindow& WindowEventModel::GetInputPropertiesWindow()
{
	return _InputPropertiesWindow;
}

const InputPropertiesMouse& WindowEventModel::GetInputPropertiesMouse()
{
	return _InputPropertiesMouse;
}

const InputPropertiesKeyboard& WindowEventModel::GetInputPropertiesKeyboard()
{
	return _InputPropertiesKeyboard;
}

void WindowEventModel::InterpretInteractionEvent(const SFMLEvent& interactionEvent)
{
	_InputPropertiesWindow.InterpretInteractionEvent(interactionEvent);
	_InputPropertiesMouse.InterpretInteractionEvent(interactionEvent);
	_InputPropertiesKeyboard.InterpretInteractionEvent(interactionEvent);
}
