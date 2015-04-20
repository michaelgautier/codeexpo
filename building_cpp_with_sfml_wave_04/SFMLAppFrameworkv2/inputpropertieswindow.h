#ifndef INPUTPROPERTIESWINDOW_H
#define INPUTPROPERTIESWINDOW_H
#include <SFML/Window.hpp>

#include "visualcommon.h"

using namespace sf;

namespace Gautier
{
    namespace SFMLApp
    {
        namespace InteractionDeviceFundamentals
        {
            using namespace Gautier::SFMLApp::VisualFundamentals;
            class InputPropertiesWindow final
            {
                public:
                    const bool GetWindowResized() const;
                    const bool GetWindowIsValid() const;
                    const bool GetWindowWasClosed() const;
                    const AreaSize GetWindowSize() const;
                    const AreaSize GetLastWindowSize() const;
                    void InterpretInteractionEvent(const SFMLEvent& interactionEvent);
                private:
                    bool _WindowResized;
                    bool _WindowIsValid;
                    bool _WindowWasClosed;
                    AreaSize _WindowSize;
                    AreaSize _LastWindowSize;
            };
        }
    }
}
#endif // INPUTPROPERTIESWINDOW_H
