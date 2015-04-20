#include "visualcommon.h"
using namespace Gautier::SFMLApp::VisualFundamentals;

Polygon& VisualCommon::CopyPolygonValue(const SFMLRectFloat value, Polygon& target)
{
    target.SetX(value.left);
    target.SetY(value.top);
    target.SetWidth(value.width);
    target.SetHeight(value.height);

    return target;
}

Polygon& VisualCommon::CopyPolygonValue(const SFMLRectInt value, Polygon& target)
{
    target.SetX(value.left);
    target.SetY(value.top);
    target.SetWidth(value.width);
    target.SetHeight(value.height);

    return target;
}

Position VisualCommon::CreatePosition(const SFMLVector2Float value)
{
    Position PositionValue(value.x, value.y);

    return PositionValue;
}

Position VisualCommon::CreatePosition(const SFMLVector2Int value)
{
    Position PositionValue(value.x, value.y);

    return PositionValue;
}

Position VisualCommon::CreatePosition(const SFMLVector2UInt value)
{
    Position PositionValue(value.x, value.y);

    return PositionValue;
}

Position& VisualCommon::CopyPositionValue(const SFMLVector2Float value, Position& target)
{
    target.SetX(value.x);
    target.SetY(value.y);

    return target;
}

Position& VisualCommon::CopyPositionValue(const SFMLVector2Int value, Position& target)
{
    target.SetX(value.x);
    target.SetY(value.y);

    return target;
}

Position& VisualCommon::CopyPositionValue(const SFMLVector2UInt value, Position& target)
{
    target.SetX(value.x);
    target.SetY(value.y);

    return target;
}

SFMLVector2Float VisualCommon::CreateSFMLVectorFloat(Position& logicalPosition)
{
    SFMLVector2Float SFMLVector(logicalPosition.GetX(), logicalPosition.GetY());

    return SFMLVector;
}

SFMLVector2Int VisualCommon::CreateSFMLVectorInt(Position& logicalPosition)
{
    SFMLVector2Int SFMLVector(logicalPosition.GetX(), logicalPosition.GetY());

    return SFMLVector;
}

SFMLVector2UInt VisualCommon::CreateSFMLVectorUInt(Position& logicalPosition)
{
    SFMLVector2UInt SFMLVector(logicalPosition.GetX(), logicalPosition.GetY());

    return SFMLVector;
}

SFMLRectFloat VisualCommon::CreateSFMLRectFloat(Polygon& logicalPolygon)
{
    SFMLRectFloat SFMLRect(logicalPolygon.GetX(), logicalPolygon.GetY(), logicalPolygon.GetWidth(), logicalPolygon.GetHeight());

    return SFMLRect;
}

SFMLRectInt VisualCommon::CreateSFMLRectInt(Polygon& logicalPolygon)
{
    SFMLRectInt SFMLRect(logicalPolygon.GetX(), logicalPolygon.GetY(), logicalPolygon.GetWidth(), logicalPolygon.GetHeight());

    return SFMLRect;
}
