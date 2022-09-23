#ifndef FILE_PROCESSING_H
#define FILE_PROCESSING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

/**
 * @brief ERROR_FILE_PROCESSING - the result of some functions that is issued in case of an error or successful execution.
 */
enum ERROR_FILE_PROCESSING {
    GOOD_WORKING       = 0,
    ERROR_MEMMORY      = 1,
    ERROR_READING_FILE = 2,
    ERROR_FILE_OPEN    = 3,
    ERROR_FILE_CLOSE   = 4,
    ERROR_FSEEK        = 5,
    ERROR_FTELL        = 6,
    ERROR_FPRINTF      = 7,
    ERROR_FPUTS        = 8,
};

struct Text {
    size_t size_file;
    char* file_buffer;
    int number_line_text;
    struct LinePointerLength* line_info;
};

struct FileInfo {
    FILE* text;
    const char* file_name;
};

struct LinePointerLength {
    char* pointer_line;
    int length;
};

/**
 * @brief SizeFile - finds the file size in bytes.
 * 
 * @param file_info - pointer to the structure containing data about a file.
 * @param text_info - pointer to the structure that contains a variable to which the file size is passed.
 * @return the result of the function execution (0 - successful execution, more than 0 - error)
 */
int SizeFile (struct FileInfo* file_info, struct Text* text_info);

int NumberLineText (struct Text* text_info);

/**
 * @brief TextCtor - creates a text file buffer.
 * 
 * @param file_info - pointer to the structure containing basic data about a file.
 * @param text_info - pointer to the structure containing the file size and a pointer to the buffer of this file.
 * @return the result of the function execution (0 - successful execution, more than 0 - error).
 */
int TextCtor (struct FileInfo* file_info, struct Text* text_info);

/**
 * @brief BufferTransferPointer - passes the data on the line from the file buffer to the pointer array.
 * 
 * @param text_info - pointer to the structure containing data about a text file buffer and an array of pointers.
 */
void BufferTransferPointer (struct Text* text_info);

int ArrayTransferFile (FILE* text_end, struct Text* text_info);

/**
 * @brief PutcTextOnFile - it comes out in a text file with three text options.
 * 
 * @param file_info - pointer to the structure containing basic data about a file.
 * @param text_info - a pointer to a structure containing data about the file buffer and an array of pointers to its lines.
 * @return the result of the function execution (0 - successful execution, more than 0 - error)
 */
int PutcTextOnFile (FILE* text_end, struct FileInfo* file_info, struct Text* text_info);

/**
 * @brief TextDtor - clears the buffer after using dynamic memory.
 * 
 * @param text_info - a pointer to a structure containing data about the file buffer and an array of pointers to its lines.
 */
void TextDtor (struct Text* text_info);

#endif //FILE_PROCESSING_H
