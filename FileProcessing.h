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
};

struct Text {
    size_t size_file;
    char*  file_buffer;
    char** p_array_pointer;
    int    number_line_text;
};

struct FileInfo {
    FILE* text;
    char* file_name;
};

int SizeFile (FILE* text, size_t* size_file);

int NumberLineText (struct Text* text);

int BufferTxtFileCreate (size_t* size_file, int* number_line_text, char** file_buffer, char* file_name);

void BufferArrayCompletion(char** file_buffer_array, char* file_buffer, size_t size_file, int number_line_text);

void BufferTransferFile (char** file_buffer_array, char** p_array_pointer, int number_line_text);

void ArrayTransferFile (char** p_array_pointer, FILE* text, const int number_string_text);

#endif //FILE_PROCESSING_H
