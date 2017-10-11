#pragma once

namespace mtl
{
	template <typename... Types> struct type_list {};
	template <unsigned Index, typename TypeList> struct at;
	template <typename SourceList, template <typename...> typename DestList> struct transfer_types;
	template <typename T, typename TypeList> struct prepend_types;
	template <typename TypeList1, typename TypeList2> struct concat_types;
	template <typename TypeList, template <typename> typename UnaryPredicate> struct filter_types;
	template <typename TypeList, template <typename, typename> typename Comparison> struct sort_types;

	template <unsigned Index, typename TypeList>
	struct at
	{
		using type;
	};

	template <typename SourceList, template <typename...> typename DestList>
	struct transfer_types
	{
		using type;
	};

	template <typename T, typename TypeList> struct prepend_types
	{
		using type;
	};

	template <typename TypeList1, typename TypeList2>
	struct concat_types
	{
		using type;
	};

	template <typename TypeList, template <typename> typename UnaryPredicate>
	struct filter_types
	{
		using type;
	};

	template <typename TypeList, template <typename, typename> typename Comparison>
	struct sort_types
	{
		using type;
	};
}

#include "details/type_list_details.hpp"
