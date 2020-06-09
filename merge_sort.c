#include <stdio.h>
#include <stdlib.h>

int * merge_sort(int len, int *arr);

int main(void)
{
    // number of elements in array
    int n;    
    printf("Input amount of elements to be sorted: ");
    scanf("%i", &n);
    // create empty array
    int *arr = malloc(n * sizeof(int));     
    if (arr != NULL)
    {
        // store data from the user
        int i;
        for (i = 0; i < n; i++)
        {
            printf("Input element: \n");
            scanf("%i", &arr[i]);
        }
        
        // call the merge function   
        // reuse arr variable     
        arr = merge_sort(n, arr);

        // print        
        for (i = 0; i < n; i++)
        {
            printf( "arr[%d] = %d\n", i, arr[i]);        
        }         
    }  
    // free space
    free (arr);    
    return 0;    
}

int * merge_sort(int len, int *arr)
{
    // create variable for the new_array    
    int *new_arr = NULL;
    // prepare other variables
    int left;
    int right;
    int *left_arr = NULL;
    int *right_arr = NULL;      

    /* if only one item */
    if (len == 1)
    {
        new_arr = malloc(len * sizeof(int));
        if (new_arr != NULL)
        {
            new_arr[0] = arr[0];
        }        
    }
    else
    {
        int i;
        // Get number of elements for the left side
        left = len/2;
        left_arr = malloc(left * sizeof(int));
        if (left_arr != NULL)
        {            
            for (i = 0; i < left; i++)
            {
                left_arr[i]= arr[i];
            }
        }        
        
        // Get number of elements for the right side
        right = len - left;
        right_arr = malloc(right * sizeof(int));
        if (right_arr != NULL)
        {
            for (i = 0 ; i < right; i++)
            {
                right_arr[i] = arr[i + left];
            }
        }        
        /* sort left half of items */
        left_arr = merge_sort(left, left_arr);
        /* sort right half of itmes */
        right_arr = merge_sort(right, right_arr);

        /* Merge sorted halves */
        // Prepare variables        
        int j = 0;
        int k = 0;
        int index = 0;
        new_arr = malloc((len) * sizeof(int));
        if (new_arr != NULL)
        {
            // Compare left side with right side until one of the sides has all its elements store in new_arr
            while(j < left && k < right)
            {
                if (left_arr[j] > right_arr[k])
                {
                    new_arr[index] = right_arr[k];
                    index++;
                    k++;
                }
                else
                {
                    {
                        new_arr[index] = left_arr[j];
                        index++;
                        j++;
                    }
                }            
            }
            // store the remaining elements in one of the sides into new_array
            if (j == left)
            {
                for (; k < right; k++, index++)
                {
                    new_arr[index] = right_arr[k];
                }
            }
            else
            {
                for (; j < left; j++, index++)
                {
                    new_arr[index] = left_arr[j];
                }
            }                
        }               
    }     
    free (left_arr);
    free (right_arr);
    free(arr);
    return new_arr;     
}