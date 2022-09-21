#include "FileProcessing.h"
#include "SortingString.h"

int SizeFile (FILE* text, size_t* size_file)
{
    if (fseek (text, 0, SEEK_END) != 0)
    {
        return ERROR_FSEEK;
    }

    *size_file = ftell (text);
    if (!(*size_file))
    {
        return ERROR_FTELL;
    }

    if (fseek (text, 0, SEEK_SET) != 0)
    {
        return ERROR_FSEEK;
    }
    return GOOD_WORKING;
}

int NumberLineText (char* file_buffer, size_t size_file)
{
    int number_line_text = 0;
    for (int i = 0; i < size_file; i++)
    {
        if (file_buffer[i] == '\n')
        {
            number_line_text++;
        }
    }
    return (file_buffer[size_file - 1] == '\n') ? (number_line_text) : (number_line_text + 1);
}

int BufferTxtFileCreate (size_t* size_file, int* number_line_text, char** file_buffer, const char* file_name)
{
    FILE* text = fopen (file_name, "rb");
    if (!text)
    {
        return ERROR_FILE_OPEN;
    }

    SizeFile (text, size_file);

    *file_buffer = (char*) calloc (*size_file, sizeof (char));
    if (!(*file_buffer))
    {
        free (*file_buffer);
        fclose (text);
        return ERROR_MEMMORY;
    }

    size_t count_simbols = fread (*file_buffer, sizeof (char), *size_file, text);
    if (count_simbols != *size_file)
    {
        free (*file_buffer);
        fclose (text);
        return ERROR_READING_FILE;
    }

    *number_line_text = NumberLineText (*file_buffer, *size_file);

    if (fclose (text) != 0)
    {
        free (*file_buffer);
        return ERROR_FILE_CLOSE;
    }

    return GOOD_WORKING;
}

void BufferTransferPointer (char** p_array_pointer, char* file_buffer, size_t size_file)
{
    assert(file_buffer);

    int counter = 0;
    for (int i = 0; i < size_file; i++)
    {
        if (i == 0)
        {
            p_array_pointer[counter] = file_buffer + i;
            counter++;
        }
        else if (file_buffer[i-1] == '\n')
        {
            p_array_pointer[counter] = file_buffer + i;
            counter++;  
        }
    }
}

void ArrayTransferFile (char** p_array_pointer, FILE* text, const int number_string_text)
{
    assert(p_array_pointer);

    for (int i = 0; i < number_string_text; i++)
    {
        int j = 0;
        while ((*(p_array_pointer[i] + j) != '\n'))
        {
            fputc (*(p_array_pointer[i] + j), text);
            j++;
            if (*(p_array_pointer[i] + j) == '\0')
            {
                break;
            }
        }

        fputc ('\n', text);
    }
}

int PutcTextOnFile (char** p_array_pointer, int number_line_text, char* file_buffer)
{
    assert(p_array_pointer);
    assert(file_buffer);

    FILE* text_end = fopen ("TextEnd.txt", "ab");
    if (!text_end)
    {
        FreeBuffer (p_array_pointer, file_buffer);
        return ERROR_FILE_OPEN;
    }

    QuickSort (p_array_pointer, number_line_text, ComparisonString);
    //BubleSort (p_array_pointer, number_line_text, ComparisonString);
    ArrayTransferFile (p_array_pointer, text_end, number_line_text);
    if (fprintf(text_end, "----------------------------------------------\n") < 0)
    {
        FreeBuffer (p_array_pointer, file_buffer);
        return ERROR_FPRINTF;
    }

    QuickSort (p_array_pointer, number_line_text, ComparisonStringEnd);
    //BubleSort (p_array_pointer, number_line_text, ComparisonStringEnd);
    ArrayTransferFile (p_array_pointer, text_end, number_line_text);
    if (fprintf(text_end, "----------------------------------------------\n") < 0)
    {
        FreeBuffer (p_array_pointer, file_buffer);
        return ERROR_FPRINTF;
    }

    if (fprintf (text_end, "%s", file_buffer) < 0)
    {
        FreeBuffer (p_array_pointer, file_buffer);
        return ERROR_FPRINTF;
    }

    if (fclose (text_end) != 0)
    {
        FreeBuffer (p_array_pointer, file_buffer);
        return ERROR_FILE_CLOSE;
    }

    return GOOD_WORKING;
}

void FreeBuffer (char** p_array_pointer, char* file_buffer)
{
    free(p_array_pointer);
    free(file_buffer);
}



