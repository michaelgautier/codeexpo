#ifndef INPUTPROPERTIESMOUSE_H
#define INPUTPROPERTIESMOUSE_H

#include "visualcommon.h"

namespace Gautier
{
	namespace SFMLApp
	{
		class InputPropertiesMouse
		{
			public:
				const Point GetLastMouseCoordinates();
				const MouseButton GetLastMouseButtonPressed();
				const SFMLEventType GetLastMouseEvent();

				const Point GetMouseCoordinates();
				const MouseButton GetMouseButtonPressed();
				const SFMLEventType GetMouseEvent();

				const bool GetMouseClicked();

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
#endif // INPUTPROPERTIESMOUSE_H
