#pragma once
#include "domain.hpp"
#include "unit.hpp"

namespace mtl
{
	template <typename ValueT, typename DomainT>
	class quantity
	{
	public:
		typedef ValueT value_type;
		typedef DomainT domain_type;
		typedef quantity<value_type, domain_type> type;
		typedef unit<value_type, domain_type> unit_type;

		quantity();
		quantity(value_type measurement_, const unit_type& unit_);
		quantity(const type& other_);

		type& operator=(const type& other_);

		value_type measurement(const unit_type& unit_) const;

		type operator+() const;
		type operator-() const;
		type operator+(const type& rhs_) const;
		type operator-(const type& rhs_) const;
		type operator*(value_type rhs_) const;
		type operator/(value_type rhs_) const;
		value_type operator/(const type& rhs_) const;
		template <typename Domain2T>
		quantity<value_type, typename prod_domain_t<domain_type, Domain2T>::type>
			operator*(const quantity<value_type, Domain2T>& rhs_) const;
		template <typename Domain2T>
		quantity<value_type, typename prod_domain_t<domain_type, typename exp_domain_t<Domain2T, -1>::type>::type>
			operator/(const quantity<value_type, Domain2T>& rhs_) const;

		type& operator+=(const type& rhs_);
		type& operator-=(const type& rhs_);
		type& operator*=(value_type rhs_);
		type& operator/=(value_type rhs_);

	private:
		quantity(value_type siValue_);

		template <typename Value2T, typename Domain2T>
		friend class quantity;
		friend type operator*(value_type lhs_, const type& rhs_);

		value_type _siValue;
	};
}

#include "details/quantity_details.hpp"
