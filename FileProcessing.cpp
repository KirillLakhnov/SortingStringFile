#include "FileProcessing.h"

char* Gets (FILE* text)
{
    assert(text);

    char str[STR_LEN_MAX] = "";
    fgets (str, STR_LEN_MAX, text);

    return strdup (str);
}

int FileTransferArray (FILE* text, char** p_array_pointer)
{
    int number_string_text = 0;
    while (number_string_text < STR_NUM)
    {
        *(p_array_pointer + number_string_text) = Gets (text);
        if (*(p_array_pointer + number_string_text) == nullptr)
        {
            break;
        }
        number_string_text++;
    }

    return number_string_text;
}

/*int FileTransferArrayPlus (FILE* text, char** p_array_pointer)
{
    int number_string_text = 0, j = 0;
    char c = NAN;
    while ((c = getc (text)) != EOF)
    {
        if (c != '\n')
        {
            *(*(p_array_pointer + number_string_text) + j) = c;
            j++;
        }
        else
        {
            *(*(p_array_pointer + number_string_text) + j) = '\0';
            number_string_text++;
            j = 0;
        }
    }

    if (c == EOF)
    {
        *(*(p_array_pointer + number_string_text) + j) = '\0';
    }

    return number_string_text;
} */

void ArrayTransferFile (char** p_array_pointer, FILE* text, const int number_string_text)
{
    for (int i = 0; i < number_string_text; i++)
    {
        fprintf(text, "%s", *(p_array_pointer + i*sizeof(char*)));
    }
}

