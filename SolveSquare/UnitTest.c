//-------------------------------------------------------------------------------------
//!\file
//!\brief This file contains function for testing program on UnitTests
//-------------------------------------------------------------------------------------

#include "main.h"

//-------------------------------------------------------------------------------------

// Get value to 3 characters for using in UnitTests to compare with double values

double compare_value (const double x1)
{
    return (int)(x1*1000)/1000.0 ;
}

//-------------------------------------------------------------------------------------

void UnitTest ()
{
    double x1 = 0.0, x2 = 0.0;
    int num_of_test_good = 0, num_of_test_bad = 0;

    //-----------------------------------------------------------------------------
    // input data for UnitTests
    // input data format: a b c - coefficients  

    struct input in[] =
    {
        1,       0,         0,

        1,       0,         1,

        1,       1,         1,

        0,       1,         1,

        0,       0,         1,

        4,       4,         1,

        0,       0,         0,

        0,       1,         0,

        1,       1,         0,

        2.42,    13.5,      12.6,

        -0.6,    4.32,      1.6,

        -19.78,  42.15,     -23.72,

        27.1,    -34.01,    72.21,

        -54.64,  -43.32,    1.59,

        4.01,    -47.67,    89.76,

        -42.09,  -120.98,   34.38,

        -1.0003, 0.0000056, 2.0045,

        71.69,   -56.45,    88.58,

        -1,      0.026,     -0.000005,

        -1,      -32,       -0.00005,

        -1,      0,         0,

        -1,      -1,        0,

        -1,      -1,        -1,

        0,       -1,        0,

        0,       0,         -1,

        0,       -1,        -1,

        -1,      0,         -1
    };

    //-----------------------------------------------------------------------------
    
    /* output data for UnitTests
	   where 'x' means no root( 'x' need to follow the structure)   */

    struct output out[] =
    {
        ONE_ROOT,   0,      'x',

        NO_ROOTS,   'x',    'x',

        NO_ROOTS,   'x',    'x',

        ONE_ROOT,   -1,     'x',

        NO_ROOTS,   'x',    'x',

        ONE_ROOT,   -0.5,   'x',

        UNDEF,      'x',    'x',

        ONE_ROOT,   0,      'x',

        TWO_ROOTS,   -1,     0,

        TWO_ROOTS,  -4.393,  -1.185,

        TWO_ROOTS,  7.553,   -0.353,

        NO_ROOTS,   'x',    'x',

        NO_ROOTS,   'x',    'x',

        TWO_ROOTS,  0.035,  -0.827,

        TWO_ROOTS,  2.345,  9.541,

        TWO_ROOTS,  0.260,  -3.134,

        TWO_ROOTS,  1.415,  -1.415,

        NO_ROOTS,   'x',   'x',

        TWO_ROOTS,  0.025,  0,

        TWO_ROOTS,  0,      -31.999,

        ONE_ROOT,   0,      'x',

        TWO_ROOTS,  0,      -1,

        NO_ROOTS,   'x',    'x',

        ONE_ROOT,   0,      'x',

        NO_ROOTS,    'x',   'x',

        ONE_ROOT,   -1,     'x',

        NO_ROOTS,   'x',    'x'
    };

    //------------------------------------------------------------------------------

    for (int i = 1; i < 28; i++)
    {
        int state = SolveSquare(in[i].a, in[i].b, in[i].c, &x1, &x2);

        if (out[i].res == UNDEF)
        {
            if (state == UNDEF)
            {
                printf("Test_%d passed\n", i);
                num_of_test_good++;
            }
            else
            {
                printf("Test_%d failed\n", i);
                num_of_test_bad++;
            }
        }

        if (out[i].res == NO_ROOTS)
        {
            if (state == NO_ROOTS)
            {
                printf("Test_%d passed\n", i);
                num_of_test_good++;
            }
            else
            {
                printf("Test_%d failed\n", i);
                num_of_test_bad++;
            }
        }

        if (out[i].res == ONE_ROOT)
        {
            if ((state == ONE_ROOT) && (compare_value(x1) == out[i].x1))
            {
                printf("Test_%d passed\n", i);
                num_of_test_good++;
            }
            else
            {
                printf("Test_%d failed\n", i);
                num_of_test_bad++;
            }
        }

        if (out[i].res == TWO_ROOTS)
        {
            if ((state == TWO_ROOTS) && (compare_value(x1) == out[i].x1) && (compare_value(x2) == out[i].x2))
            {
                printf("Test_%d passed\n", i);
                num_of_test_good++;
            }
            else
            {
                printf("Test_%d failed\n", i);
                num_of_test_bad++;
            }
        }
    }

    printf("\nCount of passed tests = %d\n", num_of_test_good);

    printf("Count of not passed tests = %d\n", num_of_test_bad);
}

//---------------------------------------------------------------------------------

