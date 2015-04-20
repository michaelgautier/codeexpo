#include "rangeareasizexywh.h"
using namespace Gautier::SFMLApp;

const float RangeAreaSizeXYWH::GetWidth()
{
	return _Size.GetWidth();
}

const float RangeAreaSizeXYWH::GetHeight()
{
	return _Size.GetHeight();
}

const float RangeAreaSizeXYWH::GetX()
{
	return _Coord.GetX();
}

const float RangeAreaSizeXYWH::GetY()
{
	return _Coord.GetY();
}

const float RangeAreaSizeXYWH::GetZ()
{
	return _Coord.GetZ();
}

RangeCoord RangeAreaSizeXYWH::CreateCoord()
{
	return _Coord;
}

RangeSizeWH RangeAreaSizeXYWH::CreateSize()
{
	return _Size;
}

void RangeAreaSizeXYWH::SetWidth(const float value)
{
	_Size.SetWidth(value);
}

void RangeAreaSizeXYWH::SetHeight(const float value)
{
	_Size.SetHeight(value);
}

void RangeAreaSizeXYWH::SetX(const float value)
{
	_Coord.SetX(value);
}

void RangeAreaSizeXYWH::SetY(const float value)
{
	_Coord.SetY(value);
}

void RangeAreaSizeXYWH::SetZ(const float value)
{
	_Coord.SetZ(value);
}

void RangeAreaSizeXYWH::SetCoord(const RangeCoord value)
{
	_Coord = value;
}

void RangeAreaSizeXYWH::SetSize(const RangeSizeWH value)
{
	_Size = value;
}
