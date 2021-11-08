//-------------------------------------------------------------------------------------
//! \file
//! \brief This UnitTest-library allows to DEBUG program on UnitTests 
//-------------------------------------------------------------------------------------

#ifndef _UNITTEST_H_
#define _UNITTEST_H_

/*! \brief This structure input for \b INPUT_dataset for UnitTests
	\param [in] a 	Coefficient
	\param [in] b 	Coefficient
	\param [in] c 	Coefficient
*/

struct input
{
    double a;
    double b;
    double c;
};

/*! \brief This structure output for \b OUTPUT_dataset for UnitTests
	\param [out] res	Count of roots
	\param [out] x1		First root
	\param [out] x2		Second root
*/

struct output
{
    int res;
    double x1;
    double x2;
};

/*! This function cuts value to 3 characters for using in UnitTests to compare with double values
	\param [in] x 	x-value to compare 
	\return А truncated value
*/

double compare_value(const double x);

/*! This function verify program on \b UnitTests \n
*	Test will passed if \b output data will correspond real roots \n
*	In the end of UnitTests will show \b number_of_passed_tests and \b number_of_not_passed_tests   
*/

void UnitTest();

#endif // _UNITTEST_H_


