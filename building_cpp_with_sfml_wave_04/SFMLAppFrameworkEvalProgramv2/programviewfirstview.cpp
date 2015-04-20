#include "programviewfirstview.h"
#include "mvcviewbase.h"

using namespace Gautier::GautierProgram;
using namespace Gautier::SFMLApp::MVCViews;

MVCViewBase& ProgramViewFirstView::NextView()
{
    return *_ActiveView;
}

void ProgramViewFirstView::Activate()
{
    /*
        Logic specific to this view.
    */
    return;
}

CollectionVisual ProgramViewFirstView::GetVisuals()
{
    return _Visuals;
}

void ProgramViewFirstView::ProcessEvent(const WindowEventModel& eventModel)
{
    _Visuals.clear();

    auto BackgroundShape = new SFMLRectangleShape;
    BackgroundShape->setSize(SFMLVector2Float(200,200));
    BackgroundShape->setFillColor(SFMLColor::Magenta);

    _Visuals.push_back(BackgroundShape);

    return;
}
