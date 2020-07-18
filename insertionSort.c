#include <stdio.h>

#define SIZE 8

void sort(int array[], int size)
{
    // TODO: sort array using insertion sort
    // define first element of array as sorted
    int current;
    int i, j, temp;
    // iterate over each element of the array
    for (i = 0; i < size - 1; i++)
    {
        current = array[i];        
        if (current > array[i + 1])
        {
            //put array[i + 1] in correct position to the left
            temp = array[i + 1];
            j = i + 1;
            //shift ordered elements to the right
            while (array[j - 1] > temp && j > 0)
            {
                array[j] = array[j - 1];
                j--;   
            }
            array[j] = temp;
        }
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