#ifndef SORTING_STRING_H
#define SORTING_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

void BubleSortCharPointStruct (struct LinePointerLength* line_info, const int number_line_text, int (*compare) (const void* ,const void*));

void QuickSortCharPointStruct (struct LinePointerLength* line_info, int number_line_text, int (*compare) (const void* ,const void*));

void QuickSortVoid (void* array, size_t size_array, size_t size_type, int (*compare) (const void* ,const void*));

/**
 * @brief ComparisonString - compares lines considering only letters from left to right.
 * 
 * @param str1 - pointer to the line being compared.
 * @param str2 - pointer to the line being compared.
 * @return comparison result.
 */
int ComparisonString (const void* str1, const void* str2);

/**
 * @brief ComparisonStringEnd - compares lines considering only letters from right to left.
 * 
 * @param str1 - pointer to the line being compared.
 * @param str2 - pointer to the line being compared.
 * @return comparison result.
 */
int ComparisonStringEnd (const void* str1, const void* str2);

#endif //SORTING_STRING_H