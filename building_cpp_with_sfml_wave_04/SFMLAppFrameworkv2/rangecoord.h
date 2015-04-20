#ifndef RANGECOORD_H
#define RANGECOORD_H
namespace Gautier
{
    namespace SFMLApp
    {
        namespace DimensionalFundamentals
        {
            class RangeCoord final
            {
                public:
                    RangeCoord() = default;
                    RangeCoord(const RangeCoord&) = default;
                    RangeCoord(RangeCoord&&) = default;
                    RangeCoord& operator=(const RangeCoord&) = default;
                    RangeCoord& operator=(RangeCoord&&) = default;
                    ~RangeCoord() = default;

                    RangeCoord(const float x, const float y) :
                        _X {x}, _Y {y} {};

                    RangeCoord(const float x, const float y, const float z) :
                        _X {x}, _Y {y}, _Z {z} {};

                    const float GetX();
                    const float GetY();
                    const float GetZ();

                    void SetX(const float value);
                    void SetY(const float value);
                    void SetZ(const float value);
                private:
                    float _X {0};
                    float _Y {0};
                    float _Z {0};
            };
        }
    }
}
#endif // RANGECOORD_H
