#include "rangesizewh.h"
using namespace Gautier::SFMLApp::DimensionalFundamentals;

const float RangeSizeWH::GetWidth()
{
    return _Width;
}

const float RangeSizeWH::GetHeight()
{
    return _Height;
}

void RangeSizeWH::SetWidth(const float value)
{
    _Width = value;
}

void RangeSizeWH::SetHeight(const float value)
{
    _Height = value;
}
