#pragma once
#include "domain.hpp"

namespace mtl
{
	using distance_d = domain_t<CONST_STR("distance")>;
	using time_d = domain_t<CONST_STR("time")>;
	using mass_d = domain_t<CONST_STR("mass")>;
	using charge_d = domain_t<CONST_STR("charge")>;

	using frequency_d = recip<time_d>;
	using area_d = sqr<distance_d>;
	using volume_d = pow<distance_d, 3>;
	using velocity_d = div<distance_d, time_d>;
	using acceleration_d = div<distance_d, sqr<time_d>>;
	using force_d = mult<mass_d, acceleration_d>;
	using energy_d = mult<mass_d, sqr<velocity_d>>;
	using pressure_d = div<force_d, area_d>;
	using current_d = div<charge_d, time_d>;
	using power_d = div<energy_d, time_d>;
	using voltage_d = div<power_d, current_d>;
	using capacitance_d = div<charge_d, voltage_d>;
	using resistance_d = div<voltage_d, current_d>;
}
