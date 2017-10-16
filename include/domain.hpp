#pragma once
#include "string.hpp"

namespace mtl
{
	template <typename Name> struct domain_t;
	template <typename DomainT, int Power> struct exp_domain_t;
	template <typename... DomainArgs> struct prod_domain_t;

	template <typename Name>
	struct domain_t
	{
		typedef Name name_type;
		typedef domain_t<name_type> type;
		typedef type base_domain_type;
	};

	template <typename DomainT, int Power>
	struct exp_domain_t
	{
		typedef typename concat<typename DomainT::name_type, typename itoa<int, Power>::type>::type name_type;
		typedef typename DomainT::type base_domain_type;
		typedef exp_domain_t<base_domain_type, Power> type;

		enum { power = Power };
	};

	namespace details
	{
		template <typename... DomainArgs> struct domain_collapser;
	}

	template <typename... DomainArgs> struct prod_domain_t
	{
		using type = typename details::domain_collapser<DomainArgs...>::type;
	};

	using scalar_d = domain_t<CONST_STR("scalar")>;
}

#include "details/domain_details.hpp"

namespace mtl
{
	template <typename DomainT, int Power>
	using pow = typename exp_domain_t<DomainT, Power>::type;
	template <typename DomainT>
	using sqr = pow<DomainT, 2>;
	template <typename DomainT>
	using recip = pow<DomainT, -1>;
	template <typename... Domains>
	using mult = typename prod_domain_t<Domains...>::type;
	template <typename Domain1, typename Domain2>
	using div = mult<Domain1, recip<Domain2>>;
}
