//-------------------------------------------------------------------------------------
//! \file
//! \brief This file contains all necessary functions to solve the square eqution 
//-------------------------------------------------------------------------------------

#include "main.h"

//--------------------------------------------------------------------------

void InputData (double * ptr_a, double * ptr_b, double * ptr_c)
{
    /* Verification on true pointers  */
    assert(ptr_a != NULL);
    assert(ptr_b != NULL);
    assert(ptr_c != NULL); 
    assert(ptr_a != ptr_b);
    assert(ptr_a != ptr_c);
    assert(ptr_b != ptr_c);
    
    int counts = scanf("%lg %lg %lg", ptr_a, ptr_b, ptr_c);
    
    int x = 0;

    while (counts != 3)
    {
        printf ("\n# Please enter a, b, c in correct input format : ");

        while ((x = getchar()) != '\n');

        counts = scanf("%lg %lg %lg", ptr_a, ptr_b, ptr_c);
    }
}

//----------------------------------------------------------------------------

int SolveLinear (const double b, const double c, double * x)
{
    /* Verification on finite coefs */
    assert(isfinite(b));
    assert(isfinite(c));

    /* Verification on true pointers  */
    assert(x != NULL);

    if (isZero(b))
    {
        return (isZero(c)) ? UNDEF : NO_ROOTS;
    }
    else /* if (b != 0) */
    {
        if (isZero(c)) *x = 0;

        else *x = -c / b;

        return ONE_ROOT;
    }
}

//-----------------------------------------------------------------------------

int SolveSquare (const double a, const double b, const double c, double* x1, double* x2)
{
    /* Verification on finite coefs */
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));

    /* Verification on true pointers  */
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (isZero(a))
    {
        SolveLinear(b, c, x1);
    }
    else    /* if (a != 0) */
    {
        double d = b*b - 4*a*c;

        if (isZero(d))
        {
            if (isZero(b)) *x1 = 0;

            else *x1 = -b / (2*a);

            return ONE_ROOT;
        }
        else if (d > 0)
        {
            double sqr = sqrt(d);

            *x1 = (-b - sqr) / (2*a);
            *x2 = (-b + sqr) / (2*a);

            return TWO_ROOTS;
        }
        else    /* if(d < 0) */
            return NO_ROOTS;
    }

}

//-----------------------------------------------------------------------------

/*  Verification on Zero coef */

int isZero (const double a)
{
    /* Verification on true pointers  */
    assert(isfinite(a));

    return (fabs(a) < MISTAKE);
}

//-----------------------------------------------------------------------------




