#include "FileProcessing.h"

int SizeFile (FILE* text, size_t* size_file)
{
    if (fseek (text, 0, SEEK_END) != 0)
    {
        return ERROR_FSEEK;
    };

    *size_file = ftell(text);
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

int BufferTxtFileCreate (size_t* size_file, int* number_line_text, char** file_buffer, char* file_name)
{
    FILE* text = fopen (file_name, "rb");
    if (!text)
    {
        return ERROR_FILE_OPEN;
    }

    *size_file = SizeFile (text, size_file);

    *file_buffer = (char*) calloc (*size_file, sizeof (char));
    if (!(*file_buffer))
    {
        free (*file_buffer);
        fclose (text);
        return ERROR_MEMMORY;
    }

    size_t count_simbols = fread (*file_buffer, sizeof (char), *size_file, text);
    if (count_simbols != (size_t)size_file)
    {
        free (*file_buffer);
        fclose (text);
        return ERROR_READING_FILE;
    }

    *number_line_text = NumberLineText (*file_buffer, *size_file);

    if (!fclose (text))
    {
        free (*file_buffer);
        return ERROR_FILE_CLOSE;
    }

    return GOOD_WORKING;
}

void BufferArrayCompletion(char** file_buffer_array, char* file_buffer, size_t size_file, int number_line_text)
{
    int counter = 0;
    for (int i = 0; (i < number_line_text) && (counter < size_file); i++)
    {
        int j = 0;
        while ((file_buffer[counter] != '\n') && (j < size_file))
        {
            file_buffer_array[i][j] = file_buffer[counter];
            counter++;
            j++;
        }
        if (file_buffer[counter] == '\n')
        {
            file_buffer_array[i][j] = '\n';
            j++;
            file_buffer_array[i][j] = '\0';
            counter++;
            j++;
        }
    }
}

void BufferTransferFile (char** file_buffer_array, char** p_array_pointer, int number_line_text)
{
    for (int i = 0; i < number_line_text; i++)
    {
        *(p_array_pointer + i) = *(file_buffer_array + i);
    }
}

void ArrayTransferFile (char** p_array_pointer, FILE* text, const int number_string_text)
{
    for (int i = 0; i < number_string_text; i++)
    {
        fprintf(text, "%s", *(p_array_pointer + i*sizeof(char)));
    }
}

