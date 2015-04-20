#ifndef VIEWSSTANDARDMODEL_H
#define VIEWSSTANDARDMODEL_H
#include "visualcommon.h"

namespace Gautier
{
    namespace SFMLApp
    {
        namespace MVCModels
        {
            using namespace Gautier::SFMLApp::VisualFundamentals;

            class ViewsStandardModel final
            {
                public:
                    ViewsStandardModel();
                    CollectionVisual GetVisualModel();
                    void AddVisuals(CollectionVisual& visuals);
                private:
                    CollectionVisual _Visuals;
            };
        }
    }
}
#endif // VIEWSSTANDARDMODEL_H
