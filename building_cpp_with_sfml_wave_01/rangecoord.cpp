#include "rangecoord.h"
using namespace Gautier::SFMLApp;

const float RangeCoord::GetX()
{
	return _X;
}

const float RangeCoord::GetY()
{
	return _Y;
}

const float RangeCoord::GetZ()
{
	return _Z;
}

void RangeCoord::SetX(const float value)
{
	_X = value;
}

void RangeCoord::SetY(const float value)
{
	_Y = value;
}

void RangeCoord::SetZ(const float value)
{
	_Z = value;
}
