#ifndef WINDOWEVENTMODEL_H
#define WINDOWEVENTMODEL_H
#include <SFML/Window.hpp>

#include "inputpropertieskeyboard.h"
#include "inputpropertiesmouse.h"
#include "inputpropertieswindow.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace MVCModels
        {
            using namespace sf;
            using namespace Gautier::SFMLApp::InteractionDeviceFundamentals;
            class WindowEventModel final
            {
                public:
                    const InputPropertiesWindow& GetInputPropertiesWindow() const;
                    const InputPropertiesMouse& GetInputPropertiesMouse() const;
                    const InputPropertiesKeyboard& GetInputPropertiesKeyboard() const;

                    void InterpretInteractionEvent(const SFMLEvent& interactionEvent);
                private:
                    InputPropertiesMouse _InputPropertiesMouse;
                    InputPropertiesKeyboard _InputPropertiesKeyboard;
                    InputPropertiesWindow _InputPropertiesWindow;
            };
        }
    }
}
#endif // WINDOWEVENTMODEL_H
