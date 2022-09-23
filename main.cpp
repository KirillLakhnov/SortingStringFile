#include "SortingString.h"
#include "FileProcessing.h"

int main()
{
    struct Text text_info = {};
    struct FileInfo file_info = {.file_name = "text.txt"};

    TextCtor (&file_info, &text_info);
    text_info.number_line_text = NumberLineText (&text_info);

    BufferTransferPointer (&text_info);

    FILE* text_end = fopen ("TextEnd.txt", "ab");
    PutcTextOnFile (text_end, &file_info, &text_info);
    fclose (text_end);

    TextDtor (&text_info);

    return 0;
}
