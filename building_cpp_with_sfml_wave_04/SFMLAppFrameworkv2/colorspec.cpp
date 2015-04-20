#include "colorspec.h"
#include "visualcommon.h"

using namespace Gautier::SFMLApp::VisualFundamentals;

void ColorSpec::ChangeSFMLColor(SFMLColor& colorValue)
{
    colorValue.r = _ColorValueRed;
    colorValue.g = _ColorValueGreen;
    colorValue.b = _ColorValueBlue;
    colorValue.a = _ColorValueAlpha;

    return;
}
