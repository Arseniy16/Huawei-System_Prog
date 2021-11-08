//-------------------------------------------------------------------------------------
//! \file
//! \brief This library contains all necessary functions for this program 
//-------------------------------------------------------------------------------------

#ifndef _SOLVESQUARE_H_
#define _SOLVESQUARE_H_

//-----------------------------------------------------------------------------

//! This constant is necessary to compare value with Zero
#define MISTAKE 1e-6

//! This constant is necessary when Square equation has infinite roots
#define UNDEF -1

//! This constant is necessary when Square equation has \b NO_ROOTS
#define NO_ROOTS 0

//! This constant is necessary when Square equation has \b ONE_ROOT
#define ONE_ROOT 1

//! This constant is necessary when Square equation has \b TWO_ROOTS
#define TWO_ROOTS 2

//=============================================================================

/*! Verification on Zero coefficient.
	Compare with \b MISTAKE 

	\param [in] a 	Coefficient for estimating
	\return TRUE or FALSE
*/
int isZero (const double a);

/*!	Function to Input correct data for square equation  
	\param [in] ptr_a 	Pointer for coefficient a
	\param [in] ptr_b 	Pointer for coefficient b
	\param [in] ptr_c 	Pointer for coefficient c

*/
void InputData (double * a, double * b, double * c);

/*! Function to Solve Linear equation

	\param [in] b   Coefficient
	\param [in] c   Coefficient
	\param [out] x   Pointer to the root

	\return Count of roots
*/
int SolveLinear (const double a, const double b, double * x);

/*! Function to Solve Square equation

	\param [in] a   Coefficient
	\param [in] b   Coefficient
	\param [in] c   Coefficient
	\param [out] x1   Pointer to the first root
	\param [out] x2   Pointer to the second root

	\return Count of roots
*/
int SolveSquare (const double a, const double b, const double c, double * x1, double * x2);

#endif // _SOLVESQUARE_H_