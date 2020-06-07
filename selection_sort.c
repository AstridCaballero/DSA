#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// https://stackoverflow.com/questions/13322709/use-of-undeclared-identifier-true
// C has no built-in boolean types. So it doesn't know what true/false is. 
// You have to declare it on your own in the below way if using C89, or include <stdbool.h> if compiling with C99
#define true 1
#define false 0


int is_number(int arr_size, char *arr[]);
int * sel_sort(int arr_size, int arr[]);

int main(int argc, char *argv[])
{
    // check correct number of arguments are entered
    if (argc < 2)
    {
        printf("Usage: input file's name and a set of integer numbers\n");
        return 1;
    }
    // check if argv[1] to argv[n] ar integer numbers    
    else if (is_number(argc, argv) != 0)
    {       
        printf("Usage: input only integer numbers\n");
        return 1;
    }
    // Sort numbers
    else
    {        
        // convert char array to int array        
        int size_arr = argc - 1;
        int data[size_arr];
        int i;
        for (i = 0; i < size_arr; i++)
        {
            data[i] = atoi(argv[i+1]);
            // printf("%i\n", data[i]);
        }
    
        // Sort numbers
        /* a pointer to an int to access the return pointer of function sel_sort*/
        int *p;
        p = sel_sort(size_arr, data);
        int j;
        for ( j = 0; j < size_arr; j++ ) 
        {
            printf( "*(p + %d) : %d\n", j, *(p + j));
        }        
    }   
    return 0;
}

int is_number(int arr_size, char *arr[])
{    
    int i;
    for (i = 1; i < arr_size; i++)
    {        
        int len = strlen(arr[i]);
        int j;
        for (j = 0; j < len; j++)
        {
            // printf("%c\n", arr[i][j]);
            if (isdigit(arr[i][j]) == false)
            {
                return 1;
                break;
            }
        }       
    }
    return 0;
}

int * sel_sort(int arr_size, int arr[])
{
    int counter = 1;    
    int n = 0;   
    while(counter != arr_size)
    {
        int i;                
        int temp_small = arr[n];       
        int index;        
        for (i = n; i < arr_size - 1; i++)
        {
            // Find smallest number                          
            if (temp_small > arr[i + 1])
            {
                temp_small = arr[i + 1];
                index = i + 1;
            }                   
        }
        // take smallest number and swap place with 1st place of unsorted array
        if (temp_small != arr[n])
        {            
            arr[index] = arr[n];           
            arr[n] = temp_small;            
        }        
        n++;
        counter++; 
    }  
    int k;
    for (k = 0; k < arr_size; k++)
    {
        printf( "arr[%d] = %d\n", k, arr[k]);        
    }    
    return arr;  
}