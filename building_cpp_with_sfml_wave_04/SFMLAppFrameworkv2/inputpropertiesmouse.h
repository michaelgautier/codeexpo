#ifndef INPUTPROPERTIESMOUSE_H
#define INPUTPROPERTIESMOUSE_H

#include "visualcommon.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace InteractionDeviceFundamentals
        {
            using namespace Gautier::SFMLApp::VisualFundamentals;
            class InputPropertiesMouse final
            {
                public:
                    const Point GetLastMouseCoordinates() const;
                    const MouseButton GetLastMouseButtonPressed() const;
                    const SFMLEventType GetLastMouseEvent() const;

                    const Point GetMouseCoordinates() const;
                    const MouseButton GetMouseButtonPressed() const;
                    const SFMLEventType GetMouseEvent() const;

                    const bool GetMouseClicked() const;

                    void InterpretInteractionEvent(const SFMLEvent& interactionEvent);
                private:
                    Point _LastMouseCoordinates;
                    MouseButton _LastMouseButtonPressed;
                    SFMLEventType _LastMouseEvent;

                    Point _MouseCoordinates;
                    MouseButton _MouseButtonPressed;
                    SFMLEventType _MouseEvent;

                    bool _MouseClicked;
            };
        }
    }
}
#endif // INPUTPROPERTIESMOUSE_H
