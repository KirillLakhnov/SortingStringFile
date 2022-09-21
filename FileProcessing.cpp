#include "FileProcessing.h"
#include "SortingString.h"

int SizeFile (struct FileInfo* file_info, struct Text* text_info)
{
    if (fseek (file_info->text, 0, SEEK_END) != 0)
    {
        return ERROR_FSEEK;
    }

    text_info->size_file = ftell (file_info->text);
    if (!(text_info->size_file))
    {
        return ERROR_FTELL;
    }

    if (fseek (file_info->text, 0, SEEK_SET) != 0)
    {
        return ERROR_FSEEK;
    }
    return GOOD_WORKING;
}

int NumberLineText (struct Text* text_info)
{
    int number_line_text = 0;
    for (int i = 0; i < text_info->size_file; i++)
    {
        if (text_info->file_buffer[i] == '\n')
        {
            number_line_text++;
        }
    }
    return (text_info->file_buffer[text_info->size_file - 1] == '\n') ? (number_line_text) : (number_line_text + 1);
}

int BufferTxtFileCreate (struct FileInfo* file_info, struct Text* text_info)
{
    file_info->text = fopen (file_info->file_name, "rb");
    if (!file_info->text)
    {
        return ERROR_FILE_OPEN;
    }

    SizeFile (file_info, text_info);

    text_info->file_buffer = (char*) calloc (text_info->size_file, sizeof (char));
    if (!(text_info->file_buffer))
    {
        free (text_info->file_buffer);
        fclose (file_info->text);
        return ERROR_MEMMORY;
    }

    size_t count_simbols = fread (text_info->file_buffer, sizeof (char), text_info->size_file, file_info->text);
    if (count_simbols != text_info->size_file)
    {
        free (text_info->file_buffer);
        fclose (file_info->text);
        return ERROR_READING_FILE;
    }

    text_info->number_line_text = NumberLineText (text_info);

    if (fclose (file_info->text) != 0)
    {
        free (text_info->file_buffer);
        return ERROR_FILE_CLOSE;
    }

    return GOOD_WORKING;
}

void BufferTransferPointer (struct Text* text_info)
{
    assert(text_info->file_buffer);

    int counter = 0;
    for (int i = 0; i < text_info->size_file; i++)
    {
        if (i == 0)
        {
            text_info->p_array_pointer[counter] = text_info->file_buffer + i;
            counter++;
        }
        else if (text_info->file_buffer[i-1] == '\n')
        {
            text_info->p_array_pointer[counter] = text_info->file_buffer + i;
            counter++;  
        }
    }
}

void ArrayTransferFile (FILE* text_end, struct Text* text_info)
{
    assert(text_info->p_array_pointer);

    for (int i = 0; i < text_info->number_line_text; i++)
    {
        int j = 0;
        while ((*(text_info->p_array_pointer[i] + j) != '\n'))
        {
            fputc (*(text_info->p_array_pointer[i] + j), text_end);
            j++;
            if (*(text_info->p_array_pointer[i] + j) == '\0')
            {
                break;
            }
        }

        fputc ('\n', text_end);
    }
}

int PutcTextOnFile (struct FileInfo* file_info, struct Text* text_info)
{
    assert(text_info->p_array_pointer);
    assert(text_info->file_buffer);

    FILE* text_end = fopen ("TextEnd.txt", "ab");
    if (!text_end)
    {
        FreeBuffer (text_info);
        return ERROR_FILE_OPEN;
    }

    QuickSortCharPoint (text_info->p_array_pointer, text_info->number_line_text, ComparisonString);
    ArrayTransferFile (text_end, text_info);
    if (fprintf(text_end, "----------------------------------------------\n") < 0)
    {
        FreeBuffer (text_info);
        return ERROR_FPRINTF;
    }

    QuickSortCharPoint (text_info->p_array_pointer, text_info->number_line_text, ComparisonStringEnd);
    ArrayTransferFile (text_end, text_info);
    if (fprintf(text_end, "----------------------------------------------\n") < 0)
    {
        FreeBuffer (text_info);
        return ERROR_FPRINTF;
    }

    if (fprintf (text_end, "%s", text_info->file_buffer) < 0)
    {
        FreeBuffer (text_info);
        return ERROR_FPRINTF;
    }

    if (fclose (text_end) != 0)
    {
        FreeBuffer (text_info);
        return ERROR_FILE_CLOSE;
    }

    return GOOD_WORKING;
}

void FreeBuffer (struct Text* text_info)
{
    free(text_info->p_array_pointer);
    free(text_info->file_buffer);
}



