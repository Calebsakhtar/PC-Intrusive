// SA-Criterion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "headers/DetSATools.h"

int main()
{
	// At 23500 ft
	const double T_atm_C = -31.558;
	const double p_atm_Pa = 40128;
	const double EI_H20 = 1.23;
	const double Q_fuel_MJPerkg = 43.2;
	const double eta_ov = 0.25;
	
	const double G_PaPerK = DetSATools::compute_gradient_G(p_atm_Pa, EI_H20, Q_fuel_MJPerkg,
		eta_ov);
	const double T_LM_C = DetSATools::approximate_T_LM_C(G_PaPerK);
	const double U_LC = DetSATools::compute_U_LC(G_PaPerK, T_LM_C, T_atm_C);

	std::cout << U_LC;
	//.894369
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
