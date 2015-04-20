#ifndef COMPOSITEGRAPHIC_H
#define COMPOSITEGRAPHIC_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "visualcommon.h"

using namespace std;
namespace SFML = sf;

namespace Gautier
{
	namespace SFMLApp
	{
		class CompositeGraphic
		{
			public:

				const CollectionVisual GetGraphics();
				const bool GetGraphicIsValid();
				void SetGraphicIsValid(const bool isValid);
				void BuildGraphics(const CollectionVisual graphics);
			private:
				bool _GraphicIsValid;
				CollectionVisual _Graphics;
		};

		using CollectionComposedVisual = vector<CompositeGraphic>;
	}
}
#endif // COMPOSITEGRAPHIC_H
