#include "viewsstandardcontroller.h"
#include <memory>

using namespace Gautier::SFMLApp::MVCControllers;

void ViewsStandardController::SetInitialView(MVCViewBase* view)
{
    _ActiveView = view;

    return;
}

void ViewsStandardController::ProcessActiveView(const WindowEventModel& eventModel)
{
    if(_ActiveView)
    {
        _ActiveView->Activate();/*Logic for the view should be contained within here.*/
        _ActiveView->ProcessEvent(eventModel);
        /*
            At this point we can do other things such as get the next view and set it.
        */


        /*
            Need to set the Model for the view.
        */
        auto VisualItems = _ActiveView->GetVisuals();

        _ViewModel.AddVisuals(VisualItems);
    }

    return;
}

ViewsStandardModel& ViewsStandardController::GetViewModel()
{
    return _ViewModel;
}
