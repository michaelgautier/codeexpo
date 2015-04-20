#include "inputpropertieswindow.h"
using namespace Gautier::SFMLApp;

const bool InputPropertiesWindow::GetWindowResized()
{
	return _WindowResized;
}

const bool InputPropertiesWindow::GetWindowIsValid()
{
	return _WindowIsValid;
}

const bool InputPropertiesWindow::GetWindowWasClosed()
{
	return _WindowWasClosed;
}

const AreaSize InputPropertiesWindow::GetWindowSize()
{
	return _WindowSize;
}

void InputPropertiesWindow::InterpretInteractionEvent(const SFMLEvent& interactionEvent)
{
	_WindowResized = (interactionEvent.type == SFMLEventType::Resized);
	_WindowWasClosed = (interactionEvent.type == SFMLEventType::Closed);

	if(_WindowResized)
	{
		_WindowSize = AreaSize(interactionEvent.size.width, interactionEvent.size.height);
	}
}
