#pragma once
#include "domain.hpp"
#include "unit.hpp"

namespace mtl
{
	template <typename ValueT, typename DomainT> class quantity;
	
	template <typename Value1T, typename Value2T, typename Domain2T>
	quantity<Value2T, Domain2T> operator*(Value1T lhs_, const quantity<Value2T, Domain2T>& rhs_);
	template <typename Value1T, typename Value2T, typename Domain2T>
	quantity<Value2T, typename exp_domain_t<Domain2T, -1>::type> operator/(Value1T lhs_, const quantity<Value2T, Domain2T>& rhs_);

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
		template <typename Domain2T>
		typename quantity<value_type, typename prod_domain_t<domain_type, Domain2T>::type>::type
			operator*(const quantity<value_type, Domain2T>& rhs_) const;
		template <typename Domain2T>
		typename quantity<value_type, typename prod_domain_t<domain_type, typename exp_domain_t<Domain2T, -1>::type>::type>::type
			operator/(const quantity<value_type, Domain2T>& rhs_) const;

		type& operator+=(const type& rhs_);
		type& operator-=(const type& rhs_);
		type& operator*=(value_type rhs_);
		type& operator/=(value_type rhs_);

		template <int Power>
		typename quantity<value_type, typename exp_domain_t<domain_type, Power>::type>::type
			pow();

	private:
		quantity(value_type siValue_);

		template <typename Value2T, typename Domain2T>
		friend class ::mtl::quantity;
		
		template <typename Value1T, typename Value2T, typename Domain2T>
		friend quantity<Value2T, Domain2T> (::mtl::operator*)(Value1T lhs_, const quantity<Value2T, Domain2T>& rhs_);
		template <typename Value1T, typename Value2T, typename Domain2T>
		friend quantity<Value2T, typename exp_domain_t<Domain2T, -1>::type> (::mtl::operator/)(Value1T lhs_, const quantity<Value2T, Domain2T>& rhs_);

		value_type _siValue;
	};
}

#include "details/quantity_details.hpp"
