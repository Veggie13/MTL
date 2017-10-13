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
		unit(value_type relUnitValue_, const type& other_);

		value_type value() const;

	private:
		unit();
		unit(const type&);

		value_type _siUnitValue;
	};
}

#include "details/unit_details.hpp"
