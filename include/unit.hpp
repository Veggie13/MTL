#pragma once
#include "domain.hpp"

namespace mtl
{
	template <typename ValueT, typename DomainT>
	class unit
	{
	public:
		typedef unit<ValueT, DomainT> type;
		typedef ValueT value_type;
		typedef DomainT domain_type;

		explicit unit(value_type siUnitValue_);
		unit(value_type relUnitValue_, const type& other_);
		unit(type&& rhs_);

		value_type value() const;

		template <typename Domain2T>
		unit<value_type, mult<domain_type, Domain2T>>
			operator*(const unit<value_type, Domain2T>& rhs_) const;
		template <typename Domain2T>
		unit<value_type, div<domain_type, Domain2T>>
			operator/(const unit<value_type, Domain2T>& rhs_) const;

		template <int Power>
		unit<value_type, mtl::pow<domain_type, Power>> pow() const;

	private:
		unit();
		unit(const type&);

		template <typename Value2T, typename Domain2T>
		friend class ::mtl::unit;

		value_type _siUnitValue;
	};

	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> nano(const unit<ValueT, DomainT>& other_);
	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> micro(const unit<ValueT, DomainT>& other_);
	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> milli(const unit<ValueT, DomainT>& other_);
	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> centi(const unit<ValueT, DomainT>& other_);
	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> deci(const unit<ValueT, DomainT>& other_);
	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> kilo(const unit<ValueT, DomainT>& other_);
	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> mega(const unit<ValueT, DomainT>& other_);
	template <typename ValueT, typename DomainT>
	unit<ValueT, DomainT> giga(const unit<ValueT, DomainT>& other_);

	template <typename DomainT>
	using unit_f = unit<float, DomainT>;
	template <typename DomainT>
	using unit_lf = unit<double, DomainT>;
	template <typename DomainT>
	using unit_ll = unit<long long, DomainT>;
	template <typename DomainT>
	using unit_l = unit<long, DomainT>;
	template <typename DomainT>
	using unit_s = unit<short, DomainT>;
}

#include "details/unit_details.hpp"
