#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define RANGE 10

int * count_s(int n, int *arr);

int main (void)
{    
    // Prepare variables
    int l;
    int *arr = malloc(l * sizeof(int));
    int i;
    // Get lenght of array
    printf("Input lenght of array to sort: ");
    scanf("%i", &l);
    // Store data in array
    for (i = 0; i < l; i++)
    {
        printf("Input a number from 0 to 9: ");
        scanf("%i", &arr[i]);
    }
    // Call count function. Reuse variable arr 
    int * p;   
    p = count_s(l, arr);
    // Print sorted array
    for (i = 0; i < l; i++)
    {
        printf("%i ", p[i]);
    }
    printf("\n");
    free (arr);
    // Free p to free sorted_arr
    free (p);
    return 0;
}

int * count_s(int n, int *arr)
{
    // Prepare variables
    int i;
    int index_count;
    // Create final array
    int *sorted_arr = NULL; 
    // Create count array initialized at zero values
    int *count =  malloc(RANGE * sizeof(int));
    if (count != NULL)    
    {      
        memset(count, 0, RANGE * sizeof(int));

        // Update count array with the count of each item in unsorted array
        for (i = 0; i < n; i++)
        {
            index_count = arr[i];        
            count[index_count] += 1;            
        }
        
        // Update count[i] array with the sum of count[i - 1] to get the 
        // position for the sorted array
        for (i = 0; i < RANGE; i++)
        {
            count[i] = count[i] + count[i - 1];            
        }
        
        // allocate memory to final array
        sorted_arr = malloc(n * sizeof(int));
        if (sorted_arr != NULL)    
        {
            // fill final array
            for (i = 0; i < n; i++)
            {
                index_count = arr[i];                
                sorted_arr[count[index_count] - 1] = arr[i];                
                count[index_count] = count[index_count] - 1;
            }
        }  
    }
    free (count);
    return sorted_arr;
}