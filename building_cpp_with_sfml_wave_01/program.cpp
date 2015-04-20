#include "program.h"
#include "visualcommon.h"
#include "windowcommonimpl.h"

using namespace Gautier::SFMLApp;

void Program::Execute()
{
	WindowCommonImpl WindowTools;

	SFMLVideoMode ProgramWindowVideoMode;

	const AreaSize WindowAreaSize(800, 600);

	ProgramWindowVideoMode = WindowTools.CreateCoreInterationVisualMode(ProgramWindowVideoMode, WindowAreaSize);

	SFMLWindow ProgramWindow(ProgramWindowVideoMode, "Program Window");

	_WindowEventController.CollectNextEvent(ProgramWindow);

	bool EventCollectionIsActive = _WindowEventController.GetEventCollectionIsActive();

	while(EventCollectionIsActive)
	{
		_WindowEventController.CollectNextEvent(ProgramWindow);

		WindowEventModel EventModel = _WindowEventController.GetEventModel();

		WindowTools.ProcessEvent(EventModel, ProgramWindow);

		EventCollectionIsActive = _WindowEventController.GetEventCollectionIsActive();

		if(EventCollectionIsActive)
		{
			Draw(ProgramWindow);
		}
		else
		{
			break;
		}
	}
}

void Program::Draw(SFMLWindow& programWindow)
{
	programWindow.clear();
	//programWindow.draw();
	programWindow.display();
}
