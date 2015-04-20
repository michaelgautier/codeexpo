#include "visualsettings.h"
#include "visualcommon.h"
#include "colorspec.h"

using namespace Gautier::SFMLApp::VisualFundamentals;

VisualSettings::VisualSettings()
{
    _BackgroundColor = new ColorSpec(SFMLColor::Black);
    _BackgroundSize = new AreaSize(0,0);
    _TitleText = "MG";

    return;
}

const ColorSpec& VisualSettings::GetBackgroundColor()
{
    return *_BackgroundColor;
}

void VisualSettings::SetBackgroundColor(int r, int g, int b, int a)
{
    if(_BackgroundColor)
    {
        delete _BackgroundColor;
    }

    _BackgroundColor = new ColorSpec(r,g,b,a);

    return;
}

AreaSize& VisualSettings::GetBackgroundSize()
{
    return *_BackgroundSize;
}

void VisualSettings::SetBackgroundSize(float width, float height)
{
    if(_BackgroundSize)
    {
        delete _BackgroundSize;
    }

    _BackgroundSize = new AreaSize(width, height);

    return;
}

const string& VisualSettings::GetTitleText()
{
    return _TitleText;
}

void VisualSettings::SetTitleText(string& value)
{
    _TitleText = value;

    return;
}
