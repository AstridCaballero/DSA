#include <stdio.h>

int shift(int *arr, int len);

int main(void)
{
    // int arr[10] = {16, 17, 20, 24, 25, 1, 2, 5, 7, 11};
    int arr[5] = {1, 2, 5, 7, 11};
    // int arr[10]= {8, 9, 10, 1, 2, 3, 4, 5, 6, 7};
    int n = 5;
    int n_shift = shift(arr, n);
    printf("output = %i\n", n_shift);
    return 0;
}


int shift(int *arr, int len)
{
    // binary search the min value
    int first = 0;
    int last = len - 1;
    int half = (first + last)/2;    
   
    // loop using binary search approach and stop when the subarray 
    // has only two elements, so the distance between first and last is one.
    while(last - first > 1)
    {
        printf("First: %i ", first);
        printf("Half: %i ", half);
        printf("Last: %i\n", last);
        if (arr[half] > arr[last])
        {
            first = half;
            half = (first + last) / 2;

        }
        else 
        {
            last = half;
            half = (first + last) / 2;

        }

    }

    printf("First: %i ", first);
    printf("Half: %i ", half);
    printf("Last: %i\n", last);
    // Now check which element of the two element subarray is the smallest number
    // and return the index
    if (arr[first] < arr[last])
    {
        return first;
    }
    else
    {
        return last;
    }    
}