#include "SortingString.h"
#include "FileProcessing.h"

int main()
{
    char file_name[] = "Hamlet.txt";
    size_t size_file = 0;
    int number_line_text = 0;
    char* file_buffer = nullptr;

    BufferTxtFileCreate (&size_file, &number_line_text, &file_buffer, file_name);
 
    char** p_array_pointer = (char**) calloc (number_line_text, sizeof (char*));
    BufferTransferPointer (p_array_pointer, file_buffer, size_file);

    PutcTextOnFile (p_array_pointer, number_line_text, file_buffer);

    FreeBuffer (p_array_pointer, file_buffer);

    return 0;
}
