/**
 * @file       main.cpp
 * @brief      This is the main file of the program implementation.
 * 
 * @author     Arseniy Shtunder MIPT
 * @date       2021
 */
#include "onegin.h"

int main (int argc, const char * argv[])
{   
    #ifdef UnitTest
        test_prog();
    #else
    
    const char * input_file  = "source/hamlet.txt";
    const char * output_file = "source/output.txt";
    const char * regime      = "direct";

    get_file_path(&input_file, &output_file, argc, argv);

    if (argc > 3) regime = argv[3];

    sort_file(input_file, output_file, regime);
     
    #endif //UnitTest

    return 0;
}
