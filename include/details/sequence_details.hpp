#pragma once

namespace mtl
{
	template <typename T, template <typename TT, TT...> typename SourceSeq, template <T...> typename DestSeq, T... Ts>
	struct untyped_seq<T, SourceSeq<T, Ts...>, DestSeq<>>
	{
		using type = DestSeq<Ts...>;
	};

	template <typename T, template <T...> typename SourceSeq, template <typename TT, TT...> typename DestSeq, T... Ts>
	struct typed_seq<T, SourceSeq<Ts...>, DestSeq>
	{
		using type = DestSeq<T, Ts...>;
	};

	template <typename T, template <typename TT, TT...> typename SourceList, template <typename TT, TT...> typename DestList, T... Ts>
	struct transfer_seq<T, SourceList<T, Ts...>, DestList>
	{
		using type = DestList<T, Ts...>;
	};

	template <typename T, T Value, template <typename TT, TT...> typename Sequence, T... Ts>
	struct prepend_seq<T, Value, Sequence<T, Ts...>>
	{
		using type = Sequence<T, Value, Ts...>;
	};

	template <typename T, template <typename TT, TT...> typename Sequence, T... Ts>
	struct take_seq<0, Sequence<T, Ts...>>
	{
		using type = Sequence<T>;
	};
	template <typename T, template <typename TT, TT...> typename Sequence, T T1, T... Ts>
	struct take_seq<0, Sequence<T, T1, Ts...>>
	{
		using type = Sequence<T>;
	};
	template <unsigned N, typename T, template <typename TT, TT...> typename Sequence, T T1, T... Ts>
	struct take_seq<N, Sequence<T, T1, Ts...>>
	{
		using type = typename prepend_seq<T, T1, typename take_seq<N - 1, Sequence<T, Ts...>>::type>::type;
	};
}
