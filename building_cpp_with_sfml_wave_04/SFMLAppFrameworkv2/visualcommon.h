#ifndef VISUALCOMMON_H
#define VISUALCOMMON_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "rangeareasizexywh.h"
#include "rangecoord.h"
#include "rangesizewh.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace VisualFundamentals
        {
            using namespace std;
            namespace SFML = sf;

            using SFMLGraphicBase = SFML::Drawable;
            using SFMLShape = SFML::Shape;
            using SFMLSprite = SFML::Sprite;
            using SFMLText = SFML::Text;

            using SFMLColor = SFML::Color;

            using SFMLRectangleShape = SFML::RectangleShape;

            using BitsPerPixel = unsigned int;

            using CollectionVisual= vector<SFMLGraphicBase*>;
            /*
                Instead of using SFML measurement types directly,
                we will use domain types that are more descriptive.
            */
            using namespace Gautier::SFMLApp::DimensionalFundamentals;

            using Point = RangeCoord;
            using Position = RangeCoord;/*coordinateXY*/
            using AreaSize = RangeSizeWH;/*Size*/
            using Polygon = RangeAreaSizeXYWH;/*Polygon*/

            /*
                SFML quantity values aliased.
                This is used for mapping from our general aliases to SFML aliases when
                assigning our general values to SFML functions or
                returning SFML values from SFML functions mapping them to general values.
            */
            using SFMLVector2Float = SFML::Vector2f;
            using SFMLVector2Int = SFML::Vector2i;
            using SFMLVector2UInt = SFML::Vector2u;

            using SFMLRectFloat = SFML::FloatRect;
            using SFMLRectInt = SFML::IntRect;

            /*
                We are using SFML hardware device and event data directly.
            */
            using MouseButton = SFML::Mouse::Button;
            using KeyboardKey = SFML::Keyboard::Key;

            using SFMLEvent = SFML::Event;
            using SFMLEventType = SFMLEvent::EventType;
            using SFMLWindow = SFML::RenderWindow;
            using SFMLVideoMode = SFML::VideoMode;
            using SFMLView = SFML::View;

            class VisualCommon final
            {
                public:
                    /*
                        SFML Converters
                    */
                    static Polygon& CopyPolygonValue(const SFMLRectFloat value, Polygon& target);
                    static Polygon& CopyPolygonValue(const SFMLRectInt value, Polygon& target);

                    static Position CreatePosition(const SFMLVector2Float value);
                    static Position CreatePosition(const SFMLVector2Int value);
                    static Position CreatePosition(const SFMLVector2UInt value);

                    static Position& CopyPositionValue(const SFMLVector2Float value, Position& target);
                    static Position& CopyPositionValue(const SFMLVector2Int value, Position& target);
                    static Position& CopyPositionValue(const SFMLVector2UInt value, Position& target);

                    static SFMLVector2Float CreateSFMLVectorFloat(Position& logicalPosition);
                    static SFMLVector2Int CreateSFMLVectorInt(Position& logicalPosition);
                    static SFMLVector2UInt CreateSFMLVectorUInt(Position& logicalPosition);

                    static SFMLRectFloat CreateSFMLRectFloat(Polygon& logicalPolygon);
                    static SFMLRectInt CreateSFMLRectInt(Polygon& logicalPolygon);
            };
        }
    }
}
#endif // VISUALCOMMON_H
