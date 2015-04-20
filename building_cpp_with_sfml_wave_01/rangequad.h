#ifndef RANGEQUAD_H
#define RANGEQUAD_H

namespace Gautier
{
	namespace SFMLApp
	{
		template<typename N>
		class RangeQuad;
		/*
		Integer
		*/
		template<>
		class RangeQuad<short>
		{
			public:
				using NumberType = short;

				RangeQuad() = default;
				RangeQuad(const RangeQuad&) = default;
				RangeQuad(RangeQuad&&) = default;
				RangeQuad& operator=(const RangeQuad&) = default;
				RangeQuad& operator=(RangeQuad&&) = default;
				~RangeQuad() = default;

				RangeQuad(const NumberType n1, const NumberType n2, const NumberType n3, const NumberType n4) :
					N1 {n1}, N2 {n2}, N3 {n3}, N4 {n4} {};

				NumberType N1;
				NumberType N2;
				NumberType N3;
				NumberType N4;
		};

		template<>
		class RangeQuad<int>
		{
			public:
				using NumberType = int;

				RangeQuad() = default;
				RangeQuad(const RangeQuad&) = default;
				RangeQuad(RangeQuad&&) = default;
				RangeQuad& operator=(const RangeQuad&) = default;
				RangeQuad& operator=(RangeQuad&&) = default;
				~RangeQuad() = default;

				RangeQuad(const NumberType n1, const NumberType n2, const NumberType n3, const NumberType n4) :
					N1 {n1}, N2 {n2}, N3 {n3}, N4 {n4} {};

				NumberType N1 {0};
				NumberType N2 {0};
				NumberType N3 {0};
				NumberType N4 {0};
		};

		template<>
		class RangeQuad<unsigned int>
		{
			public:
				using NumberType = unsigned int;

				RangeQuad() = default;
				RangeQuad(const RangeQuad&) = default;
				RangeQuad(RangeQuad&&) = default;
				RangeQuad& operator=(const RangeQuad&) = default;
				RangeQuad& operator=(RangeQuad&&) = default;
				~RangeQuad() = default;

				RangeQuad(const NumberType n1, const NumberType n2, const NumberType n3, const NumberType n4) :
					N1 {n1}, N2 {n2}, N3 {n3}, N4 {n4} {};

				NumberType N1 {0};
				NumberType N2 {0};
				NumberType N3 {0};
				NumberType N4 {0};
		};

		template<>
		class RangeQuad<long>
		{
			public:
				using NumberType = long;

				RangeQuad() = default;
				RangeQuad(const RangeQuad&) = default;
				RangeQuad(RangeQuad&&) = default;
				RangeQuad& operator=(const RangeQuad&) = default;
				RangeQuad& operator=(RangeQuad&&) = default;
				~RangeQuad() = default;

				RangeQuad(const NumberType n1, const NumberType n2, const NumberType n3, const NumberType n4) :
					N1 {n1}, N2 {n2}, N3 {n3}, N4 {n4} {};

				NumberType N1 {0};
				NumberType N2 {0};
				NumberType N3 {0};
				NumberType N4 {0};
		};

		template<>
		class RangeQuad<long long>
		{
			public:
				using NumberType = long long;

				RangeQuad() = default;
				RangeQuad(const RangeQuad&) = default;
				RangeQuad(RangeQuad&&) = default;
				RangeQuad& operator=(const RangeQuad&) = default;
				RangeQuad& operator=(RangeQuad&&) = default;
				~RangeQuad() = default;

				RangeQuad(const NumberType n1, const NumberType n2, const NumberType n3, const NumberType n4) :
					N1 {n1}, N2 {n2}, N3 {n3}, N4 {n4} {};

				NumberType N1 {0};
				NumberType N2 {0};
				NumberType N3 {0};
				NumberType N4 {0};
		};

		template<>
		class RangeQuad<unsigned long>
		{
			public:
				using NumberType = unsigned long;

				RangeQuad() = default;
				RangeQuad(const RangeQuad&) = default;
				RangeQuad(RangeQuad&&) = default;
				RangeQuad& operator=(const RangeQuad&) = default;
				RangeQuad& operator=(RangeQuad&&) = default;
				~RangeQuad() = default;

				RangeQuad(const NumberType n1, const NumberType n2, const NumberType n3, const NumberType n4) :
					N1 {n1}, N2 {n2}, N3 {n3}, N4 {n4} {};

				NumberType N1 {0};
				NumberType N2 {0};
				NumberType N3 {0};
				NumberType N4 {0};
		};

		template<>
		class RangeQuad<unsigned long long>
		{
			public:
				using NumberType = unsigned long long;

				RangeQuad() = default;
				RangeQuad(const RangeQuad&) = default;
				RangeQuad(RangeQuad&&) = default;
				RangeQuad& operator=(const RangeQuad&) = default;
				RangeQuad& operator=(RangeQuad&&) = default;
				~RangeQuad() = default;

				RangeQuad(const NumberType n1, const NumberType n2, const NumberType n3, const NumberType n4) :
					N1 {n1}, N2 {n2}, N3 {n3}, N4 {n4} {};

				NumberType N1 {0};
				NumberType N2 {0};
				NumberType N3 {0};
				NumberType N4 {0};
		};
		/*
		Floating Point
		*/
		template<>
		class RangeQuad<float>
		{
			public:
				using NumberType = float;

				RangeQuad() = default;
				RangeQuad(const RangeQuad&) = default;
				RangeQuad(RangeQuad&&) = default;
				RangeQuad& operator=(const RangeQuad&) = default;
				RangeQuad& operator=(RangeQuad&&) = default;
				~RangeQuad() = default;

				RangeQuad(const NumberType n1, const NumberType n2, const NumberType n3, const NumberType n4) :
					N1 {n1}, N2 {n2}, N3 {n3}, N4 {n4} {};

				NumberType N1 {0};
				NumberType N2 {0};
				NumberType N3 {0};
				NumberType N4 {0};
		};

		template<>
		class RangeQuad<double>
		{
			public:
				using NumberType = double;

				RangeQuad() = default;
				RangeQuad(const RangeQuad&) = default;
				RangeQuad(RangeQuad&&) = default;
				RangeQuad& operator=(const RangeQuad&) = default;
				RangeQuad& operator=(RangeQuad&&) = default;
				~RangeQuad() = default;

				RangeQuad(const NumberType n1, const NumberType n2, const NumberType n3, const NumberType n4) :
					N1 {n1}, N2 {n2}, N3 {n3}, N4 {n4} {};

				NumberType N1 {0};
				NumberType N2 {0};
				NumberType N3 {0};
				NumberType N4 {0};
		};

		template<>
		class RangeQuad<long double>
		{
			public:
				using NumberType = long double;

				RangeQuad() = default;
				RangeQuad(const RangeQuad&) = default;
				RangeQuad(RangeQuad&&) = default;
				RangeQuad& operator=(const RangeQuad&) = default;
				RangeQuad& operator=(RangeQuad&&) = default;
				~RangeQuad() = default;

				RangeQuad(const NumberType n1, const NumberType n2, const NumberType n3, const NumberType n4) :
					N1 {n1}, N2 {n2}, N3 {n3}, N4 {n4} {};

				NumberType N1 {0};
				NumberType N2 {0};
				NumberType N3 {0};
				NumberType N4 {0};
		};
	}
}
#endif // QUADVALUES4_H
