#include <stdio.h>

#define SIZE 8

int temp[SIZE] = {0};

void merge (int array[], int start_1, int end_1, int start_2, int end_2)
{
    // TODO: Merge sorted subarrays using the auxiliary array 'temp'
    // compare left side with right side using variables i and j
    int i, j;
    // get variable to iterate over temp
    int k;
    for (i = start_1, j = start_2, k = 0; i <= end_1 && j <= end_2; k++)
    {
        if (array[i] < array[j])
        {
            temp[k] = array[i];
            i++;
        }
        else
        {
            temp[k] = array[j];
            j++;
        }
    }
    if (i > end_1)
    {
        for (; k < end_2 + 1; k++, j++)
        {
            temp[k] = array[j];
        }
    }
    else if (j > end_2)
    {
        for (; k < end_2 + 1; k++, i++)
        {
            temp[k] = array[i];
        }
    }   
}

void sort (int array[], int start, int end)
{
    if (end > start)
    {
        int middle = start + (end - start) / 2;

        // sort left half
        sort(array, start, middle);

        // sort right half
        sort(array, middle + 1, end);

        // merge the two halves
        merge(array, start, middle, middle + 1, end);
    }
}

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108};
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    sort(numbers, 0, SIZE - 1);
    for (i = 0; i < SIZE; i++)
    {
        printf("%i ", temp[i]);
    }
    printf("\n");
}