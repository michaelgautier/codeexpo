#ifndef COMPONENTKEYBOARD_H
#define COMPONENTKEYBOARD_H
#include <vector>

#include "compositegraphic.h"
#include "windoweventmodel.h"

using namespace std;
using namespace sf;

namespace Gautier
{
	namespace SFMLApp
	{
		class ComponentKeyboard
		{
			public:

				void ProcessEvent(WindowEventModel eventModel);
				const CollectionComposedVisual& GetGraphics();
			private:
				bool _CursorIsActive;
				CollectionComposedVisual _CompositeGraphics;
		};
	}
}
#endif // COMPONENTKEYBOARD_H

