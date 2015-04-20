#include "programwindow.h"
#include "visualsettings.h"
#include "visualcommon.h"
#include "colorspec.h"

using namespace Gautier::SFMLApp::VisualFundamentals;

VisualSettings& ProgramWindow::GetVisualSettings()
{
    return _VisualSettings;
}

ProgramWindow::ProgramWindow()
{
    Init();

    return;
};

void ProgramWindow::SetVisualSettings(VisualSettings visualSettings)
{
    _VisualSettings = visualSettings;

//    AreaSize WindowAreaSize = _VisualSettings->GetBackgroundSize();
//    const string* WindowTitleText = _VisualSettings->GetTitleText();
//
//    const SFMLVector2UInt WindowSize(WindowAreaSize.GetWidth(), WindowAreaSize.GetHeight());

//    WindowImplementation.RenderTarget->setTitle(*WindowTitleText);
//    WindowImplementation.RenderTarget->setSize(WindowSize);

//    WindowImplementation.RenderTarget->setTitle("test");
//    WindowImplementation.RenderTarget->setSize(SFMLVector2UInt(100, 200));
    CreateSFMLProgramWindow();

    return;
}

void ProgramWindow::Init()
{
    if(!_InitCalled)
    {
        _InitCalled = true;

        auto DesktopVisualMode = SFMLVideoMode::getDesktopMode();

        _DesktopModeSize = AreaSize(DesktopVisualMode.width, DesktopVisualMode.height);
        _DesktopBitsPerPixel = DesktopVisualMode.bitsPerPixel;
    }

    return;
}

bool ProgramWindow::IsWindowOpen()
{
    return WindowImplementation.RenderTarget->isOpen();
}

void ProgramWindow::CreateSFMLProgramWindow()
{
    if(!_SFMLProgramWindowCreateCalled)
    {
        _SFMLProgramWindowCreateCalled = true;

        auto WindowAreaSize = _VisualSettings.GetBackgroundSize();

        SFMLVideoMode ProgramWindowVideoMode(WindowAreaSize.GetWidth(), WindowAreaSize.GetHeight());

        if(!WindowImplementation.RenderTarget)
        {
            auto WindowTitleText = _VisualSettings.GetTitleText();

            WindowImplementation.RenderTarget.reset(new SFMLWindow(ProgramWindowVideoMode, WindowTitleText));
        }
    }

    return;
}

VisualWindow& ProgramWindow::GetVisualWindow()
{
    CreateSFMLProgramWindow();

    return WindowImplementation;
}

void ProgramWindow::ProcessEvent(const WindowEventModel& eventModel)
{
    auto WindowEventProperties = eventModel.GetInputPropertiesWindow();

    auto WindowWasResized = WindowEventProperties.GetWindowResized();

    if(WindowWasResized)
    {
        auto WindowSize = WindowEventProperties.GetWindowSize();

        Polygon VisibleArea (0, 0, WindowSize.GetWidth(), WindowSize.GetHeight());

        auto ViewableArea = VisualCommon::CreateSFMLRectFloat(VisibleArea);

        WindowImplementation.RenderTarget->setView(SFMLView(ViewableArea));
    }
}

void ProgramWindow::DefaultWindowClear()
{
    auto WindowBackgroundColorFilter = _VisualSettings.GetBackgroundColor();
    SFMLColor WindowBackgroundColor;
    WindowBackgroundColorFilter.ChangeSFMLColor(WindowBackgroundColor);

    WindowImplementation.RenderTarget->clear(WindowBackgroundColor);

    return;
}

void ProgramWindow::Draw()
{
    DefaultWindowClear();

    WindowImplementation.RenderTarget->display();

    return;
}

void ProgramWindow::Draw(SFMLGraphicBase& drawable)
{
    DefaultWindowClear();

    WindowImplementation.RenderTarget->draw(drawable);
    WindowImplementation.RenderTarget->display();

    return;
}
