#ifndef VISUALSETTINGS_H
#define VISUALSETTINGS_H

#include "visualcommon.h"
#include "colorspec.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace VisualFundamentals
        {
            using namespace Gautier::SFMLApp::VisualFundamentals;
            class VisualSettings
            {
                public:
                    VisualSettings();
                    const ColorSpec& GetBackgroundColor();
                    void SetBackgroundColor(int r, int g, int b, int a);
                    AreaSize& GetBackgroundSize();
                    void SetBackgroundSize(float width, float height);
                    const string& GetTitleText();
                    void SetTitleText(string& value);
                private:
                    ColorSpec* _BackgroundColor = nullptr;
                    AreaSize* _BackgroundSize = nullptr;
                    string _TitleText;
            };
        }
    }
}
#endif // VISUALSETTINGS_H
