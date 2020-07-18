#include <cs50.h>
#include <stdio.h>

#define SIZE 8

bool search(int needle, int haystack[], int size)
{
    // TODO   
    int lower_bound = 0;
    int upper_bound = size - 1;
    int mid = lower_bound + (upper_bound - lower_bound)/2;
    while (upper_bound >= lower_bound)
    {
        if (needle == haystack[mid])
        {
            return true;
        }
        else if (needle < haystack[mid])
        {
            upper_bound = mid - 1;
        }
        else
        {
            lower_bound = mid + 1;
        }
        mid = lower_bound + (upper_bound - lower_bound)/2;
    }
    if (lower_bound > upper_bound)
    {
        return false;
    }
}

int main(void)
{
    int numbers[SIZE] = { 4, 8, 15, 16, 23, 42, 50, 108 };
    printf("> ");
    int n = get_int("input number: "); 
    if (search(n, numbers, SIZE))
    {
        printf("YES\n");
    }
    else 
    {
        printf("NO\n");
    }
}