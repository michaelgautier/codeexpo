#ifndef INPUTPROPERTIESKEYBOARD_H
#define INPUTPROPERTIESKEYBOARD_H
#include <string>

#include "visualcommon.h"

using namespace std;

namespace Gautier
{
	namespace SFMLApp
	{
		class InputPropertiesKeyboard
		{
			public:
				const KeyboardKey GetLastKeyboardKeyPressed();
				const SFMLEventType GetLastKeyboardEvent();

				const KeyboardKey GetKeyboardKeyPressed();
				const SFMLEventType GetKeyboardEvent();

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
#endif // INPUTPROPERTIESKEYBOARD_H
