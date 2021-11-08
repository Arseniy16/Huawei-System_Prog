//-------------------------------------------------------------------------------------
/*! \file
	\brief This program solve square equation
	\copyright Shtunder Arseniy
	
	If you want to start UnitTests, please, uncomment \b #define \b TEST
*/
//-------------------------------------------------------------------------------------

#include "main.h"

//---------------------------------------------------------------

//#define TEST

int main ()
{
    #ifdef TEST
        UnitTest();
    #else

    printf("# This is a square equation solver\n\n"
           "#(c) ShtunderMIPT 2020 \n\n");

    printf("# Please enter coefficients of equation: ax^2 + bx + c = 0\n");

    printf("# Correct input format: Ex: 2.3 5.1 3.9 \n\n");
    
    printf("# Enter a, b, c : ");

    double a = 0, b = 0, c = 0;

    InputData(&a, &b, &c);

    double x1 = 0, x2 = 0;
    int roots = SolveSquare(a, b, c, &x1, &x2);

    switch(roots)
    {
        case NO_ROOTS: printf("\nThere aren't any roots\n");
                break;

        case ONE_ROOT: printf("\nThis equation has one root: x = %lg\n", x1);
                break;

        case TWO_ROOTS: printf("\nThis equation has two roots: x1 = %lg, x2 = %lg\n", x1, x2);
                break;

        case UNDEF: printf("\nThis equation has any number as a root\n");
                break;

        default: printf("\nmain() ERROR: Roots = %d\n", roots);
                return 1;
    }

    #endif //TEST

    return 0;
}
