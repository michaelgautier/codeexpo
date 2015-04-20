#ifndef INPUTPROPERTIESWINDOW_H
#define INPUTPROPERTIESWINDOW_H
#include <SFML/Window.hpp>

#include "visualcommon.h"

using namespace sf;

namespace Gautier
{
	namespace SFMLApp
	{
		class InputPropertiesWindow
		{
			public:
				const bool GetWindowResized();
				const bool GetWindowIsValid();
				const bool GetWindowWasClosed();
				const AreaSize GetWindowSize();
				void InterpretInteractionEvent(const SFMLEvent& interactionEvent);
			private:
				bool _WindowResized;
				bool _WindowIsValid;
				bool _WindowWasClosed;
				AreaSize _WindowSize;
		};
	}
}
#endif // INPUTPROPERTIESWINDOW_H
