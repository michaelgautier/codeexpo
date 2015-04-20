#ifndef MVCVIEWBASE_H
#define MVCVIEWBASE_H

#include <memory>

#include "visualcommon.h"
#include "windoweventmodel.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace MVCViews
        {
            using namespace Gautier::SFMLApp::MVCModels;
            class MVCViewBase
            {
                public:
                    virtual MVCViewBase& NextView();
                    virtual void Activate();
                    virtual CollectionVisual GetVisuals();
                    virtual void ProcessEvent(const WindowEventModel& eventModel);
                private:
                    shared_ptr<MVCViewBase> _ActiveView = nullptr;
                    CollectionVisual _Visuals;
            };
        }
    }
}
#endif // MVCVIEWBASE_H
