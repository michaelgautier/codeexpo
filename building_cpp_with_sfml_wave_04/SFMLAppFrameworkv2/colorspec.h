#ifndef COLORSPEC_H
#define COLORSPEC_H

#include "visualcommon.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace VisualFundamentals
        {
            class ColorSpec
            {
                public:
                    /*Red   Green   Blue    Alpha*/
                    ColorSpec(int red, int green, int blue, int alpha)
                        : _ColorValueRed {red}, _ColorValueGreen {green}, _ColorValueBlue {blue}, _ColorValueAlpha {alpha} {};

                    ColorSpec(const SFMLColor& colorValue)
                        : ColorSpec(colorValue.r, colorValue.g, colorValue.b, colorValue.a) {};

                    void ChangeSFMLColor(SFMLColor& colorValue);
                private:
                    /*Red   Green   Blue    Alpha*/
                    int _ColorValueRed {0};
                    int _ColorValueGreen {0};
                    int _ColorValueBlue {0};
                    int _ColorValueAlpha {0};
            };
        }
    }
}
#endif // COLORSPEC_H
