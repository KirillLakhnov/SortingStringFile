#ifndef SORTING_STRING_H
#define SORTING_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

const int DIFFERENCE_UPPER_LOWER_LETTERS = 32;

char* Gets (FILE* text);

void SortingString (char** p_array_pointer, int number_string_text);

void SortingStringEnd (char** p_array_pointer, const int number_string_text);

int ComparisonString (char* str1, char* str2);

int ComparisonStringEnd (char* str1, char* str2);

#endif //SORTING_STRING_H