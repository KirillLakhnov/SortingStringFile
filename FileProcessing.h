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
    GOOD_WORKING         = 0,
    ERROR_MEMMORY        = 1,
    ERROR_READING_FILE   = 2,
    ERROR_FILE_OPEN      = 3,
    ERROR_FILE_CLOSE     = 4,
    ERROR_FSEEK          = 5,
    ERROR_FTELL          = 6,
    ERROR_FPRINTF        = 7,
    ERROR_FPUTS          = 8,
    ERROR_BUFFER_CREATER = 9,
};

/**
 * @brief Text - the structure contains variables related to the original text file and buffer.
 * 
 */
struct Text {
    char* file_buffer;
    size_t size_buffer;
    struct Line* line_info;
    int number_line_text;
};

/**
 * @brief FileInfo - a structure containing the name of the original file and its size
 * 
 */
struct FileInfo {
    const char* file_name;
    size_t size_file;
};

/**
 * @brief Line - a structure containing a pointer to a string and its length.
 * 
 */
struct Line {
    char* pointer_line;
    size_t length;
};

/**
 * @brief SizeFile - finds the file size in bytes.
 * 
 * @param text - text file.
 * @param text_info - pointer to the structure that contains a variable to which the file size is passed.
 * @return the result of the function execution (0 - successful execution, more than 0 - error)
 */
int SizeFile (FILE* text, struct Text* text_info);

/**
 * @brief NumberLineText - counts the number of rows and replaces '\n' with '\0'
 * 
 * @param text_info - pointer to the structure containing the file size and a pointer to the buffer of this file.
 * @return number of rows
 */
int NumberLineText (struct Text* text_info);

/**
 * @brief BufferCreater - creates a file buffer.
 * 
 * @param file_info - pointer to the structure containing basic data about a file.
 * @param text_info - pointer to the structure containing the file size and a pointer to the buffer of this file.
 * @return the result of the function execution (0 - successful execution, more than 0 - error).
 */

int BufferCreater (struct FileInfo* file_info, struct Text* text_info);
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

/** 
 * @brief ArraySortTransferFile - outputs sorted text to a file
 * 
 * @param text_end - the file to which the text is output
 * @param text_info - pointer to the structure containing data about a text file buffer and an array of pointers.
 * @return the result of the function execution (0 - successful execution, more than 0 - error).
 */
int ArraySortTransferFile (FILE* text_end, struct Text* text_info);

/**
 * @brief ArrayTransferFile - outputs the original text to a file.
 * 
 * @param text_end - the file to which the text is output
 * @param text_info - pointer to the structure containing data about a text file buffer and an array of pointers.
 * @return the result of the function execution (0 - successful execution, more than 0 - error).
 */
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
