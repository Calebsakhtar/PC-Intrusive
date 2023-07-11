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

	double compute_gradient_G(const double p_atm_Pa, const double EI_H20, const double Q_fuel_MJPerkg,
		const double eta_ov) {
		// Calculates the gradient "G" (in units of Pa/K) from the Schmidt-Appleman criterion.
		// This implements Equation 11 from Schumann 2012.
		// 
		// The inputs are as follows
		//	- p_atm_Pa is the atmospheric Pressure in Pascals
		//	- EI_H20 is the H20 missions index of the fuel
		//	- Q_fuel_MJPerkg is the fuel LCV in MJ/kg
		//	- eta_ov is the overall efficiency of the aircraft
		
		const double Q_fuel_JPerkg = Q_fuel_MJPerkg * 1e6;
		const double cp_air_JPerkgK = 1004; // From Schumann 2012
		const double M_ratio = 0.622; // From Schumann 2012

		return cp_air_JPerkgK * p_atm_Pa * EI_H20 / 
			M_ratio / Q_fuel_JPerkg / (1 - eta_ov);
	}

	double approximate_T_LM_C(const double G_PaPerK) {
		// Calculates the tangent temperature "T_LM" (in degrees Celsius) from the Schmidt-Appleman criterion.
		// This implements Equation 10 from Schumann 2012.
		// 
		// The inputs are as follows
		//	- G_PaPerK is the gradient in units of Pa/Kg

		const double a = -46.46;
		const double b = 9.43;
		const double c = -0.053;
		const double d = 0.72;

		return a + b * log(G_PaPerK + c) + d * pow(log(G_PaPerK + c), 2);
	}

	double compute_U_LC(const double G_PaPerK, const double T_LM_C,	const double T_atm_C) {
		// Calculates the critical relative humidity "U_LC" from the Schmidt-Appleman criterion.
		// This implements Equation 12 from Schumann 2012.
		// 
		// The inputs are as follows
		//	- G_PaPerK is the gradient in units of Pa/Kg
		//  - T_LM_C is the tangent temperature in degrees celsius
		//  - T_atm_C is the atmospheric temperature in degrees celsius

		return (G_PaPerK * (T_atm_C - T_LM_C) + compute_p_sat_liq(T_LM_C - 273)) / compute_p_sat_liq(T_atm_C - 273);
	}
}
