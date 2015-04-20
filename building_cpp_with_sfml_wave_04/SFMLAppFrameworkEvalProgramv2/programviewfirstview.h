#ifndef PROGRAMVIEWFIRSTVIEW_H
#define PROGRAMVIEWFIRSTVIEW_H

#include <memory>

#include "mvcviewbase.h"
#include "windoweventmodel.h"

namespace Gautier
{
    namespace GautierProgram
    {
        using namespace Gautier::SFMLApp::InteractionDeviceFundamentals;
        using namespace Gautier::SFMLApp::MVCModels;
        class ProgramViewFirstView final
            : public Gautier::SFMLApp::MVCViews::MVCViewBase/*Fully qualified to ensure no ambiguity.*/
        {
            public:
                MVCViewBase& NextView() override;

                void Activate() override;

                CollectionVisual GetVisuals() override;

                void ProcessEvent(const WindowEventModel& eventModel) override;
            private:
                MVCViewBase* _ActiveView = nullptr;
                CollectionVisual _Visuals;
        };
    }
}
#endif // PROGRAMVIEWFIRSTVIEW_H
