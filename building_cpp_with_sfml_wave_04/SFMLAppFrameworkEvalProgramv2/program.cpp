#include <SFML/Graphics.hpp>

#include "program.h"
#include "visualcommon.h"
#include "windowviewmanager.h"
#include "programwindow.h"
#include "visualsettings.h"
#include "visualwindow.h"

using namespace Gautier::SFMLApp;
using namespace Gautier::GautierProgram;
using namespace Gautier::SFMLApp::VisualFundamentals;

VisualSettings Program::_VisualSettings;

void Program::Execute()
{
    ConfigureVisualTheme();

    auto VisualWindowHandle = _ProgramWindow.GetVisualWindow();

    ProcessEvents(*VisualWindowHandle.RenderTarget);

    return;
}

void Program::ProcessEvents(SFMLWindow& programWindow)
{
    auto EventCollectionIsActive = true;

    while(EventCollectionIsActive)
    {
        EventCollectionIsActive = _WindowEventController.CollectNextEvent(programWindow);

        if(EventCollectionIsActive)
        {
            auto EventModel = _WindowEventController.GetEventModel();

            ProcessView(EventModel);
        }
        else
        {
            break;
        }
    }

    return;
}

VisualSettings& Program::GetVisualSettings()
{
    return _VisualSettings;
}

void Program::ProcessView(const WindowEventModel& eventModel)
{
    _ProgramWindow.ProcessEvent(eventModel);

    auto WindowDrawn = _WindowViewManager.ProcessEvent(eventModel, _ProgramWindow);

    if(!WindowDrawn)
    {
        _ProgramWindow.Draw();
    }

    return;
}

void Program::ConfigureVisualTheme()
{
    _VisualSettings.SetBackgroundColor(74, 135, 183, 255);
    _VisualSettings.SetBackgroundSize(800, 600);

    {
        string WindowTitleText = "Gautier's Window";

        _VisualSettings.SetTitleText(WindowTitleText);
    }

    _ProgramWindow.SetVisualSettings(_VisualSettings);

    return;
}
