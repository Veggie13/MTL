#pragma once

namespace mtl
{
	namespace details
	{
		template <unsigned Length, char... Chars>
		struct get_const_string
		{
			using type = typename untyped_seq<char, typename take_seq<Length, sequence<char, Chars...>>::type, const_string<>>::type;
		};

		template<uint8_t... digits>
		struct positive_to_chars
		{
			using type = const_string<('0' + digits)...>;
		};

		template<uint8_t... digits>
		struct negative_to_chars
		{
			using type = const_string<'-', ('0' + digits)...>;
		};

		template<bool neg, uint8_t... digits>
		struct to_chars
		{
			using type = typename positive_to_chars<digits...>::type;
		};

		template<uint8_t... digits>
		struct to_chars<true, digits...>
		{
			using type = typename negative_to_chars<digits...>::type;
		};

		template<bool neg, uintmax_t rem, uint8_t... digits>
		struct explode : explode<neg, rem / 10, rem % 10, digits...> {};

		template<bool neg, uint8_t... digits>
		struct explode<neg, 0, digits...>
		{
			using type = typename to_chars<neg, digits...>::type;
		};
	}

	template <>
	struct const_strcmp<const_string<>, const_string<>>
	{
		enum { value = 0 };
	};
	template <char... Chars>
	struct const_strcmp<const_string<Chars...>, const_string<>>
	{
		enum { value = 1 };
	};
	template <char... Chars>
	struct const_strcmp<const_string<>, const_string<Chars...>>
	{
		enum { value = -1 };
	};
	template <char Char1, char... Chars1, char Char2, char... Chars2>
	struct const_strcmp<const_string<Char1, Chars1...>, const_string<Char2, Chars2...>>
	{
		enum
		{
			value = (Char1 < Char2) ? -1 :
			(Char1 > Char2) ? 1 :
			const_strcmp<const_string<Chars1...>, const_string<Chars2...>>::value
		};
	};

	template <typename String1, typename... Strings>
	struct concat<String1, Strings...>
	{
		using type = typename concat<String1, typename concat<Strings...>::type>::type;
	};
	template <char... Chars1, char... Chars2>
	struct concat<const_string<Chars1...>, const_string<Chars2...>>
	{
		using type = const_string<Chars1..., Chars2...>;
	};
}

#define EXPLODE_1(str, i) \
	(sizeof(str) > (i) ? (str)[(i)] : 0)
#define EXPLODE_4(str, i) \
	EXPLODE_1(str, i+0), \
	EXPLODE_1(str, i+1), \
	EXPLODE_1(str, i+2), \
	EXPLODE_1(str, i+3)
#define EXPLODE_16(str, i) \
	EXPLODE_4(str, i+0), \
	EXPLODE_4(str, i+4), \
	EXPLODE_4(str, i+8), \
	EXPLODE_4(str, i+12)
#define EXPLODE_64(str, i) \
	EXPLODE_16(str, i+0), \
	EXPLODE_16(str, i+16), \
	EXPLODE_16(str, i+32), \
	EXPLODE_16(str, i+48)
#define EXPLODE(str) EXPLODE_64(str, 0)
