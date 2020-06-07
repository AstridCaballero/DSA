#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int is_digit(int len, char *arr[]);
int * insert_sort(int len, int arr[]);

int main(int argc, char *argv[])
{
    // Chech argv[1] to argv[n] are digits 
    int len = argc - 1;

    // Check input args are at least two
    if (argc < 2)
    {
        printf("Please insert numbers to sort\n");
        return 1;
    }       

    else if (is_digit(len, argv) != 0)  
    {
        printf("Please insert only numbers\n");
        return 1;
    }  
   
    // sort the array of numbers
    else
    {
        // convert the string array to numbers array
        int *data = malloc(len * sizeof(int));
        if (data == NULL)
        {
            return 1;
        }
        int i;
        for (i = 0; i < len; i++)
        {
            data[i] = atoi(argv[i+1]);
        }

       // Create a pointer to store the return pointer from fucntion insert_sort
       int *p = malloc(len * sizeof(int));
       if (p == NULL)
       {
           return 1;
       }
       p = insert_sort(len, data);
       int j;
       for ( j = 0; j < len; j++ ) 
       {
            printf( "*(p + %d) : %d\n", j, *(p + j));
       } 
       free(data);    
       free(p);          
    }    
    return 0;
}

// Function to check is a string is a digit
int is_digit(int len, char *arr[])
{
    int i;
    for (i = 1; i < len; i++)
    {
        int len_i = strlen(arr[i]);
        int j;
        for (j = 0; j < len_i; j++)
        {
            if (isdigit(arr[i][j]) == false)
            {
                return 1;
                break;
            }
        }
    }
    return 0;
}

// function to sort the numbers
int * insert_sort(int len, int arr[])
{
    int i;
    // Sort [0] item
    int temp = arr[0];  
    int index;  
    int counter;
    // move to the right and compare 
    for (i = 0; i < len - 1; i++)
    {                 
        int j = i;
        counter = 0;
        // move to the left and compare
        if (arr[i] > arr[i + 1])
        {
            temp = arr[i + 1];
            index = i + 1;

            while ((j >= 0) && (arr[j] > arr[i + 1]))
            {      
                // count how many numbers to the left are bigger than arr[i + 1]
                counter++;      
                // move to the left
                j--;
            } 
            // move elements that are greater than arr[i + 1] to the right  
            int l = index;
            int m = counter;
            for (; m > 0; l--, m--)
            {
                arr[l] = arr[l - 1]; 
            }
            int new_index = index - counter;
            arr[new_index] = temp;
        }         
    }
    int k;
    for (k = 0; k < len; k++)
    {
        printf( "arr[%d] = %d\n", k, arr[k]);        
    } 
    return arr;
}