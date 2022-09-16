#include "SortingString.h"
#include "FileProcessing.h"

int main()
{
    FILE* text = fopen ("Text.txt", "r");

    char** p_array_pointer = (char**) calloc (STR_NUM, sizeof (char*));
    int number_string_text = FileTransferArray (text, p_array_pointer);
    //int number_string_text = FileTransferArrayPlus (text, p_array_pointer);

    fclose (text);

    SortingString (p_array_pointer, number_string_text);

    //for (int i = 0; i < number_string_text; i++)
    //{
    //    printf("%s", *(p_array_pointer + i));
    //}

    //FILE* text_end = fopen ("TextEnd.txt", "a");
    //ArrayTransferFile (p_array_pointer, text_end, number_string_text);
    //fclose (text_end);

    return 0;
}