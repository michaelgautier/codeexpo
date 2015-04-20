#ifndef WINDOWVIEWSCREEN1_H
#define WINDOWVIEWSCREEN1_H

#include "windoweventmodel.h"
#include "windowviewcommonimpl.h"

namespace Gautier
{
	namespace SFMLApp
	{
		class WindowViewScreen1
		{
			public:
				WindowViewScreen1() = default;
				void AccumulateCompositeGraphics();
				void ProcessEvent(WindowEventModel& eventModel);
				void DrawView(SFMLWindow& programWindow);
			private:
				CollectionComposedVisual& _GraphicsToRender;
				WindowViewCommonImpl _WindowViewCommonImpl;
		};
	}
}
#endif // WINDOWVIEWSCREEN1_H
