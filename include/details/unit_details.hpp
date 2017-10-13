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
}
