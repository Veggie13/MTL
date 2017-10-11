#pragma once

namespace mtl
{
	template <typename T, T... Ts> struct sequence {};
	template <typename T, typename SourceSeq, typename DestSeq> struct untyped_seq;
	template <typename T, typename SourceSeq, template <typename TT, TT...> typename DestSeq> struct typed_seq;
	template <typename T, typename SourceList, template <typename TT, TT...> typename DestList> struct transfer_seq;
	template <typename T, T Value, typename Sequence> struct prepend_seq;
	template <unsigned N, typename Sequence> struct take_seq;

	template <typename T, typename SourceSeq, typename DestSeq> struct untyped_seq
	{
		using type;
	};

	template <typename T, typename SourceSeq, template <typename TT, TT...> typename DestSeq>
	struct typed_seq
	{
		using type;
	};

	template <typename T, typename SourceList, template <typename TT, TT...> typename DestList>
	struct transfer_seq
	{
		using type;
	};

	template <typename T, T Value, typename Sequence>
	struct prepend_seq
	{
		using type;
	};

	template <unsigned N, typename Sequence>
	struct take_seq
	{
		using type;
	};
}

#include "details/sequence_details.hpp"
