#ifndef WINDOWEVENTCONTROLLER_H
#define WINDOWEVENTCONTROLLER_H

#include "windoweventmodel.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace MVCControllers
        {
            using namespace Gautier::SFMLApp::InteractionDeviceFundamentals;
            using namespace Gautier::SFMLApp::MVCModels;
            class WindowEventController final
            {
                public:
                    bool CollectNextEvent(SFMLWindow& programWindow);

                    /*Designed solely for multi-threaded and separate querying of status*/
                    const bool GetEventCollectionIsActive();
                    const WindowEventModel& GetEventModel();
                private:
                    bool _EventCollectionIsActive;
                    WindowEventModel _EventModel;
            };
        }
    }
}
#endif // WINDOWEVENTCONTROLLER_H
