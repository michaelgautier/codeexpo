#ifndef PROGRAM_H
#define PROGRAM_H

#include "windoweventcontroller.h"

namespace Gautier
{
	namespace SFMLApp
	{
		class Program
		{
			public:
				void Execute();
			private:
				WindowEventController _WindowEventController;

				void Draw(SFMLWindow& programWindow);
		};
	}
}
#endif // PROGRAM_H
