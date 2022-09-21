#include "SortingString.h"
#include "FileProcessing.h"

int LineLen (const char* str)
{
    assert (str);

    int lenght_string = 0;
    while (str[lenght_string] != '\n')
    {
        lenght_string++;
    }

    return lenght_string;
}

void BubleSort (char** p_array_pointer, const int number_line_text, int (*compare) (const void* ,const void*))
{  
    assert(p_array_pointer);

    for (int i = 0; i < (number_line_text - 1); i++)
    {
        for (int j = i + 1; j < number_line_text; j++)
        {
            if (compare ((void*)(*(p_array_pointer + i)), (void*)(*(p_array_pointer + j))) > 0)
            {
                char* sort_help = *(p_array_pointer + j);
                for (int k = j - 1; k >= i; k--)
                {
                    *(p_array_pointer + (k+1)) = *(p_array_pointer + k);
                    *(p_array_pointer + k) = sort_help;
                }
            }      
        }
    }
}

void QuickSort (char** p_array_pointer, int number_line_text, int (*compare) (const void* ,const void*))
{
    assert(p_array_pointer);

    int i = 0;
    int j = number_line_text - 1;
    char* middle_array = *(p_array_pointer + (number_line_text/2));

    do
    {
        while (compare ((void*)(*(p_array_pointer + i)), (void*)(middle_array)) < 0)
        {
            i++;
        }
        while (compare ((void*)(*(p_array_pointer + j)), (void*)(middle_array)) > 0)
        {
            j--;
        }

        if (i <= j)
        {
            char* sort_help = *(p_array_pointer + i);
            *(p_array_pointer + i) = *(p_array_pointer + j);
            *(p_array_pointer + j) = sort_help;

            i++;
            j--;
        }
    } 
    while (i <= j)
        ;

    if (i < number_line_text - 1)
    {
        QuickSort (p_array_pointer + i, number_line_text - i, compare);
    }
    
    if (j > 0)
    {
        QuickSort (p_array_pointer, j+1, compare);
    }
}

int ComparisonString (const void* str1, const void* str2)
{
    assert (str1);
    assert (str2);

    int i = 0, j = 0;
    while (*((char*)(str1) + i) != '\n' && *((char*)(str2) + j) != '\n')
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

    int i = LineLen ((char*)str1), j = LineLen ((char*)str2);
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
