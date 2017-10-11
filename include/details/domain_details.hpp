#pragma once
#include <type_traits>
#include "type_list.hpp"

namespace mtl
{
	namespace details
	{
		template <typename Domain1T, typename Domain2T>
		using less_than = typename std::conditional<(const_strcmp<typename Domain1T::name_type, typename Domain2T::name_type>::value < 0), std::true_type, std::false_type>::type;

		template <typename... DomainArgs>
		struct domain_combinator
		{
			using type = domain_combinator<DomainArgs...>;
		};
		template <typename Domain1T, typename... DomainArgs>
		struct domain_combinator<Domain1T, DomainArgs...>
		{
			using type = typename prepend_types<Domain1T, typename domain_combinator<DomainArgs...>::type>::type;
		};
		template <typename... DomainArgs1, typename... DomainArgs2>
		struct domain_combinator<prod_domain_t<DomainArgs1...>, DomainArgs2...>
		{
			using type = typename domain_combinator<DomainArgs1..., DomainArgs2...>::type;
		};
		
		template <typename... DomainArgs>
		struct domain_collapser_impl
		{
			using type = domain_collapser_impl<DomainArgs...>;
		};
		template <typename String, typename... DomainArgs>
		struct domain_collapser_impl<domain_t<String>, domain_t<String>, DomainArgs...>
		{
			using type = typename domain_collapser_impl<typename exp_domain_t<domain_t<String>, 2>::type, DomainArgs...>::type;
		};
		template <typename Domain1T, int Power, typename... DomainArgs>
		struct domain_collapser_impl<exp_domain_t<Domain1T, Power>, Domain1T, DomainArgs...>
		{
			using type = typename domain_collapser_impl<typename exp_domain_t<Domain1T, Power + 1>::type, DomainArgs...>::type;
		};
		template <typename Domain1T, int Power, typename... DomainArgs>
		struct domain_collapser_impl<Domain1T, exp_domain_t<Domain1T, Power>, DomainArgs...>
		{
			using type = typename domain_collapser_impl<typename exp_domain_t<Domain1T, Power + 1>::type, DomainArgs...>::type;
		};
		template <typename Domain1T, int Power1, int Power2, typename... DomainArgs>
		struct domain_collapser_impl<exp_domain_t<Domain1T, Power1>, exp_domain_t<Domain1T, Power2>, DomainArgs...>
		{
			using type = typename domain_collapser_impl<typename exp_domain_t<Domain1T, Power1 + Power2>::type, DomainArgs...>::type;
		};
		template <typename... DomainArgs>
		struct domain_collapser_impl<scalar_d, DomainArgs...>
		{
			using type = typename domain_collapser_impl<DomainArgs...>::type;
		};
		template <typename... DomainArgs1, typename... DomainArgs2>
		struct domain_collapser_impl<prod_domain_t<DomainArgs1...>, DomainArgs2...>
		{
			using type = typename domain_collapser_impl<DomainArgs1..., DomainArgs2...>::type;
		};
		template <typename Domain1T, typename... DomainArgs>
		struct domain_collapser_impl<Domain1T, DomainArgs...>
		{
			using type = typename prepend_types<Domain1T, typename domain_collapser_impl<DomainArgs...>::type>::type;
		};

		template <typename... DomainArgs>
		struct domain_collapser
		{
			using combined = typename domain_combinator<DomainArgs...>::type;
			using sorted = typename sort_types<combined, less_than>::type;
			using collapsed = typename transfer_types<sorted, domain_collapser_impl>::type;
			using type = typename transfer_types<typename collapsed::type, prod_domain_t>::type;
		};
	}

	template <typename DomainT>
	struct exp_domain_t<DomainT, 1>
	{
		typedef DomainT type;
	};
	template <typename DomainT>
	struct exp_domain_t<DomainT, 0>
	{
		typedef scalar_d type;
	};
	template <typename DomainT, int Power1, int Power2>
	struct exp_domain_t<exp_domain_t<DomainT, Power1>, Power2>
	{
		using type = typename exp_domain_t<DomainT, Power1 * Power2>::type;
	};
	template <typename... Domains, int Power>
	struct exp_domain_t<prod_domain_t<Domains...>, Power>
	{
		using type = typename prod_domain_t<typename exp_domain_t<Domains, Power>::type...>::type;
	};

	template <typename DomainT>
	struct prod_domain_t<DomainT>
	{
		using type = typename DomainT::type;
	};
}
