#include "windoweventcontroller.h"
using namespace Gautier::SFMLApp;

void WindowEventController::CollectNextEvent(SFMLWindow& programWindow)
{
	_EventCollectionIsActive = programWindow.isOpen();

	if(_EventCollectionIsActive)
	{
		SFMLEvent InteractionEvent;

		bool EventPollSuccessful = programWindow.pollEvent(InteractionEvent);

		if(EventPollSuccessful)
		{
			_EventCollectionIsActive = (InteractionEvent.type != SFMLEvent::Closed);

			if(_EventCollectionIsActive)
			{
				_EventModel.InterpretInteractionEvent(InteractionEvent);
			}
		}
	}
}

const bool WindowEventController::GetEventCollectionIsActive()
{
	return _EventCollectionIsActive;
}

const WindowEventModel& WindowEventController::GetEventModel()
{
	return _EventModel;
}
