#pragma once

namespace mtl
{
	template <typename ValueT, typename DomainT>
	class unit
	{
	public:
		typedef unit<ValueT, DomainT> type;
		typedef ValueT value_type;
		typedef DomainT domain_type;

		unit(value_type siUnitValue_);

		value_type value() const;

	private:
		unit();
		unit(const type&);

		value_type _siUnitValue;
	};

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT>::unit(value_type siUnitValue_)
		: _siUnitValue(siUnitValue_) {}

	template <typename ValueT, typename DomainT>
	ValueT unit<ValueT, DomainT>::value() const { return _siUnitValue; }
}
