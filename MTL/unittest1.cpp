#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <domain.hpp>
#include <quantity.hpp>
#include <std_units.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace mtl
{
}

template <typename... Types> struct printer;
template <>
struct printer<>
{
	using type = printer<>;
	static std::vector<std::string> go() { return{}; }
};
template <typename T, typename... Types>
struct printer<T, Types...>
{
	using type = printer<T, Types...>;
	static std::vector<std::string> go()
	{
		using name_type = typename T::name_type;
		auto name = name_type::value;
		std::vector<std::string> result = printer<Types...>::type::go();
		result.insert(result.begin(), { name });
		return result;
	}
};

namespace MTL
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			using namespace mtl;
			using L = distance_d;
			using T = time_d;
			using F = frequency_d;
			using V = velocity_d;

			using l1 = mult<L, T, T, L, F>;
			using l2 = mult<L, F, L, T>;
			using theList = mult<l1, l2>;
			auto names = transfer_types<theList, printer>::type::go();

			unit_f<V> fps(0.3f, mps_f);

			quantity_f<L> d(13, metre_f);
			quantity_f<T> t(2, second_f);
			quantity_f<V> v = d / t;
			float vel = v.measurement(mps_f);
			float vel2 = v.measurement(fps);
			float vel3 = v.measurement(kph_f);

			auto x = 2 * v;
			auto y = 2 / v;
			auto z = ((v.pow<-3>() * v) * v) * v;
			auto w = v.pow<0>();
			auto u = x * y;
			auto e = v / v;
		}

	};
}