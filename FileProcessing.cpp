#include "FileProcessing.h"
#include "SortingString.h"

int SizeFile (FILE* text, struct Text* text_info)
{
    assert(text);

    if (fseek (text, 0, SEEK_END) != 0)
    {
        return ERROR_FSEEK;
    }

    text_info->size_buffer = ftell (text);
    if (!(text_info->size_buffer))
    {
        return ERROR_FTELL;
    }

    if (fseek (text, 0, SEEK_SET) != 0)
    {
        return ERROR_FSEEK;
    }
    return GOOD_WORKING;
}

int NumberLineText (struct Text* text_info)
{
    assert(text_info->file_buffer);

    int number_line_text = 0;
    
    for (int i = 0; i <= text_info->size_buffer; i++)
    {
        if (text_info->file_buffer[i] == '\n')
        {
            number_line_text++;
            if (i != 1 && text_info->file_buffer[i - 1] == '\r')
            {
                text_info->file_buffer[i-1] = '\0';
            }
            else
            {
                text_info->file_buffer[i] = '\0';
            }

        }
    }
    return (text_info->file_buffer[text_info->size_buffer - 1] == '\n') ? (number_line_text) : (number_line_text + 1);
}

int BufferCreater (struct FileInfo* file_info, struct Text* text_info)
{
    assert(file_info->file_name);

    FILE* text = fopen (file_info->file_name, "rb");
    if (!text)
    {
        return ERROR_FILE_OPEN;
    }

    SizeFile (text, text_info); 

    text_info->file_buffer = (char*) calloc (text_info->size_buffer + 1, sizeof (char));
    if (!(text_info->file_buffer))
    {
        fclose (text);
        return ERROR_MEMMORY;
    }

    size_t count_simbols = fread (text_info->file_buffer, sizeof (char), text_info->size_buffer, text);
    if (count_simbols != text_info->size_buffer)
    {
        free (text_info->file_buffer);
        fclose (text);
        return ERROR_READING_FILE;
    }

    if (fclose (text) != 0)
    {
        free (text_info->file_buffer);
        return ERROR_FILE_CLOSE;
    }

    return GOOD_WORKING;
}

int TextCtor (struct FileInfo* file_info, struct Text* text_info)
{
    if (BufferCreater (file_info, text_info))
    {
        return ERROR_BUFFER_CREATER;
    }

    text_info->number_line_text = NumberLineText (text_info);

    BufferTransferPointer (text_info);

    return GOOD_WORKING;
}

void BufferTransferPointer (struct Text* text_info)
{
    assert(text_info->file_buffer);

    text_info->line_info = (struct Line*) calloc (text_info->number_line_text, sizeof(Line));

    int number_line_text = 0;
    int length_line = 0;
    
    for (int i = 0; i <= text_info->size_buffer; i++)
    {
        if (text_info->file_buffer[i] == '\0')
        {
            text_info->line_info[number_line_text].length = length_line;
            length_line = 0;

            number_line_text++;
        }
        else if (text_info->file_buffer[i] == '\0')
        {
            text_info->line_info[number_line_text].length = length_line;
        }
        else
        {
            length_line++;
        }
    }

    int counter = 0;
    for (int i = 0; i < text_info->number_line_text; i++)
    {
        text_info->line_info[i].pointer_line = text_info->file_buffer + counter;
        counter += (text_info->line_info[i].length + 1);
    }
}

int ArraySortTransferFile (FILE* text_end, struct Text* text_info)
{
    assert(text_info->file_buffer);
    assert(text_info->line_info);
    assert(text_end);

    for (int i = 0; i < text_info->number_line_text; i++)
    {
        if (fputs (text_info->line_info[i].pointer_line, text_end) < 0 || fputc('\n', text_end) < 0)
        {
            return ERROR_FPUTS;
        }
    }
    return GOOD_WORKING;
}

int ArrayTransferFile (FILE* text_end, struct Text* text_info)
{
    int counter = 0;
    for (int i = 0; i < text_info->number_line_text; i++)
    {
        if (fputs((text_info->file_buffer) + counter, text_end) < 0)
        {
            return ERROR_FPUTS;
        }
        if (fputc('\n', text_end) < 0)
        {
            return ERROR_FPUTS;
        }
        counter += strlen((text_info->file_buffer + counter)) + 1;
    }

    return GOOD_WORKING;
}

int PutcTextOnFile (FILE* text_end, struct FileInfo* file_info, struct Text* text_info)
{
    assert(text_info->file_buffer);
    assert(text_info->line_info);
    assert(text_end);

    QuickSortVoid (text_info->line_info, text_info->number_line_text, sizeof(*text_info->line_info), ComparisonString);
    ArraySortTransferFile (text_end, text_info);
    if (fprintf(text_end, "----------------------------------------------\n") < 0)
    {
        return ERROR_FPRINTF;
    }

    QuickSortVoid (text_info->line_info, text_info->number_line_text, sizeof(*text_info->line_info), ComparisonStringEnd);
    ArraySortTransferFile (text_end, text_info);
    if (fprintf(text_end, "----------------------------------------------\n") < 0)
    {
        return ERROR_FPRINTF;
    }

    ArrayTransferFile (text_end, text_info);

    return GOOD_WORKING;
}

void TextDtor (struct Text* text_info)
{
    assert(text_info->file_buffer);
    assert(text_info->line_info);

    free(text_info->file_buffer);
    free(text_info->line_info);

    text_info->file_buffer = nullptr;
    text_info->line_info = nullptr;
    text_info->number_line_text = NAN;
    text_info->size_buffer = NAN;
}
