#include "mvcviewbase.h"
#include "visualcommon.h"

using namespace Gautier::SFMLApp::MVCViews;
MVCViewBase& MVCViewBase::NextView()
{
    return *_ActiveView;
}

void MVCViewBase::Activate()
{
    return;
}

CollectionVisual MVCViewBase::GetVisuals()
{
    return _Visuals;
}

void MVCViewBase::ProcessEvent(const WindowEventModel& eventModel)
{
    return;
}
