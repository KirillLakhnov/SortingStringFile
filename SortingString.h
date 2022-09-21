#ifndef SORTING_STRING_H
#define SORTING_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

/**
 * @brief LineLen - learns the length of the line.
 * 
 * @param str - pointer to the line.
 * @return line length in bytes.
 */
int LineLen (const char* str);

/**
 * @brief BubleSortCharPoint - sorts an array of pointers of type char with a bubble.
 * 
 * @param p_array_pointer - pointer to an array of pointers.
 * @param number_line_text - number of pointers in the array.
 * @param compare - pointer to function comparing lines.
 */
void BubleSortCharPoint (char** p_array_pointer, const int number_line_text, int (*compare) (const void* ,const void*));

/**
 * @brief QuickSortCharPoint - fast sorts an array of pointers of type char. 
 * 
 * @param p_array_pointer - pointer to an array of pointers.
 * @param number_line_text - number of pointers in the array.
 * @param compare - pointer to function comparing lines.
 */
void QuickSortCharPoint (char** p_array_pointer, int number_line_text, int (*compare) (const void* ,const void*));

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