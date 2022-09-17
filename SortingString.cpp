#include "SortingString.h"
#include "FileProcessing.h"

void SortingStringBuble (char** p_array_pointer, const int number_string_text)
{  
    for (int i = 0; i < (number_string_text - 1); i++)
    {
        for (int j = i+1; j < number_string_text; j++)
        {
            if (ComparisonString (*(p_array_pointer+i), *(p_array_pointer+j)) > 0)
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

void SortingStringBubleEnd (char** p_array_pointer, const int number_string_text)
{  
    for (int i = 0; i < (number_string_text - 1); i++)
    {
        for (int j = i+1; j < number_string_text; j++)
        {
            if (ComparisonStringEnd (*(p_array_pointer+i), *(p_array_pointer+j)) > 0)
            {
                char* sort_help = *(p_array_pointer + j);
                for (int k = j - 1; k >= i; k--)
                {
                    *(p_array_pointer + (k + 1)) = *(p_array_pointer + k);
                    *(p_array_pointer + k) = sort_help;
                }
            }      
        }
    }
}

void BubleSort (char** p_array_pointer, const int number_string_text, int (*compare) (const void* ,const void*))
{  
    for (int i = 0; i < (number_string_text - 1); i++)
    {
        for (int j = i+1; j < number_string_text; j++)
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

int ComparisonString (const void* str1, const void* str2)
{
    assert (str1);
    assert (str2);

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




/* void BubleSortPlus (void* p_array, size_t number, size_t size_type, int (*compare) (const void* ,const void*))
{  
    for (int i = 0; i < ((int)number - 1); i++)
    {
        for (int j = i + 1; j < (int)number; j++)
        {
            if (compare ((void*)((char*)(p_array) + i), (void*)((char*)(p_array) + j)) > 0)
            {
                char* sort_help = (char*)(p_array) + j*size_type;
                for (int k = j - 1; k >= i; k--)
                {
                    *((char*)(p_array) + (k + 1)*size_type) = *((char*)(p_array) + k*size_type);
                    *((char*)(p_array) + k*size_type) = *sort_help;
                }
            }      
        }
    } 
} */

/* void QuickSort (char* p_array, int number_string_text, int (*compare) (const void* ,const void*))
{
    int i = 0;
    int j = number_string_text - 1;
    char* middle_array = p_array + number_string_text/2;

    do
    {
        while (compare ((void*)(p_array + i), (void*)(middle_array)) < 0)
        {
            i++;
        }
        while (compare ((void*)(p_array + i), (void*)(middle_array)) > 0)
        {
            j--;
        }

        if (i <= j)
        {
            char sort_help = p_array[i];
            p_array[i] = p_array[j];
            p_array[j] = sort_help;

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0)
    {
        QuickSort (p_array, j+1, compare);
    }

    if (i < number_string_text)
    {
        QuickSort (p_array + i, number_string_text - i, compare);
    }
} */

