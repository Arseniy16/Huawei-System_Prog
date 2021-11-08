/**
 * @file       unit_test.cpp
 * @brief      This file is required for unit testing.
 * 
 * @author     Arseniy Shtunder MIPT
 * @date       2021
 */
#include "onegin.h"

/**
 * @var        MEM_SIZE
 * @brief      The size of memory for the buffer
 * 
 * The size of memory that needs to be allocated to write the contents of the file to the buffer
 * MEM_SIZE = max count of strings          
 */

/**
 * @var        LINE_SIZE
 * @brief      The max size of a string
 * 
 * LINE_SIZE = maximum count of characters in a string
 */

const int MEM_SIZE  = 5000;
const int LINE_SIZE = 200;

int cmp_texts (FILE * output, FILE * test)
{
    ASSERT(output);
    ASSERT(test);

    char ** str_output = (char **) calloc(MEM_SIZE, sizeof(char *));
    char ** str_test = (char **) calloc(MEM_SIZE, sizeof(char *));

    ASSERT(str_output);
    ASSERT(str_test);

    for (size_t i = 0; i < MEM_SIZE; ++i)
    {
        str_output[i] = (char *) calloc(LINE_SIZE, sizeof(char));
        str_test[i] = (char *) calloc(LINE_SIZE, sizeof(char));

        ASSERT(str_output[i]);
        ASSERT(str_test[i]);
    }

    size_t num_lines1 = 0;
    size_t num_lines2 = 0;
   
    while (fgets(str_output[num_lines1++], LINE_SIZE, output) && num_lines1 < MEM_SIZE);
    while (fgets(str_test[num_lines2++], LINE_SIZE, test) && num_lines2 < MEM_SIZE);

    num_lines1--;
    num_lines2--;

    if (num_lines1 == num_lines2)
    {
        for (size_t i = 0; i < num_lines1; ++i)
        {
            if (strcmp(str_test[i], str_output[i]) != 0)
                return -1;
        }

        for (size_t i = 0; i < MEM_SIZE; ++i)
        {
            free(str_output[i]);
            free(str_test[i]);
        }

        free(str_test);
        free(str_output);

        return 0;
    }
    else
        return -1;
}

/**
 * @brief      Test the file.
 * 
 * It compares output file and test file. 
 *
 * @param      num   The number of test file
 *
 */
#define TEST_FILE(num)                                                  \
    test_input  = "tests_input/test_input"#num".txt";                   \
    prog_output = "result/prog_output"#num".txt";                       \
    test_output = "tests_output/test_output"#num".txt";                 \
                                                                        \
    output = fopen(prog_output, "w+");                                  \
    test = fopen(test_output, "r");                                     \
                                                                        \
    ASSERT(output);                                                     \
    ASSERT(test);                                                       \
                                                                        \
    sort_file(test_input, prog_output, "direct");                       \
                                                                        \
    if (cmp_texts(output, test) == 0)                                   \
    {                                                                   \
        printf("TEST"#num" : PASSED\n");                                \
        count_passed++;                                                 \
    }                                                                   \
    else                                                                \
        printf("TEST"#num" : FAILED\n");                                \
                                                                        \
    fclose(test);                                                       \
    fclose(output);                                                     \

void test_prog ()
{
    const char * test_input  = nullptr;
    const char * prog_output = nullptr;
    const char * test_output = nullptr;

    FILE * output = nullptr;
    FILE * test   = nullptr;

    static int count_passed = 0;

    TEST_FILE(1);
    TEST_FILE(2);
    TEST_FILE(3);
    TEST_FILE(4);
    TEST_FILE(5);

    if (count_passed == 5)
    {    
        printf("---------------WELL DONE----------------\n");
        printf("//-------ALL TESTS ARE PASSED---------//\n");
    }
    else
    {
        printf("--------------NOT GOOD-------------------\n");
        printf("--------NOT ALL TESTS ARE PASSED---------\n");
    }
}