#include <stdio.h>

int shift(int *arr, int len);

int main(void)
{
    int arr[4] = {1, 3, 7, 8};
    int n = 4;
    int n_shift = shift(arr, n);
}


int shift(int *arr, int len)
{
    int temp, index;
    temp = arr[0];
    index = 0;
    int i;
    for(i = 1; i < len; i++)
    {
         if (temp > arr[i])
         {
             temp = arr[i];
             index = i;
             break;
         }        
    }    
    printf("output = %i\n", index);
    return index;
}