#include <memory>

#include "windowviewmanager.h"
#include "visualcommon.h"
#include "programviewfirstview.h"

using namespace Gautier::SFMLApp::InteractionDeviceFundamentals;
using namespace Gautier::GautierProgram;

WindowViewManager::WindowViewManager()
{
    _SFMLGraphicDrawables.reserve(40);

    auto FirstView = new ProgramViewFirstView;

    _ViewStandardController.SetInitialView(FirstView);

    return;
}

bool WindowViewManager::ProcessEvent(const WindowEventModel& eventModel, ProgramWindow& programWindow)
{
    auto WindowDrawn = false;

    _ViewStandardController.ProcessActiveView(eventModel);

    auto ViewModel = _ViewStandardController.GetViewModel();

    auto Visuals = ViewModel.GetVisualModel();

    auto EventCollectionIsActive = programWindow.IsWindowOpen();

    if(EventCollectionIsActive)
    {
        if(!_SFMLGraphicDrawables.empty())
        {
            _SFMLGraphicDrawables.clear();
        }

        if(!Visuals.empty())
        {
            _SFMLGraphicDrawables.insert(_SFMLGraphicDrawables.end(), Visuals.begin(), Visuals.end());
        }

        ProcessVisuals(programWindow);
        WindowDrawn = true;
    }

    return WindowDrawn;
}

void WindowViewManager::ProcessVisuals(ProgramWindow& programWindow)
{
    if(!_SFMLGraphicDrawables.empty())
    {
        for(auto SFMLDrawableItem : _SFMLGraphicDrawables)
        {
            programWindow.Draw(*SFMLDrawableItem);
        }
    }
    else
    {
        programWindow.Draw();
    }

    return;
}
