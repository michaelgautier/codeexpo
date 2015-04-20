#include "visualcommon.h"
#include "windowcommonimpl.h"

using namespace Gautier::SFMLApp;

SFMLVideoMode& WindowCommonImpl::CreateCoreInterationVisualMode(SFMLVideoMode& videoMode, AreaSize sizeValue)
{
	_LastWindowSize = sizeValue;
	SFMLVideoMode DesktopVisualMode = SFMLVideoMode::getDesktopMode();
	_DesktopModeSize = AreaSize(DesktopVisualMode.width, DesktopVisualMode.height);
	_DesktopBitsPerPixel = DesktopVisualMode.bitsPerPixel;

	float Width = sizeValue.GetWidth();
	float Height = sizeValue.GetHeight();

	videoMode = SFMLVideoMode(Width, Height, _DesktopBitsPerPixel);

	return videoMode;
}

void WindowCommonImpl::ProcessEvent(WindowEventModel& eventModel, SFMLWindow& programWindow)
{
	InputPropertiesWindow WindowEventProperties = eventModel.GetInputPropertiesWindow();

	bool WindowWasResized = WindowEventProperties.GetWindowResized();

	if(WindowWasResized)
	{
		AreaSize WindowSize = WindowEventProperties.GetWindowSize();

		Polygon VisibleArea (0, 0, WindowSize.GetWidth(), WindowSize.GetHeight());

		SFMLRectFloat ViewableArea = VisualCommon::CreateSFMLRectFloat(VisibleArea);

		programWindow.setView(SFMLView(ViewableArea));
	}
}
