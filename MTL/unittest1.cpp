#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>
#include <domain.hpp>
#include <quantity.hpp>

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
			using L = domain_t<CONST_STR("length")>;
			using T = domain_t<CONST_STR("time")>;
			using F = typename exp_domain_t<T, -1>::type;
			using V = typename prod_domain_t<L, typename exp_domain_t<T, -1>::type>::type;

			using l1 = typename prod_domain_t<L, T, T, L, F>::type;
			using l2 = typename prod_domain_t<L, F, L, T>::type;
			using theList = typename prod_domain_t<l1, l2>::type;
			//using x = at<2, colList>::type;
			auto names = transfer_types<theList, printer>::type::go();
			//const char* names[] =
			//{
			//	at<0, theList>::type::name_type::value,
			//	at<1, theList>::type::name_type::value,
			//	at<2, theList>::type::name_type::value,
			//	at<3, theList>::type::name_type::value,
			//	at<4, theList>::type::name_type::value,
			//	at<5, theList>::type::name_type::value,
			//	at<6, theList>::type::name_type::value,
			//	at<7, theList>::type::name_type::value,
			//	at<8, theList>::type::name_type::value,
			//};
			unit<float, L> meter(1);
			unit<float, T> second(1);
			unit<float, V> mps(1);
			unit<float, V> fps(0.3f);
			unit<float, V> kph(1000.0f / 3600);

			quantity<float, L> d(13, meter);
			quantity<float, T> t(2, second);
			auto v = d / t;
			float vel = v.measurement(mps);
			float vel2 = v.measurement(fps);
			float vel3 = v.measurement(kph);
		}

	};
}