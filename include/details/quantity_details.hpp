#pragma once

namespace mtl
{
	template <typename ValueT>
	class quantity<ValueT, scalar_d>
	{
	public:
		typedef ValueT value_type;
		typedef scalar_d domain_type;
		typedef value_type type;

	private:
		quantity();
		quantity(const quantity<value_type, domain_type>&);
	};

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT>::quantity()
		: _siValue(0) {}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT>::quantity(value_type measurement_, const unit_type& unit_)
		: _siValue(measurement_ / unit_.value()) {}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT>::quantity(const type& other_)
		: _siValue(other_._siValue) {}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT>::quantity(value_type siValue_)
		: _siValue(siValue_) {}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT>&
		quantity<ValueT, DomainT>::operator=(const type& other_)
	{
		_siValue = other_._siValue;
		return *this;
	}

	template <typename ValueT, typename DomainT>
	ValueT quantity<ValueT, DomainT>::measurement(const unit_type& unit_) const
	{
		return _siValue / unit_.value();
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator+() const
	{
		return *this;
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator-() const
	{
		return (-_siValue);
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator+(const type& rhs_) const
	{
		return (_siValue + rhs_._siValue);
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator-(const type& rhs_) const
	{
		return (_siValue - rhs_._siValue);
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator*(value_type rhs_) const
	{
		return (_siValue * rhs_);
	}

	template <typename Value1T, typename Value2T, typename DomainT>
	quantity<Value2T, DomainT> operator*(Value1T lhs_, const quantity<Value2T, DomainT>& rhs_)
	{
		return rhs_ * lhs_;
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator/(value_type rhs_) const
	{
		return (_siValue / rhs_);
	}

	template <typename Value1T, typename Value2T, typename DomainT>
	quantity<Value2T, typename exp_domain_t<DomainT, -1>::type>
		operator/(Value1T lhs_, const quantity<Value2T, DomainT>& rhs_)
	{
		return (lhs_ / rhs_._siValue);
	}

	template <typename ValueT, typename DomainT>
	template <typename Domain2T>
	typename quantity<ValueT, typename prod_domain_t<DomainT, Domain2T>::type>::type
		quantity<ValueT, DomainT>::operator*(const quantity<value_type, Domain2T>& rhs_) const
	{
		return (_siValue * rhs_._siValue);
	}

	template <typename ValueT, typename DomainT>
	template <typename Domain2T>
	typename quantity<ValueT, typename prod_domain_t<DomainT, typename exp_domain_t<Domain2T, -1>::type>::type>::type
		quantity<ValueT, DomainT>::operator/(const quantity<value_type, Domain2T>& rhs_) const
	{
		return (_siValue / rhs_._siValue);
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT>& quantity<ValueT, DomainT>::operator+=(const type& rhs_)
	{
		_siValue += rhs_._siValue;
		return *this;
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT>& quantity<ValueT, DomainT>::operator-=(const type& rhs_)
	{
		_siValue -= rhs_._siValue;
		return *this;
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT>& quantity<ValueT, DomainT>::operator*=(value_type rhs_)
	{
		_siValue *= rhs_;
		return *this;
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT>& quantity<ValueT, DomainT>::operator/=(value_type rhs_)
	{
		_siValue /= rhs_;
		return *this;
	}

	template <typename ValueT, typename DomainT>
	template <int Power>
	typename quantity<ValueT, typename exp_domain_t<DomainT, Power>::type>::type
		quantity<ValueT, DomainT>::pow()
	{
		return ::pow(_siValue, Power);
	}
}
