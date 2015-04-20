#include "windoweventcontroller.h"
using namespace Gautier::SFMLApp::MVCControllers;

bool WindowEventController::CollectNextEvent(SFMLWindow& programWindow)
{
    _EventCollectionIsActive = programWindow.isOpen();

    if(_EventCollectionIsActive)
    {
        SFMLEvent InteractionEvent;

        auto EventPollSuccessful = programWindow.pollEvent(InteractionEvent);

        if(EventPollSuccessful)
        {
            _EventCollectionIsActive = (programWindow.isOpen()) && (InteractionEvent.type != SFMLEvent::Closed);

            if(_EventCollectionIsActive)
            {
                _EventModel.InterpretInteractionEvent(InteractionEvent);
            }
        }
    }

    return GetEventCollectionIsActive();
}

const bool WindowEventController::GetEventCollectionIsActive()
{
    return _EventCollectionIsActive;
}

const WindowEventModel& WindowEventController::GetEventModel()
{
    return _EventModel;
}
