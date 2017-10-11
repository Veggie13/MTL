#pragma once
#include "sequence.hpp"

namespace mtl
{
	template <char... Chars> struct const_string;
	template <typename String1, typename String2> struct const_strcmp;
	template <typename... Strings> struct concat;
	template <typename Integer, Integer Value> struct itoa;

	template <unsigned N>
	constexpr unsigned const_strlen(const char(&)[N]) { return N - 1; }

	template <char... Chars>
	struct const_string
	{
		enum { length = const_strlen({ Chars..., 0 }) };
		static constexpr char value[length + 1] = { Chars..., 0 };
	};

	template <typename String1, typename String2>
	struct const_strcmp
	{
		enum { value };
	};

	template <typename... Strings>
	struct concat
	{
		using type;
	};

	namespace details
	{
		template<bool neg, uintmax_t rem, uint8_t... digits> struct explode;

		template<typename T>
		constexpr uintmax_t cabs(T num) { return (num < 0) ? -num : num; }
	}

	template <typename Integer, Integer Value>
	struct itoa
	{
		using type = typename details::explode<(Value < 0), details::cabs(Value)>::type;
	};
}

#include "details/string_details.hpp"

#define CONST_STR(STR) ::mtl::details::get_const_string<::mtl::const_strlen(STR), EXPLODE(STR)>::type
