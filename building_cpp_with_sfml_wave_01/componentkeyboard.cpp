#include "componentkeyboard.h"
using namespace Gautier::SFMLApp;

void ComponentKeyboard::ProcessEvent(const WindowEventModel eventModel)
{
	_CursorIsActive = false;
}

const CollectionComposedVisual& ComponentKeyboard::GetGraphics()
{
	return _CompositeGraphics;
}
