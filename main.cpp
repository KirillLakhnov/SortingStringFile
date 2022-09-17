#include "SortingString.h"
#include "FileProcessing.h"

int main()
{
    char file_name[] = "Text.txt";
    size_t size_file = 0;
    int number_line_text = NAN;
    char* file_buffer = nullptr;
    
    BufferTxtFileCreate (&size_file, &number_line_text, &file_buffer, file_name);


    char** file_buffer_array = (char**) calloc (number_line_text, sizeof (char*));
    for (int i = 0; i < number_line_text; i++)
    {
        file_buffer_array[i] = (char*) calloc (size_file, sizeof(char));
    }

    BufferArrayCompletion(file_buffer_array, file_buffer, size_file, number_line_text);
    
    /**/for (int i = 0; i < number_line_text; i++)
    /**/{
    /**/    printf("%s", file_buffer_array[i]);
    /**/} 

    char** p_array_pointer = (char**) calloc (number_line_text, sizeof (char*));
    BufferTransferFile (file_buffer_array, p_array_pointer, number_line_text);

    FILE* text_end = fopen ("TextEnd.txt", "ab");

    BubleSort (p_array_pointer, number_line_text, ComparisonString);
    ArrayTransferFile (p_array_pointer, text_end, number_line_text);
    fprintf(text_end, "----------------------------------------------\n");

    BubleSort (p_array_pointer, number_line_text, ComparisonStringEnd);
    ArrayTransferFile (p_array_pointer, text_end, number_line_text);
    fprintf(text_end, "----------------------------------------------\n");

    fprintf (text_end, "%s", file_buffer);

    fclose (text_end); 

    return 0;
}
