#ifndef RANGEAREASIZEXYWH_H
#define RANGEAREASIZEXYWH_H
#include "rangecoord.h"
#include "rangesizewh.h"
#include "rangequad.h"

namespace Gautier
{
	namespace SFMLApp
	{
		class RangeAreaSizeXYWH
		{
			public:
				RangeAreaSizeXYWH() = default;
				RangeAreaSizeXYWH(const RangeAreaSizeXYWH&) = default;
				RangeAreaSizeXYWH(RangeAreaSizeXYWH&&) = default;
				RangeAreaSizeXYWH& operator=(const RangeAreaSizeXYWH&) = default;
				RangeAreaSizeXYWH& operator=(RangeAreaSizeXYWH&&) = default;
				~RangeAreaSizeXYWH() = default;

				RangeAreaSizeXYWH(const float x, const float y) :
					_Coord {x, y} {};

				RangeAreaSizeXYWH(const float x, const float y, const float width, const float height) :
					_Coord {x, y}, _Size {width, height} {};

				RangeAreaSizeXYWH(const RangeCoord coord) :
					_Coord {coord} {};

				RangeAreaSizeXYWH(const RangeSizeWH sizeWH) :
					_Size {sizeWH} {};

				RangeAreaSizeXYWH(const RangeCoord coord, const RangeSizeWH sizeWH) :
					_Coord {coord}, _Size {sizeWH} {};

				RangeAreaSizeXYWH(RangeQuad<double> values) :
					_Coord(values.N1, values.N2), _Size(values.N3, values.N4) {};

				RangeAreaSizeXYWH(RangeQuad<float> values) :
					_Coord(values.N1, values.N2), _Size(values.N3, values.N4) {};

				RangeAreaSizeXYWH(RangeQuad<int> values) :
					_Coord(values.N1, values.N2), _Size(values.N3, values.N4) {};

				RangeAreaSizeXYWH(RangeQuad<long> values) :
					_Coord(values.N1, values.N2), _Size(values.N3, values.N4) {};

				RangeAreaSizeXYWH(RangeQuad<long double> values) :
					_Coord(values.N1, values.N2), _Size(values.N3, values.N4) {};

				RangeAreaSizeXYWH(RangeQuad<long long> values) :
					_Coord(values.N1, values.N2), _Size(values.N3, values.N4) {};

				RangeAreaSizeXYWH(RangeQuad<short> values) :
					_Coord(values.N1, values.N2), _Size(values.N3, values.N4) {};

				RangeAreaSizeXYWH(RangeQuad<unsigned int> values) :
					_Coord(values.N1, values.N2), _Size(values.N3, values.N4) {};

				RangeAreaSizeXYWH(RangeQuad<unsigned long> values) :
					_Coord(values.N1, values.N2), _Size(values.N3, values.N4) {};

				RangeAreaSizeXYWH(RangeQuad<unsigned long long> values) :
					_Coord(values.N1, values.N2), _Size(values.N3, values.N4) {};

				const float GetWidth();
				const float GetHeight();
				const float GetX();
				const float GetY();
				const float GetZ();
				RangeCoord CreateCoord();
				RangeSizeWH CreateSize();

				void SetWidth(const float value);
				void SetHeight(const float value);
				void SetX(const float value);
				void SetY(const float value);
				void SetZ(const float value);
				void SetCoord(const RangeCoord value);
				void SetSize(const RangeSizeWH value);
			private:
				RangeCoord _Coord;
				RangeSizeWH _Size;
		};
	}
}
#endif // RANGEAREASIZEXYWH_H
