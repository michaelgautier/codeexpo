#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>

#include <SFML/Graphics.hpp>

#include "visualcommon.h"
#include "windoweventcontroller.h"
#include "programwindow.h"
#include "visualsettings.h"

/*Window Views*/
#include "windowviewmanager.h"

namespace Gautier
{
    namespace GautierProgram
    {
        using namespace Gautier::SFMLApp::MVCControllers;

        class Program final
        {
            public:
                void Execute();
                static VisualSettings& GetVisualSettings();
            private:
                WindowEventController _WindowEventController;

                ProgramWindow _ProgramWindow;
                WindowViewManager _WindowViewManager;
                static VisualSettings _VisualSettings;

                void ProcessEvents(SFMLWindow& programWindow);
                void ProcessView(const WindowEventModel& eventModel);
                void ConfigureVisualTheme();
        };
    }
}
#endif // PROGRAM_H
