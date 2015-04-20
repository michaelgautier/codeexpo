#include "windowviewscreen1.h"
using namespace Gautier::SFMLApp;
void WindowViewScreen1::AccumulateCompositeGraphics()
{

}

void WindowViewScreen1::ProcessEvent(WindowEventModel& eventModel)
{
	_WindowViewCommonImpl.ProcessEvent(eventModel);
}

void WindowViewScreen1::DrawView(SFMLWindow& programWindow)
{
	_WindowViewCommonImpl.DrawView(programWindow, _GraphicsToRender);
}
