#ifndef SORTING_STRING_H
#define SORTING_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

int LineLen (const char* str);

void BubleSort (char** p_array_pointer, const int number_string_text, int (*compare) (const void* ,const void*));

void QuickSort (char** p_array_pointer, int number_line_text, int (*compare) (const void* ,const void*));

int ComparisonString (const void* str1, const void* str2);

int ComparisonStringEnd (const void* str1, const void* str2);

#endif //SORTING_STRING_H