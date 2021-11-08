/**
 * @file       onegin.h
 * @brief      This file has function declarations for the program implementation.
 *
 * @author     Arseniy Shtunder MIPT
 * @date       2021
 */
#ifndef _INCLUDE_ONEGIN_H_
#define _INCLUDE_ONEGIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

/**
 * @def        UnitTest
 * @brief      Activate UnitTest mode.
 */
//If you want to start unit test, uncomment #define Unittest. 

// #define UnitTest

/**
 * @def        PRINT_DEBUG
 * @brief      Activate PRINT_DEBUG mode
 */
#ifndef UnitTest
    #define PRINT_DEBUG
#endif 

/**
 * @def        DEBUG
 * @brief      Activate DEBUG mode
 */
#define DEBUG

/**
 * @def PRINT_ARG(string, value)
 * @brief      Prints with argument in debug regime.
 * 
 * If define PRINT_DEBUG, it uses printf(string, value), otherwise it does nothing.
 *  
 * @param      string  The string
 * @param      value   The value
 *
 */

/**
 * @def PRINT(string)
 * @brief      Prints without argument.
 * 
 * If define PRINT_DEBUG, it uses printf(string), otherwise it does nothing.
 * 
 * @param      string  The string
 *
 */

#ifdef PRINT_DEBUG
    #define PRINT_ARG(string, value) printf(string, value)
    #define PRINT(string) printf(string)
#else
    #define PRINT_ARG(string, value)
    #define PRINT(string)
#endif //PRINT_DEBUG

/**
 * @def ASSERT(exp)
 * @brief      Calls assert function.
 *
 * If define DEBUG, it uses assert(exp), otherwise it does nothing.
 * 
 * @param      exp   The expression
 *
 */

#ifdef DEBUG
    #define ASSERT(exp) assert(exp)
#else
    #define ASSERT(exp) 
#endif //DEBUG


const int EQUAL   =  0;
const int GREATER =  1;
const int LESS    = -1;

/** 
 * @brief      The structure of File.
 * 
 * This structure includes the pointer to buffer and the length of buffer.
 */
struct File
{
    char * buf; /** pointer to the buffer for writing file content */
    size_t len_buf; /** length of the buffer */
};

/**
 * @brief      The structure of string.
 * 
 * This structure includes pointer to string and the length of string.
 */
struct str_t
{
    char * str; /**< pointer to the string */
    size_t len_str; /**< length of the string */
};

/**
 * @brief      The structure of Strings.
 * 
 * This structure includes pointer to strings and the length of all strings in buffer.
 */
struct Strings
{
    str_t * strings; /**< pointer to strings which consist all content of file */
    size_t count_str; /**< count of strings */
};

/**
 * @brief      A Constructor.
 * 
 * This constructor allocates memory for buffer and for strings.
 * Then all information is written from the file to the buffer and each line from file goes to strings.
 *  
 * @param      file        The pointer to File
 * @param      lines       The pointer to Strings
 * @param      input_file  The input file
 *
 * @return     Upon succesful completion returns 0, otherwise returns -1.
 */
int Ctor (File * file, Strings * lines, const char * input_file);

/**
 * @brief      A Destructor.
 *
 * @param      strings  The pointer to Strings
 * @param      file     The pointer to File
 *
 * @return     Upon succesful completion returns 0, otherwise returns -1.
 */
int Dtor (Strings * strings, File * file);

/**
 * @brief      Gets the file path.
 * 
 * @param      input_file   The input file
 * @param      output_file  The output file
 * @param      argc         The count of arguments
 * @param      argv         The arguments array
 *
 * @return     if all is ok, returns 0.
 */
int get_file_path (const char ** input_file, const char ** output_file, int argc, const char * argv[]);

/**
 * @brief      Gets the size of file.
 *
 * @param      file_name  The name of file
 *
 * @return     the size of file.
 */
size_t sizeof_file (const char * file_name);

/**
 * @brief      Gets the count of file lines.
 *
 * @param      buf      The buffer
 * @param      len_buf  The length of buffer
 *
 * @return     the count of file lines.
 */
size_t lines_of_file (char * buf, size_t len_buf);

/**
 * @brief      Puts the result in the file.
 *
 * @param      output_file  The output file
 * @param      strings      The strings
 * @param      count_str    The count of strings
 *
 * @return     Upon succesful completion returns 0, otherwise returns -1.
 */
int put_to_file (const char * output_file, str_t * strings, size_t count_str);

/**
 * @brief      Compares two symbols with each other. 
 *
 * @param      a     symbol_1
 * @param      b     symbol_2
 *
 * @return     If greater - return 1, if equal - return 0, if less - return -1. 
 */
int char_cmp (const char a, const char b);

/**
 * @brief      Swaps two strings and their lengths respectively.
 *
 * @param      strings  The strings
 * @param      left     The left index of string
 * @param      right    The right index of string
 */
void swap (str_t * strings, size_t left, size_t right);

/**
 * @brief      The direct comparator.
 *
 * Сompares two strings in direct alphabetical order.
 * It comes letter by letter and removes unnecessary characters (digits, spaces, etc...).
 * If the characters of one line have ended, compares lengths of strings.
 * 
 * @param      string1  The string_1
 * @param      string2  The string_2
 *
 * @return     If greater - return 1, if equal - return 0, if less - return -1.
 */
int cmp_direct (const void * string1, const void * string2);

/**
 * @brief      The reverse comparator.
 *
 * Сompares two strings in reverse alphabetical order.
 * It comes letter by letter and removes unnecessary characters (digits, spaces, etc...).
 * If the characters of one line have ended, compares lengths of strings.
 * 
 * @param      string1  The string 1
 * @param      string2  The string 2
 *
 * @return     If greater - return -1, if equal - return 0, if less - return 1.
 *             
 */
int cmp_reverse (const void * string1, const void * string2);

/**
 * @brief      The rhyme comparator.
 *
 * Compares two strings in direct alphabetical order starting from the end of the strings.
 * So that it creates special rhyme.
 *  
 * @param      string1  The string_1
 * @param      string2  The string_2
 *
 * @return     If greater - return 1, if equal - return 0, if less - return -1.
 */
int cmp_rhyme (const void * string1, const void * string2);

/**
 * @brief      Records strings from the buffer.
 *
 * It records strings from the buffer and cleares unnecessary characters (digits, spaces, etc...).
 *  
 * @param      strings  The strings
 * @param      buf      The buffer
 * @param      len_buf  The length buffer
 *
 * @return     the count of recorded strings
 */
int record_str (str_t * strings, char * buf, size_t len_buf);

/**
 * @brief      The quick sort function.
 *
 * It sorts strings using the qsort algorithm.
 * 
 * @param      strings  The strings
 * @param      left     The left index of string
 * @param      right    The right index of string
 * @param      str_cmp  The string comparator
 */
void qsorting (str_t * strings, int left, int right, int (* str_cmp) (const void *, const void *));

/**
 * @brief      The pointer to function to choose the comparator.
 *
 * @param      regime  The regime of sorting
 *
 * @return     the comparator for sorting.
 */
int (*choose_comp(const char *regime))(const void *, const void *);

/**
 * @brief      Sorts the contents of the file.
 *
 * It's main function which use all functions.
 * It creates buf and strings.
 * Then uses the Constructor to allocate memory and sorts strings.
 * After that, put strings to the output_file and calls Destructor to free memory.
 * Also it uses some log info.
 *   
 * @param      input_file   The input file
 * @param      output_file  The output file
 * @param      regime       The regime of sorting
 */
void sort_file (const char * input_file, const char * output_file, const char * regime);

/**
 * @brief      Compares texts.
 *
 * It uses in unit_tests to compare the contents of files
 * @param      output  The output file
 * @param      test    The test file
 *
 * @return     If the comparison is successful, it returns 0, otherwise it returns -1.
 */
int cmp_texts (FILE * output, FILE * test);

/**
 * @brief      Test the program 
 * 
 * It tests program using test files and shows the information about the test
 */
void test_prog ();

#endif //_INCLUDE_ONEGIN_HPP_