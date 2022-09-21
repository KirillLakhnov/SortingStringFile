#ifndef FILE_PROCESSING_H
#define FILE_PROCESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

enum ERROR_FILE_PROCESSING {
    GOOD_WORKING       = 0,
    ERROR_MEMMORY      = 1,
    ERROR_READING_FILE = 2,
    ERROR_FILE_OPEN    = 3,
    ERROR_FILE_CLOSE   = 4,
    ERROR_FSEEK        = 5,
    ERROR_FTELL        = 6,
    ERROR_FPRINTF      = 7,
};

struct Text {
    size_t size_file;
    char*  file_buffer;
    char** p_array_pointer;
    int    number_line_text;
};

struct FileInfo {
    FILE* text;
    const char* file_name;
};

int SizeFile (FILE* text, size_t* size_file);

int NumberLineText (char* file_buffer, size_t size_file);

int BufferTxtFileCreate (size_t* size_file, int* number_line_text, char** file_buffer, const char* file_name);

void BufferTransferPointer (char** p_array_pointer, char* file_buffer, size_t size_file);

void ArrayTransferFile (char** p_array_pointer, FILE* text, const int number_string_text);

int PutcTextOnFile (char** p_array_pointer, int number_line_text, char* file_buffer);

void FreeBuffer (char** p_array_pointer, char* file_buffer);

#endif //FILE_PROCESSING_H
