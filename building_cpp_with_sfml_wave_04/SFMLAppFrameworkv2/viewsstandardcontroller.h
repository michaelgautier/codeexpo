#ifndef VIEWSSTANDARDCONTROLLER_H
#define VIEWSSTANDARDCONTROLLER_H

#include <memory>

#include "viewsstandardmodel.h"
#include "mvcviewbase.h"
#include "visualcommon.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace MVCControllers
        {
            using namespace Gautier::SFMLApp::MVCViews;
            using namespace Gautier::SFMLApp::VisualFundamentals;
            class ViewsStandardController final
            {
                public:
                    void SetInitialView(MVCViewBase* view);

                    /*The following implies a dependency between window event models
                    and the views. It is true. The window event system must be active,
                    in working order, and available if there is to be any view activity.*/
                    void ProcessActiveView(const WindowEventModel& eventModel);

                    ViewsStandardModel& GetViewModel();
                private:
                    ViewsStandardModel _ViewModel;
                    MVCViewBase* _ActiveView = nullptr;
            };
        }
    }
}
#endif // VIEWSSTANDARDCONTROLLER_H
