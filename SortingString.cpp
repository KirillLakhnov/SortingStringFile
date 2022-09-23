#include "SortingString.h"
#include "FileProcessing.h"

void BubleSortCharPointStruct (struct LinePointerLength* line_info, const int number_line_text, int (*compare) (const void* ,const void*))
{  
    for (int i = 0; i < (number_line_text - 1); i++)
    {
        for (int j = i + 1; j < number_line_text; j++)
        {
            if (compare ((void*)(line_info[i].pointer_line), (void*)(line_info[j].pointer_line)) > 0)
            {
                char* sort_help = line_info[j].pointer_line;
                for (int k = j - 1; k >= i; k--)
                {
                    line_info[k+1].pointer_line = line_info[k].pointer_line;
                    line_info[k].pointer_line = sort_help;
                }
            }      
        }
    }
}

void QuickSortCharPointStruct (struct LinePointerLength* line_info, int number_line_text, int (*compare) (const void* ,const void*))
{

    int i = 0;
    int j = number_line_text - 1;
    char* middle_array = line_info[(number_line_text/2)].pointer_line;

    do
    {
        while (compare ((void*)(line_info[i].pointer_line), (void*)(middle_array)) < 0)
        {
            i++;
        }
        while (compare ((void*)(line_info[j].pointer_line), (void*)(middle_array)) > 0)
        {
            j--;
        }

        if (i <= j)
        {
            char* sort_help = line_info[i].pointer_line;
            line_info[i].pointer_line = line_info[j].pointer_line;
            line_info[j].pointer_line = sort_help;

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
            //void* sort_help = calloc (1 , size_type);
            //memcpy(sort_help, (void*)((char*)array + i*size_type), size_type);
            //memcpy((void*)((char*)array + i*size_type), (void*)((char*)array + j*size_type), size_type);
            //memcpy((void*)((char*)array + j*size_type), sort_help, size_type);
            char* sort_help = (char*)array + i*size_type;
            *((char**)array + i*size_type) = *((char**)array + j*size_type);
            *((char**)array + j*size_type) = sort_help;

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

int ComparisonString (const void* str1, const void* str2)
{
    assert (str1);
    assert (str2);

    //char* str_1 = *(char**)str1;
    //char* str_2 = *(char**)str2;

    int i = 0, j = 0;
    while (*((char*)(str1) + i) != '\0' && *((char*)(str2) + j) != '\0')
    {
        while (isalpha (*((char*)(str1) + i)) == 0)
        {
            i++;
        }
        while (isalpha (*((char*)(str2) + j)) == 0)
        {
            j++;
        } 

        if ((tolower (*((char*)(str1) + i))) != tolower (*((char*)(str2) + j)))
        {
            break;
        }
        else
        {
            i++;
            j++;
        }
    } 
    return tolower (*((char*)(str1) + i)) - tolower (*((char*)(str2) + j));
}

int ComparisonStringEnd (const void* str1, const void* str2)
{
    assert (str1);
    assert (str2);

    int i = strlen ((char*)str1), j = strlen ((char*)str2);
    int str_i = NAN, str_j = NAN;

    while (i >= 0 && j >= 0)
    {
        int str_i = i+1;
        int str_j = j+1;
        
        while (isalpha (*((char*)(str1) + i)) == 0)
        {
            i--;
            if (i < 0)
            {
                break;
            }
        }
        while (isalpha (*((char*)(str2) + j)) == 0)
        {
            j--;
            if (j < 0)
            {
                break;
            }
        } 

        if (tolower (*((char*)(str1) + i)) != tolower (*((char*)(str2) + j)))
        {
            break;
        }
        else
        {
            i--;
            j--;
        }
    } 

    if (i < 0 || j < 0)
    {
        return tolower (*((char*)(str1) + str_i)) - tolower (*((char*)(str2) + str_j));
    }
    else
    {
        return tolower (*((char*)(str1) + i)) - tolower (*((char*)(str2) + j));
    }
}
