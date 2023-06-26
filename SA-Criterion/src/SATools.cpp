#include <math.h>
#include "../headers/SATools.h"

namespace SATools {

	double p_sat_liq(const double T) {
		const double a = -6096.9385;
		const double b = 16.635794;
		const double c = -0.02711193;
		const double d = 1.673952e-5;
		const double e = 2.433502;

		return 100 * exp(a / T + b + c * T + d * T * T + e * log(T));
	}

	double p_sat_ice(const double T) {
		const double a = -6024.5282;
		const double b = 24.7219;
		const double c = 0.010613868;
		const double d = -1.3198825e-5;
		const double e = -0.49382577;

		return 100 * exp(a / T + b + c * T + d * T * T + e * log(T));
	}
}