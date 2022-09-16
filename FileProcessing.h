#ifndef FILE_PROCESSING_H
#define FILE_PROCESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

const int STR_LEN_MAX = 1000;
const size_t  STR_NUM = 5000;

char* Gets (FILE* text);

int FileTransferArray (FILE* text, char** p_array_pointer);

//int FileTransferArrayPlus (FILE* text, char** p_array_pointer);

void ArrayTransferFile (char** p_array_pointer, FILE* text, const int number_string_text);

#endif //FILE_PROCESSING_H
