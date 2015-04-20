#ifndef PROGRAMWINDOW_H
#define PROGRAMWINDOW_H

#include <SFML/Graphics.hpp>

#include "visualcommon.h"
#include "windoweventmodel.h"
#include "visualsettings.h"
#include "visualwindow.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace VisualFundamentals
        {
            using namespace Gautier::SFMLApp::VisualFundamentals;
            using namespace Gautier::SFMLApp::MVCModels;
            /*This is essentially a resource handle for the SFML Window in order to decouple
            the details, and SFML types from the the main program.*/
            class ProgramWindow final
            {
                public:
                    ProgramWindow();
                    VisualWindow& GetVisualWindow();
                    void ProcessEvent(const WindowEventModel& eventModel);
                    void Draw();
                    void Draw(SFMLGraphicBase& drawable);
                    bool IsWindowOpen();
                    VisualSettings& GetVisualSettings();
                    void SetVisualSettings(VisualSettings visualSettings);
                private:
                    AreaSize _DesktopModeSize;
                    BitsPerPixel _DesktopBitsPerPixel;

                    VisualSettings _VisualSettings;

                    VisualWindow WindowImplementation;

                    bool _InitCalled {false};
                    bool _SFMLProgramWindowCreateCalled {false};

                    void Init();
                    void CreateSFMLProgramWindow();
                    void DefaultWindowClear();
            };
        }
    }
}
#endif // PROGRAMWINDOW_H
