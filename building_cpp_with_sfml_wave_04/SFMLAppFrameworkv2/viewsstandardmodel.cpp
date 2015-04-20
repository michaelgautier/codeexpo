#include "viewsstandardmodel.h"
#include "visualcommon.h"
using namespace Gautier::SFMLApp::MVCModels;

ViewsStandardModel::ViewsStandardModel()
{
    _Visuals.reserve(20);

    return;
}

CollectionVisual ViewsStandardModel::GetVisualModel()
{
    return _Visuals;
}

void ViewsStandardModel::AddVisuals(CollectionVisual& visuals)
{
    if(!_Visuals.empty())
    {
        _Visuals.clear();
    }

    for(SFMLGraphicBase* VisualItem : visuals)
    {
        _Visuals.push_back(VisualItem);
    }

    return;
}
