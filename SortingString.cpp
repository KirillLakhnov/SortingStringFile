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


int ComparisonString (char* str1, char* str2)
{
    assert (str1);
    assert (str2);

    int i = 0, j = 0;
    while (str1[i] != '\0' && str2[j] != '\0')
    {
        while (isalpha (str1[i]) == 0)
        {
            i++;
        }
        while (isalpha (str2[j]) == 0)
        {
            j++;
        } 

        if (tolower(str1[i]) != tolower(str2[j]))
        {
            break;
        }
        else
        {
            i++;
            j++;
        }
    } 
    return tolower(str1[i]) - tolower(str2[j]);
}

int ComparisonStringEnd (char* str1, char* str2)
{
    assert (str1);
    assert (str2);

    int i = strlen (str1), j = strlen (str2);
    int str_i = NAN, str_j = NAN;

    while (i >= 0 && j >= 0)
    {
        int str_i = i+1;
        int str_j = j+1;
        while (isalpha (str1[i]) == 0)
        {
            i--;
            if (i < 0)
            {
                break;
            }
        }
        while (isalpha (str2[j]) == 0)
        {
            j--;
            if (j < 0)
            {
                break;
            }
        } 

        if (tolower(str1[i]) != tolower(str2[j]))
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
        return tolower(str1[str_i]) - tolower(str2[str_j]);
    }
    else
    {
        return tolower(str1[i]) - tolower(str2[j]);
    }
}