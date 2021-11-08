/**
 * @file       onegin.cpp
 * @brief      This file has function definitions for the program implementation.
 * 
 * @author     Arseniy Shtunder MIPT
 * @date       2021
 */
#include "onegin.h"

int Ctor (File * file, Strings * lines, const char * input_file)
{
    FILE * input = fopen(input_file, "r");
    if (input == nullptr)
    {
        perror("ERROR to open input_file");
        return -1;
    }

    size_t len_buf = sizeof_file(input_file);
    if (len_buf == 0)
    {
        perror("The input file is empty");
        return -1;
    }

    char * buf = (char *)calloc(len_buf, sizeof(char));
    if (buf == nullptr)
    {
        perror("ERROR to allocate memory for buf");
        return -1;
    }

    fread(buf, sizeof(char), len_buf, input);

    fclose(input);
    
    size_t lines_file = lines_of_file(buf, len_buf);
        
    str_t * strings = (str_t *) calloc(lines_file, sizeof(str_t));
    if (strings == nullptr)
    {
        perror("ERROR to allocate memory for strings");
        return -1;
    }
    
    file->buf = buf;
    file->len_buf = len_buf;
    lines->strings = strings; 
    lines->count_str = lines_file;
    
    return 0;
}

int Dtor (Strings * strings, File * file)
{
    free(strings);
    free(file);

    return 0;
}

int get_file_path (const char ** input_file, const char ** output_file, int argc, const char * argv[])
{
    ASSERT(input_file);
    ASSERT(output_file);
    ASSERT(argv);

    if (argc >= 2)
    {
        *input_file = argv[1];

        if (argc > 2)   
            *output_file = argv[2];        
    }

    return 0;
}

size_t sizeof_file (const char * file_name)
{
    ASSERT(file_name);

    struct stat stbuf;
    stat(file_name, &stbuf);

    return stbuf.st_size;
}

size_t lines_of_file (char * buf, size_t len_buf)
{
    ASSERT(buf);

    size_t lines_file = 0;

    for (size_t i = 0 ; i < len_buf; i++)
        if (buf[i] == '\n')
            lines_file++;

    return ++lines_file;
}

int put_to_file (const char * output_file, str_t * strings, size_t count_str)
{
    ASSERT(output_file);
    ASSERT(strings);

    FILE * output = fopen(output_file, "w");
    if (output == nullptr)
    {
        perror("ERROR to write to output_file");
        return -1;
    }

    for(size_t num = 0; num < count_str; num++)
    {
        for(size_t i = 0; i < strings[num].len_str; i++)
            fprintf(output, "%c", strings[num].str[i]);
        fprintf(output, "\n");
    }

    fclose(output);

    return 0;
}

int char_cmp (const char a, const char b)
{
    if (toupper(a) == toupper(b)) return EQUAL;

    else if (toupper(a) > toupper(b)) return GREATER;

    else return LESS;
}

void swap (str_t * strings, size_t left, size_t right)
{
    ASSERT(strings);

    char * tmp_str = strings[left].str;
    
    strings[left].str = strings[right].str;
    strings[right].str = tmp_str;

    size_t length = strings[left].len_str;

    strings[left].len_str = strings[right].len_str;
    strings[right].len_str = length;
}

int cmp_direct (const void * string1, const void * string2)
{
    ASSERT(string1);
    ASSERT(string2);

    size_t i = 0;
    size_t j = 0;
    
    while ((i < ((str_t *)string1)->len_str) && (j < ((str_t *)string2)->len_str))
    {        
        while (!isalpha(((str_t *)string1)->str[i])) 
        {
            i++;
            if (i >= ((str_t *)string1)->len_str) break;
        }

        while (!isalpha(((str_t *)string2)->str[j])) 
        {
            j++;
            if (j >= ((str_t *)string2)->len_str) break;
        }

        if ((i >= ((str_t *)string1)->len_str) || (j >= ((str_t *)string2)->len_str)) break;

        if (char_cmp(((str_t *)string1)->str[i], ((str_t *)string2)->str[j]) == EQUAL)
        {
            i++;
            j++;
        }    
        else
        {
            return char_cmp(((str_t *)string1)->str[i], ((str_t *)string2)->str[j]);            
        }     
    }
        
    return ((str_t *)string1)->len_str - ((str_t *)string2)->len_str;
}

int cmp_reverse (const void * string1, const void * string2)
{
    ASSERT(string1);
    ASSERT(string2);

    return -(cmp_direct(string1, string2));
}

int cmp_rhyme (const void * string1, const void * string2)
{
    ASSERT(string1);
    ASSERT(string2);

    int len1 = ((str_t *)string1)->len_str - 1;
    int len2 = ((str_t *)string2)->len_str - 1;

    while (len1 >= 0 && len2 >= 0)
    {
        while (!isalpha(((str_t *)string1)->str[len1])) 
        {
            len1--;
            if (len1 < 0) break;
        }

        while (!isalpha(((str_t *)string2)->str[len2])) 
        {
            len2--;
            if (len2 < 0) break;
        }

        if ((len1 < 0) || (len2 < 0)) break;

        if (char_cmp(((str_t *)string1)->str[len1], ((str_t *)string2)->str[len2]) == EQUAL)
        {
            len1--;
            len2--;
        }
        else
            return char_cmp(((str_t *)string1)->str[len1], ((str_t *)string2)->str[len2]);

    }

    return ((str_t *)string1)->len_str - ((str_t *)string2)->len_str;
}

int record_str (str_t * strings, char * buf, size_t len_buf)
{
    ASSERT(strings);
    ASSERT(buf);

    size_t count_char = 0;
    size_t count_str = 0;

    while (true)
    {
        while (true)
        {
            if (count_char >= len_buf) break;
            else if (isspace(buf[count_char])) count_char++;
            else break;
        }

        if (count_char >= len_buf) break;

        strings[count_str].str = &buf[count_char];

        strings[count_str].len_str = count_char;

        while (buf[count_char] != '\n')
        {
            if (count_char >= len_buf) break;
            count_char++;
        }

        strings[count_str].len_str = count_char - strings[count_str].len_str;

        count_str++;
        count_char++;
    }

    return count_str;
}

void qsorting (str_t * strings, int left, int right, int (* str_cmp) (const void *, const void *))
{
    ASSERT(strings);
    ASSERT(str_cmp);

    if (left >= right)
        return;

    int last = left;

    swap(strings, left, left + (right - left) / 2);

    for (int pos = left + 1; pos <= right; ++pos)
        if (str_cmp((const void *)&strings[pos], (const void *)&strings[left]) < 0)
            swap(strings, ++last, pos);

    swap(strings, left, last);

    qsorting(strings, left, last - 1, str_cmp);
    qsorting(strings, last + 1, right, str_cmp);
}

int (*choose_cmp(const char *regime))(const void *, const void *)
{
    ASSERT(regime);

    if (!strcmp(regime, "reverse"))
        return cmp_reverse;
    else if (!strcmp(regime, "rhyme"))
        return cmp_rhyme;
    else
        return cmp_direct;
}

void sort_file (const char * input_file, const char * output_file, const char * regime)
{
    ASSERT(input_file);
    ASSERT(output_file);
    ASSERT(regime);

    File * file = (File *)calloc(1, sizeof(File));
    Strings * lines = (Strings *)calloc(1, sizeof(Strings));

    ASSERT(file);
    ASSERT(lines); 

    PRINT("//-------------------------------------//\n");
    PRINT("//LOG_INFO about input and output files//\n");
    PRINT("//-------------------------------------//\n");

    PRINT_ARG("Name of input_file = %s\n", input_file);
    PRINT_ARG("Name of output_file = %s\n", output_file);

    int (*str_cmp)(const void *, const void *) = choose_cmp(regime);
    
    if (!strcmp(regime, "reverse"))
        PRINT("Regime: cmp_reverse\n");
    else if (!strcmp(regime, "rhyme"))
        PRINT("Regime: cmp_rhyme\n");
    else
        PRINT("Regime: cmp_direct\n");

    PRINT("-----------------------------------\n");
/*    
    if (Ctor(file, lines, input_file) < 0)
        exit(EXIT_FAILURE); //return -1;
*/
    Ctor(file, lines, input_file);

    PRINT_ARG("Size input_file = %ld\n", file->len_buf); 
    PRINT_ARG("Count lines of input_file = %ld\n", lines->count_str);

    lines->count_str = record_str(lines->strings, file->buf, file->len_buf);

    PRINT_ARG("Count lines of output_file = %ld\n", lines->count_str);
    
    qsorting(lines->strings, 0, lines->count_str-1, str_cmp);

    PRINT("-------------------good-------------------------\n");
/*
    if (put_to_file(output_file, lines->strings, lines->count_str) < 0)
        exit(EXIT_FAILURE); //return -1;
*/
    put_to_file(output_file, lines->strings, lines->count_str);

    PRINT_ARG("Size output_file = %ld\n", sizeof_file(output_file));

    Dtor(lines, file);
}
