#ifndef RANGEAREASIZEXYWH_H
#define RANGEAREASIZEXYWH_H
#include "rangecoord.h"
#include "rangesizewh.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace DimensionalFundamentals
        {
            class RangeAreaSizeXYWH final
            {
                public:
                    RangeAreaSizeXYWH() = default;
                    RangeAreaSizeXYWH(const RangeAreaSizeXYWH&) = default;
                    RangeAreaSizeXYWH(RangeAreaSizeXYWH&&) = default;
                    RangeAreaSizeXYWH& operator=(const RangeAreaSizeXYWH&) = default;
                    RangeAreaSizeXYWH& operator=(RangeAreaSizeXYWH&&) = default;
                    ~RangeAreaSizeXYWH() = default;

                    RangeAreaSizeXYWH(const float x, const float y) :
                        _Coord {x, y} {};

                    RangeAreaSizeXYWH(const float x, const float y, const float width, const float height) :
                        _Coord {x, y}, _Size {width, height} {};

                    RangeAreaSizeXYWH(const RangeCoord coord) :
                        _Coord {coord} {};

                    RangeAreaSizeXYWH(const RangeSizeWH sizeWH) :
                        _Size {sizeWH} {};

                    RangeAreaSizeXYWH(const RangeCoord coord, const RangeSizeWH sizeWH) :
                        _Coord {coord}, _Size {sizeWH} {};

                    const float GetWidth();
                    const float GetHeight();
                    const float GetX();
                    const float GetY();
                    const float GetZ();
                    RangeCoord CreateCoord();
                    RangeSizeWH CreateSize();

                    void SetWidth(const float value);
                    void SetHeight(const float value);
                    void SetX(const float value);
                    void SetY(const float value);
                    void SetZ(const float value);
                    void SetCoord(const RangeCoord value);
                    void SetSize(const RangeSizeWH value);
                private:
                    RangeCoord _Coord;
                    RangeSizeWH _Size;
            };
        }
    }
}
#endif // RANGEAREASIZEXYWH_H
