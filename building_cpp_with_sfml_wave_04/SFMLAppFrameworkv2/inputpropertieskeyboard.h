#ifndef INPUTPROPERTIESKEYBOARD_H
#define INPUTPROPERTIESKEYBOARD_H
#include <string>

#include "visualcommon.h"

using namespace std;

namespace Gautier
{
    namespace SFMLApp
    {
        namespace InteractionDeviceFundamentals
        {
            using namespace Gautier::SFMLApp::VisualFundamentals;
            class InputPropertiesKeyboard final
            {
                public:
                    const KeyboardKey GetLastKeyboardKeyPressed() const;
                    const SFMLEventType GetLastKeyboardEvent() const;

                    const KeyboardKey GetKeyboardKeyPressed() const;
                    const SFMLEventType GetKeyboardEvent() const;

                    void InterpretInteractionEvent(const SFMLEvent& interactionEvent);
                private:
                    KeyboardKey _LastKeyboardKeyPressed;
                    SFMLEventType _LastKeyboardEvent;

                    KeyboardKey _KeyboardKeyPressed;
                    SFMLEventType _KeyboardEvent;

                    string _TextBuffer;
            };
        }
    }
}
#endif // INPUTPROPERTIESKEYBOARD_H
