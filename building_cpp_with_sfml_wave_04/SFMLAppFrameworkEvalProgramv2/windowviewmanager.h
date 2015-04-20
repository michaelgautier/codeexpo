#ifndef WINDOWVIEWMANAGER_H
#define WINDOWVIEWMANAGER_H

#include <SFML/Graphics.hpp>

#include "windoweventmodel.h"
#include "programwindowviewname.h"
#include "programwindow.h"
#include "visualcommon.h"

#include "viewsstandardcontroller.h"

namespace Gautier
{
    namespace GautierProgram
    {
        using namespace std;
        using namespace Gautier::SFMLApp::InteractionDeviceFundamentals;
        using namespace Gautier::SFMLApp::MVCControllers;
        using namespace Gautier::SFMLApp::MVCModels;
        class WindowViewManager final
        {
            public:
                WindowViewManager();

                bool ProcessEvent(const WindowEventModel& eventModel, ProgramWindow& ProgramWindow);
            private:
                void ProcessVisuals(ProgramWindow& programWindow);
                CollectionVisual _SFMLGraphicDrawables;
                ViewsStandardController _ViewStandardController;
        };
    }
}
#endif // WINDOWVIEWMANAGER_H
