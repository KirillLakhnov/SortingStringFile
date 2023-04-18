#include "SortingString.h"
#include "FileProcessing.h"

void Swap (void* obj1, void* obj2, size_t size_element)
{
    char* obj1_byte = (char*) obj1;
    char* obj2_byte = (char*) obj2;

    while (size_element >= sizeof(unsigned long long))
    {
        unsigned long long swap_help = *((unsigned long long*)obj1_byte);
        *((unsigned long long*)obj1_byte) = *((unsigned long long*)obj2_byte);
        *((unsigned long long*)obj2_byte) = swap_help;

        obj1_byte += sizeof(unsigned long long);
        obj2_byte += sizeof(unsigned long long);

        size_element -= sizeof(unsigned long long);
    }

    while (size_element >= sizeof(int))
    {
        int swap_help = *((int*)obj1_byte);
        *((int*)obj1_byte) = *((int*)obj2_byte);
        *((int*)obj2_byte) = swap_help;

        obj1_byte += sizeof(int);
        obj2_byte += sizeof(int);

        size_element -= sizeof(int);
    }

    while (size_element != 0)
    {
        char swap_help = *(obj1_byte);
        *(obj1_byte) = *(obj2_byte);
        *(obj2_byte) = swap_help;

        obj1_byte++;
        obj2_byte++;

        size_element -= sizeof(char);
    }
}

void BubleSortCharPointStruct (struct Line* line_info, const int number_line_text, int (*compare) (const void* ,const void*))
{  
    for (int i = 0; i < (number_line_text - 1); i++)
    {
        for (int j = i + 1; j < number_line_text; j++)
        {
            if (compare ((void*)(&line_info[i]), (void*)(&line_info[j])) > 0)
            {
                Swap (&line_info[i], &line_info[j], sizeof(*line_info));
            }      
        }
    }
}

void QuickSortCharPointStruct (struct Line* line_info, int number_line_text, int (*compare) (const void* ,const void*))
{

    int i = 0;
    int j = number_line_text - 1;
    struct Line* middle_array = &line_info[(number_line_text/2)];

    do
    {
        while (compare ((void*)(&line_info[i]), (void*)(middle_array)) < 0)
        {
            i++;
        }
        while (compare ((void*)(&line_info[j]), (void*)(middle_array)) > 0)
        {
            j--;
        }

        if (i <= j)
        {
            Swap (&line_info[i], &line_info[j], sizeof(*line_info));

            i++;
            j--;
        }
    } 
    while (i <= j)
        ;

    if (i < number_line_text - 1)
    {
        QuickSortCharPointStruct (&line_info[i], number_line_text - i, compare);
    }
    
    if (j > 0)
    {
        QuickSortCharPointStruct (line_info, j+1, compare);
    }
}

void QuickSortVoid (void* array, size_t size_array, size_t size_type, int (*compare) (const void* ,const void*))
{
    int i = 0;
    int j = (int) size_array - 1;
    char* middle_array = (char*)array + (size_array/2) * size_type ;

    do
    {
        while (compare (((char*)array + i*size_type), middle_array) < 0)
        {
            i++;
        }
        while (compare (((char*)array + j*size_type), (middle_array)) > 0)
        {
            j--;
        }

        if (i <= j)
        {
            Swap ((char*)array + i*size_type, (char*)array + j*size_type, size_type);

            i++;
            j--;
        }
    } 
    while (i <= j)
        ;

    if (i < size_array - 1)
    {
        QuickSortVoid (((char*)array + i*size_type), size_array - i, size_type, compare);
    }
    
    if (j > 0)
    {
        QuickSortVoid (array, j+1, size_type, compare);
    }
}

int ComparisonString (const void* struct_line1, const void* struct_line2)
{
    assert (struct_line1);
    assert (struct_line2);
    
    char* str_1 = ((Line*) struct_line1)->pointer_line;
    char* str_2 = ((Line*) struct_line2)->pointer_line;

    int i = 0, j = 0;
    while (str_1[i] != '\0' && str_2[j] != '\0')
    {
        while (isalpha (str_1[i]) == 0)
        {
            i++;
        }
        while (isalpha (str_2[j]) == 0)
        {
            j++;
        } 

        if ((tolower (str_1[i]) != tolower (str_2[j])))
        {
            break;
        }
        else
        {
            i++;
            j++;
        }
    } 
    return tolower (str_1[i]) - tolower (str_2[j]);
}

int ComparisonStringEnd (const void* struct_line1, const void* struct_line2)
{
    assert (struct_line1);
    assert (struct_line2);

    char* str_1 = ((Line*) struct_line1)->pointer_line;
    char* str_2 = ((Line*) struct_line2)->pointer_line;

    int i = ((Line*) struct_line1)->length,
        j = ((Line*) struct_line2)->length;

    while (i >= 0 && j >= 0)
    {   
        while (!isalpha (str_1[i]))
        {
            i--;
        }
        while (!isalpha (str_2[j]))
        {
            j--;
        }

        if (i < 0 || j < 0)
        {
            break;
        }

        if (tolower (str_1[i]) != tolower (str_2[j]))
        {
            break;
        }
        else
        {
            i--;
            j--;
        }
    }

    if (i < 0 && j < 0) 
    {
        return  0;
    }
    else if (i < 0)     
    {
        return  -1;
    }
    else if (j < 0)     
    {
        return  1;
    }
    else
    {
        return tolower (str_1[i]) - tolower (str_2[j]);
    }
}
