#ifndef WINDOWVIEWCOMMONIMPL_H
#define WINDOWVIEWCOMMONIMPL_H
#include <SFML/Graphics.hpp>

#include "compositegraphic.h"
#include "windoweventmodel.h"

using namespace sf;

namespace Gautier
{
	namespace SFMLApp
	{
		class WindowViewCommonImpl
		{
			public:
				void ProcessEvent(const WindowEventModel& eventModel);
				void DrawView(const SFMLWindow& programWindow, const CollectionComposedVisual& graphicItems);
			private:
		};
	}
}
#endif // WINDOWVIEWCOMMONIMPL_H
