#ifndef WINDOWEVENTCONTROLLER_H
#define WINDOWEVENTCONTROLLER_H

#include "windoweventmodel.h"

namespace Gautier
{
	namespace SFMLApp
	{
		class WindowEventController
		{
			public:
				void CollectNextEvent(SFMLWindow& programWindow);
				const bool GetEventCollectionIsActive();
				const WindowEventModel& GetEventModel();
			private:
				bool _EventCollectionIsActive;
				WindowEventModel _EventModel;
		};
	}
}
#endif // WINDOWEVENTCONTROLLER_H
