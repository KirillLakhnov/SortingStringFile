#ifndef SORTING_STRING_H
#define SORTING_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

const int DIFFERENCE_UPPER_LOWER_LETTERS = 32;

void SortingStringBuble (char** p_array_pointer, const int number_string_text);

void SortingStringBubleEnd (char** p_array_pointer, const int number_string_text);

void BubleSort (char** p_array_pointer, const int number_string_text, int (*compare) (const void* ,const void*));

int ComparisonString (const void* str1, const void* str2);

int ComparisonStringEnd (const void* str1, const void* str2);

//void BubleSortPlus (void* p_array, size_t number, size_t size_type, int (*compare) (const void* ,const void*));

//void QuickSort (char* p_array, int number_string_text, int (*compare) (const void* ,const void*));

#endif //SORTING_STRING_H