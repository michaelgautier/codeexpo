#ifndef WINDOWCOMMONIMPL_H
#define WINDOWCOMMONIMPL_H

#include "visualcommon.h"
#include "windoweventmodel.h"

namespace Gautier
{
	namespace SFMLApp
	{
		class WindowCommonImpl
		{
			public:
				SFMLVideoMode& CreateCoreInterationVisualMode(SFMLVideoMode& videoMode, AreaSize sizeValue);
				void ProcessEvent(WindowEventModel& eventModel, SFMLWindow& programWindow);
			private:
				AreaSize _DesktopModeSize;
				AreaSize _LastWindowSize;
				BitsPerPixel _DesktopBitsPerPixel;
				//Polygon _WindowArea;
		};
	}
}
#endif // WINDOWCOMMONIMPL_H
