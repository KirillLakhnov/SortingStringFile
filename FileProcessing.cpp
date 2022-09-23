#include "FileProcessing.h"
#include "SortingString.h"

int SizeFile (struct FileInfo* file_info, struct Text* text_info)
{
    assert(file_info->text);

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
    assert(text_info->file_buffer);

    text_info->line_info = (struct LinePointerLength*) calloc (text_info->number_line_text + 1, sizeof(LinePointerLength));
    int number_line_text = 0;
    int length_line = 0;
    
    for (int i = 0; i < text_info->size_file; i++)
    {
        if (text_info->file_buffer[i] == '\n')
        {
            length_line++;
            text_info->line_info[number_line_text].length = length_line;
            length_line = 0;

            number_line_text++;
            text_info->file_buffer[i] = '\0';
        }
        else
        {
            length_line++;
        }
    }

    return (text_info->file_buffer[text_info->size_file - 1] == '\n') ? (number_line_text) : (number_line_text + 1);
}

int TextCtor (struct FileInfo* file_info, struct Text* text_info)
{
    assert(file_info->file_name);

    file_info->text = fopen (file_info->file_name, "rb");
    if (!file_info->text)
    {
        return ERROR_FILE_OPEN;
    }

    SizeFile (file_info, text_info); 

    text_info->file_buffer = (char*) calloc (text_info->size_file + 1, sizeof (char));
    if (!(text_info->file_buffer))
    {
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
    assert(text_info->line_info);

    int counter = 0;
    for (int i = 0; i < text_info->number_line_text; i++)
    {
        text_info->line_info[i].pointer_line = text_info->file_buffer + counter;
        counter += (text_info->line_info[i].length);
    }
}

int ArrayTransferFile (FILE* text_end, struct Text* text_info)
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

int PutcTextOnFile (FILE* text_end, struct FileInfo* file_info, struct Text* text_info)
{
    assert(text_info->file_buffer);
    assert(text_info->line_info);
    assert(text_end);

    QuickSortCharPointStruct (text_info->line_info, text_info->number_line_text, ComparisonString);
    ArrayTransferFile (text_end, text_info);
    if (fprintf(text_end, "----------------------------------------------\n") < 0)
    {
        return ERROR_FPRINTF;
    }

    QuickSortCharPointStruct (text_info->line_info, text_info->number_line_text, ComparisonStringEnd);
    ArrayTransferFile (text_end, text_info);
    if (fprintf(text_end, "----------------------------------------------\n") < 0)
    {
        return ERROR_FPRINTF;
    }

    int counter = 0;
    for (int i = 0; i < text_info->number_line_text; i++)
    {
        fputs((text_info->file_buffer) + counter, text_end);
        if(i != text_info->number_line_text -1)
        {
            fputc('\n', text_end);
        }
        counter += (text_info->line_info[i].length);
    }

    return GOOD_WORKING;
}

void TextDtor (struct Text* text_info)
{
    assert(text_info->file_buffer);
    assert(text_info->line_info);

    free(text_info->file_buffer);
    free(text_info->line_info);
}



