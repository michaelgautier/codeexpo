#ifndef RANGESIZEWH_H
#define RANGESIZEWH_H
namespace Gautier
{
    namespace SFMLApp
    {
        namespace DimensionalFundamentals
        {
            class RangeSizeWH final
            {
                public:
                    RangeSizeWH() = default;
                    RangeSizeWH(const RangeSizeWH&) = default;
                    RangeSizeWH(RangeSizeWH&&) = default;
                    RangeSizeWH& operator=(const RangeSizeWH&) = default;
                    RangeSizeWH& operator=(RangeSizeWH&&) = default;
                    ~RangeSizeWH() = default;

                    RangeSizeWH(const float width, const float height):_Width {width}, _Height {height} {};

                    const float GetWidth();
                    const float GetHeight();

                    void SetWidth(const float value);
                    void SetHeight(const float value);
                private:
                    float _Width;
                    float _Height;
            };
        }
    }
}
#endif // RANGESIZEWH_H
