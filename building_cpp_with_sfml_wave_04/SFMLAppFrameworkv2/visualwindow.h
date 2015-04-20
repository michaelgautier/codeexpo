#ifndef VISUALWINDOW_H
#define VISUALWINDOW_H

#include <memory>
#include <SFML/Graphics.hpp>

#include "visualcommon.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace VisualFundamentals
        {
            class VisualWindow final
            {
                public:
                    shared_ptr<SFMLWindow> RenderTarget = nullptr;
            };
        }
    }
}
#endif // VISUALWINDOW_H
