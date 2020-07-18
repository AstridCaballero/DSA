#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{
    // TODO: sort array using bubble sort
    int counter = -1;
    int i, temp;
    while (counter != 0)
    {
        counter = 0;
        for (i = 0; i < size - 1; i++)
        {
            if (array[i] > array[i + 1])
            {
                //swap
                temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                // increase counter
                counter++;
            }
        } 
        size--;   
    }
}

int main(void)
{
    int numbers[SIZE] = { 4, 15, 16, 50, 8, 23, 42, 108 };
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
    sort(numbers, SIZE);
    for (i = 0; i < SIZE; i++)
    {
        printf("%i ", numbers[i]);
    }
    printf("\n");
}