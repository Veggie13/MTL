#pragma once

namespace mtl
{
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
		return _siValue * unit_.value();
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator+() const
	{
		return *this;
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator-() const
	{
		return type(-_siValue);
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator+(const type& rhs_) const
	{
		return type(_siValue + rhs_._siValue);
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator-(const type& rhs_) const
	{
		return type(_siValue - rhs_._siValue);
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator*(value_type rhs_) const
	{
		return type(_siValue * rhs_);
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> operator*(ValueT lhs_, const quantity<ValueT, DomainT>& rhs_)
	{
		return rhs_ * lhs_;
	}

	template <typename ValueT, typename DomainT>
	quantity<ValueT, DomainT> quantity<ValueT, DomainT>::operator/(value_type rhs_) const
	{
		return type(_siValue / rhs_);
	}

	template <typename ValueT, typename DomainT>
	ValueT quantity<ValueT, DomainT>::operator/(const type& rhs_) const
	{
		return _siValue / rhs_._siValue;
	}

	template <typename ValueT, typename DomainT>
	template <typename Domain2T>
	quantity<ValueT, typename prod_domain_t<DomainT, Domain2T>::type>
		quantity<ValueT, DomainT>::operator*(const quantity<value_type, Domain2T>& rhs_) const
	{
		return quantity<ValueT, typename prod_domain_t<DomainT, Domain2T>::type>(_siValue * rhs_._siValue);
	}

	template <typename ValueT, typename DomainT>
	template <typename Domain2T>
	quantity<ValueT, typename prod_domain_t<DomainT, typename exp_domain_t<Domain2T, -1>::type>::type>
		quantity<ValueT, DomainT>::operator/(const quantity<value_type, Domain2T>& rhs_) const
	{
		return quantity<ValueT, typename prod_domain_t<DomainT, typename exp_domain_t<Domain2T, -1>::type>::type>(_siValue / rhs_._siValue);
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
}
