#include <math.h>
#include "../headers/DetSATools.h"

namespace DetSATools {

	double compute_p_sat_liq(const double T_K) {
		// Calculates the liquid saturation pressure "p_sat_liq" (in units of Pa) 
		// from the Schmidt-Appleman criterion. The equation can be found in Schumann 2012.
		// 
		// The inputs are as follows
		//	- T is the absolute temperature in Kelvin

		const double a = -6096.9385;
		const double b = 16.635794;
		const double c = -0.02711193;
		const double d = 1.673952e-5;
		const double e = 2.433502;

		return 100 * exp(a / T_K + b + c * T_K + d * T_K * T_K + e * log(T_K));
	}

	double compute_p_sat_ice(const double T_K) {
		// Calculates the ice saturation pressure "p_sat_ice" (in units of Pa)
		// from the Schmidt-Appleman criterion. The equation can be found in Schumann 2012.
		// 
		// The inputs are as follows
		//	- T_K is the absolute temperature in Kelvin

		const double a = -6024.5282;
		const double b = 24.7219;
		const double c = 0.010613868;
		const double d = -1.3198825e-5;
		const double e = -0.49382577;

		return 100 * exp(a / T_K + b + c * T_K + d * T_K * T_K + e * log(T_K));
	}

	double compute_gradient_G(const double p_atm_Pa, const double EI_H20,
		const double Q_fuel_MJperkg, const double eta_ov) {
		// Calculates the gradient "G" (in units of Pa/K) from the Schmidt-Appleman criterion.
		// This implements Equation 11 from Schumann 2012.
		// 
		// The inputs are as follows
		//	- p_atm_Pa is the atmospheric Pressure in Pascals
		//	- EI_H20 is the H20 missions index of the fuel
		//	- Q_fuel_MJperkg is the fuel LCV in MJ/kg
		//	- eta_ov is the overall efficiency of the aircraft
		
		const double Q_fuel_Jperkg = Q_fuel_MJperkg * 1e6;
		const double cp_air_JperkgK = 1004; // From Schumann 2012
		const double M_ratio = 0.622; // From Schumann 2012

		return cp_air_JperkgK * p_atm_Pa * EI_H20 / 
			M_ratio / Q_fuel_Jperkg / (1 - eta_ov);
	}
}