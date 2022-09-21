#include "SortingString.h"
#include "FileProcessing.h"

int main()
{
    struct Text text_info = {};
    struct FileInfo file_info = {.file_name = "text.txt"};

    BufferTxtFileCreate (&file_info, &text_info);
 
    text_info.p_array_pointer = (char**) calloc (text_info.number_line_text, sizeof (char*));
    BufferTransferPointer (&text_info);

    PutcTextOnFile (&file_info, &text_info);

    FreeBuffer (&text_info);

    return 0;
}
