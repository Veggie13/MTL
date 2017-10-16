#pragma once
#include "unit.hpp"
#include "std_domains.hpp"

#define DEFINE_UNIT(NAME, DOMAIN, VALUE) \
	const unit_f<DOMAIN> NAME##_f((float)VALUE); \
	const unit_lf<DOMAIN> NAME##_lf((double)VALUE)
#define DERIVE_UNIT(NAME, DOMAIN, VALUE, OTHER) \
	const unit_f<DOMAIN> NAME##_f((float)VALUE, OTHER##_f); \
	const unit_lf<DOMAIN> NAME##_lf((double)VALUE, OTHER##_lf)
#define PREFIX_UNIT(PREFIX, NAME, DOMAIN) \
	const unit_f<DOMAIN> PREFIX##NAME##_f = PREFIX(NAME##_f); \
	const unit_lf<DOMAIN> PREFIX##NAME##_lf = PREFIX(NAME##_lf)

namespace mtl
{
	DEFINE_UNIT(metre, distance_d, 1);
	PREFIX_UNIT(nano, metre, distance_d);
	PREFIX_UNIT(micro, metre, distance_d);
	PREFIX_UNIT(milli, metre, distance_d);
	PREFIX_UNIT(centi, metre, distance_d);
	PREFIX_UNIT(deci, metre, distance_d);
	PREFIX_UNIT(kilo, metre, distance_d);

	DEFINE_UNIT(second, time_d, 1);
	PREFIX_UNIT(nano, second, time_d);
	PREFIX_UNIT(micro, second, time_d);
	PREFIX_UNIT(milli, second, time_d);
	DERIVE_UNIT(minute, time_d, 60, second);
	DERIVE_UNIT(hour, time_d, 60, minute);
	DERIVE_UNIT(day, time_d, 24, hour); // calendar stuff is more complicated, should be more precise

	DEFINE_UNIT(gram, mass_d, 1);
	PREFIX_UNIT(nano, gram, mass_d);
	PREFIX_UNIT(micro, gram, mass_d);
	PREFIX_UNIT(milli, gram, mass_d);
	PREFIX_UNIT(centi, gram, mass_d);
	PREFIX_UNIT(deci, gram, mass_d);
	PREFIX_UNIT(kilo, gram, mass_d);

	DEFINE_UNIT(coulomb, charge_d, 1);

	DEFINE_UNIT(hertz, frequency_d, 1);
	PREFIX_UNIT(kilo, hertz, frequency_d);
	PREFIX_UNIT(mega, hertz, frequency_d);
	PREFIX_UNIT(giga, hertz, frequency_d);

	const unit_f<velocity_d> mps_f = metre_f / second_f;
	const unit_lf<velocity_d> mps_lf = metre_lf / second_lf;
	const unit_f<velocity_d> kph_f = kilometre_f / hour_f;
	const unit_lf<velocity_d> kph_lf = kilometre_lf / hour_lf;

	DEFINE_UNIT(g, acceleration_d, 9.80665);

	const unit_f<volume_d> litre_f = centimetre_f.pow<3>();
	const unit_lf<volume_d> litre_lf = centimetre_lf.pow<3>();
}
