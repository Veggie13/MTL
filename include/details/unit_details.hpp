#pragma once

namespace mtl
{
	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT>::unit(value_type siUnitValue_)
		: _siUnitValue(siUnitValue_) {}

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT>::unit(value_type relUnitValue_, const type& other_)
		: _siUnitValue(relUnitValue_ * other_._siUnitValue) {}

	template <typename ValueT, typename DomainT>
	ValueT unit<ValueT, DomainT>::value() const { return _siUnitValue; }

	template <typename ValueT, typename DomainT>
	template <typename Domain2T>
	unit<ValueT, mult<DomainT, Domain2T>>
		unit<ValueT, DomainT>::operator*(const unit<ValueT, Domain2T>& rhs_) const
	{
		return unit<ValueT, mult<DomainT, Domain2T>>(_siUnitValue * rhs_._siUnitValue);
	}

	template <typename ValueT, typename DomainT>
	template <typename Domain2T>
	unit<ValueT, div<DomainT, Domain2T>>
		unit<ValueT, DomainT>::operator/(const unit<ValueT, Domain2T>& rhs_) const
	{
		return unit<ValueT, div<DomainT, Domain2T>>(_siUnitValue / rhs_._siUnitValue);
	}

	template <typename ValueT, typename DomainT>
	template <int Power>
	unit<ValueT, pow<DomainT, Power>> unit<ValueT, DomainT>::pow() const
	{
		return unit<ValueT, mtl::pow<DomainT, Power>>(::pow(_siUnitValue, Power));
	}

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> nano(const unit<ValueT, DomainT>& other_)
	{ return unit<ValueT, DomainT>((ValueT)1e-9, other_); }

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> micro(const unit<ValueT, DomainT>& other_)
	{ return unit<ValueT, DomainT>((ValueT)1e-6, other_); }

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> milli(const unit<ValueT, DomainT>& other_)
	{ return unit<ValueT, DomainT>((ValueT)1e-3, other_); }

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> centi(const unit<ValueT, DomainT>& other_)
	{ return unit<ValueT, DomainT>((ValueT)1e-2, other_); }

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> deci(const unit<ValueT, DomainT>& other_)
	{ return unit<ValueT, DomainT>((ValueT)1e-1, other_); }

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> kilo(const unit<ValueT, DomainT>& other_)
	{ return unit<ValueT, DomainT>((ValueT)1e3, other_); }

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> mega(const unit<ValueT, DomainT>& other_)
	{ return unit<ValueT, DomainT>((ValueT)1e6, other_); }

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> giga(const unit<ValueT, DomainT>& other_)
	{ return unit<ValueT, DomainT>((ValueT)1e9, other_); }
}
