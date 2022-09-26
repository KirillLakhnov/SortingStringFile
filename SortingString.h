#ifndef SORTING_STRING_H
#define SORTING_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
/**
 * @brief Swap - a function that makes a swap of two elements.
 * 
 * @param obj1 - swap object
 * @param obj2 - swap object
 * @param size_element - size of the transmitted element.
 */
void Swap (void* obj1, void* obj2, size_t size_element);

/**
 * @brief BubleSortCharPointStruct - bubble sorting of an array of structures.
 * 
 * @param line_info - pointer to an array of structures
 * @param number_line_text - number of array elements
 * @param compare - a function comparing two elements of an array
 */
void BubleSortCharPointStruct (struct Line* line_info, const int number_line_text, int (*compare) (const void* ,const void*));

/**
 * @brief QuickSortCharPointStruct - quick sorting of an array of structures.
 * 
 * @param line_info - pointer to an array of structures
 * @param number_line_text - number of array elements
 * @param compare - a function comparing two elements of an array
 */
void QuickSortCharPointStruct (struct Line* line_info, int number_line_text, int (*compare) (const void* ,const void*));

/**
 * @brief QuickSortVoid - quick sorting for different data types
 * 
 * @param array - pointer to an array
 * @param size_array - array size
 * @param size_type - size of the array data type
 * @param compare - a function comparing two elements of an array
 */
void QuickSortVoid (void* array, size_t size_array, size_t size_type, int (*compare) (const void* ,const void*));

/**
 * @brief ComparisonString - compares strings by letters only.
 * 
 * @param struct_line1 - pointer to the comparison element
 * @param struct_line2 - pointer to the comparison element
 * @return comparison result
 */
int ComparisonString (const void* struct_line1, const void* struct_line2);

/**
 * @brief ComparisonStringEnd - compares strings only by letters from the end.
 * 
 * @param struct_line1 - pointer to the comparison element
 * @param struct_line2 - pointer to the comparison element
 * @return comparison result
 */
int ComparisonStringEnd (const void* struct_line1, const void* struct_line2);

#endif //SORTING_STRING_H