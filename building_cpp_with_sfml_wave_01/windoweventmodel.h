#ifndef WINDOWEVENTMODEL_H
#define WINDOWEVENTMODEL_H
#include <SFML/Window.hpp>

#include "inputpropertieskeyboard.h"
#include "inputpropertiesmouse.h"
#include "inputpropertieswindow.h"

using namespace sf;

namespace Gautier
{
	namespace SFMLApp
	{
		class WindowEventModel
		{
			public:
				const InputPropertiesWindow& GetInputPropertiesWindow();
				const InputPropertiesMouse& GetInputPropertiesMouse();
				const InputPropertiesKeyboard& GetInputPropertiesKeyboard();

				void InterpretInteractionEvent(const SFMLEvent& interactionEvent);
			private:
				InputPropertiesMouse _InputPropertiesMouse;
				InputPropertiesKeyboard _InputPropertiesKeyboard;
				InputPropertiesWindow _InputPropertiesWindow;
		};
	}
}
#endif // WINDOWEVENTMODEL_H
