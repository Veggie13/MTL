#pragma once

namespace mtl
{
	namespace details
	{
		template <typename BoolValueT>
		using negate = typename std::conditional<BoolValueT::value, std::false_type, std::true_type>::type;
	}

	template <unsigned Index, template <typename...> typename TypeList, typename Type1, typename... Types>
	struct at<Index, TypeList<Type1, Types...>>
	{
		using type = typename at<Index - 1, TypeList<Types...>>::type;
	};
	template <template <typename...> typename TypeList, typename Type1, typename... Types>
	struct at<0, TypeList<Type1, Types...>>
	{
		using type = Type1;
	};

	template <template <typename...> typename SourceList, template <typename...> typename DestList, typename... Types>
	struct transfer_types<SourceList<Types...>, DestList>
	{
		using type = DestList<Types...>;
	};

	template <typename T, template <typename...> typename TypeList, typename... Types>
	struct prepend_types<T, TypeList<Types...>>
	{
		using type = TypeList<T, Types...>;
	};

	template <template <typename...> typename TypeList, typename... Types1, typename... Types2>
	struct concat_types<TypeList<Types1...>, TypeList<Types2...>>
	{
		using type = TypeList<Types1..., Types2...>;
	};

	template <typename I, template <typename...> typename TypeList, template <typename> typename UnaryPredicate, typename... Is>
	struct filter_types<TypeList<I, Is...>, UnaryPredicate> {
		using type = typename std::conditional<
			UnaryPredicate<I>::value,
			typename prepend_types<I, typename filter_types<TypeList<Is...>, UnaryPredicate>::type>::type,
			typename filter_types<TypeList<Is...>, UnaryPredicate>::type
		>::type;
	};
	template <template <typename...> typename TypeList, template <typename> typename UnaryPredicate>
	struct filter_types<TypeList<>, UnaryPredicate> {
		using type = TypeList<>;
	};

	template <template <typename...> typename TypeList, template <typename, typename> typename Comparison>
	struct sort_types<TypeList<>, Comparison> {
		using type = TypeList<>;
	};
	template <typename N, typename... Is, template <typename...> typename TypeList, template <typename, typename> typename Comparison>
	struct sort_types<TypeList<N, Is...>, Comparison>
	{  // Using the quicksort method.
		template <typename I> struct less_than : Comparison<I, N> {};
		template <typename I> using more_than = details::negate<less_than<I>>;
		using subsequence_less_than_N = typename filter_types<TypeList<Is...>, less_than>::type;
		using subsequence_more_than_N = typename filter_types<TypeList<Is...>, more_than>::type;
		using type = typename concat_types<typename sort_types<subsequence_less_than_N, Comparison>::type,
			typename prepend_types<N, typename sort_types<subsequence_more_than_N, Comparison>::type>::type
		>::type;
	};
}
