namespace DetSATools {

	// Calculates the liquid saturation pressure "p_sat_liq" (in units of Pa) 
	// from the Schmidt-Appleman criterion. The equation can be found in Schumann 2012.
	// 
	// The inputs are as follows
	//	- T is the absolute temperature in Kelvin
	double compute_p_sat_liq(const double T_K);

	// Calculates the ice saturation pressure "p_sat_ice" (in units of Pa)
	// from the Schmidt-Appleman criterion. The equation can be found in Schumann 2012.
	// 
	// The inputs are as follows
	//	- T_K is the absolute temperature in Kelvin
	double compute_p_sat_ice(const double T_K);

	// Calculates the gradient "G" (in units of Pa/K) from the Schmidt-Appleman criterion.
	// The equation can be found in Schumann 2012.
	// 
	// The inputs are as follows
	//	- p_atm_Pa is the atmospheric Pressure in Pascals
	//	- EI_H20 is the H20 missions index of the fuel
	//	- Q_fuel_MJPerkg is the fuel LCV in MJ/kg
	//	- eta_ov is the overall efficiency of the aircraft
	double compute_gradient_G(const double p_atm_Pa, const double EI_H20,
		const double Q_fuel_MJPerkg, const double eta_ov);

	// Calculates the tangent temperature "T_LM" (in degrees Celsius) from the Schmidt-Appleman criterion.
	// This implements Equation 10 from Schumann 2012.
	// 
	// The inputs are as follows:
	//	- G_PaPerK is the gradient in units of Pa/Kg
	double approximate_T_LM_C(const double G_PaPerK);

}
