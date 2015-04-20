#include "inputpropertieswindow.h"
using namespace Gautier::SFMLApp::InteractionDeviceFundamentals;

const bool InputPropertiesWindow::GetWindowResized() const
{
    return _WindowResized;
}

const bool InputPropertiesWindow::GetWindowIsValid() const
{
    return _WindowIsValid;
}

const bool InputPropertiesWindow::GetWindowWasClosed() const
{
    return _WindowWasClosed;
}

const AreaSize InputPropertiesWindow::GetWindowSize() const
{
    return _WindowSize;
}

const AreaSize InputPropertiesWindow::GetLastWindowSize() const
{
    return _LastWindowSize;
}

void InputPropertiesWindow::InterpretInteractionEvent(const SFMLEvent& interactionEvent)
{
    _WindowResized = (interactionEvent.type == SFMLEventType::Resized);
    _WindowWasClosed = (interactionEvent.type == SFMLEventType::Closed);

    if(_WindowResized)
    {
        _LastWindowSize = _WindowSize;
        _WindowSize = AreaSize(interactionEvent.size.width, interactionEvent.size.height);
    }
}
