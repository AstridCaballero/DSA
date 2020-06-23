#include <stdio.h>
#include <stdlib.h>

int int_Compare (const void *a, const void *b);

int main(void)
{
    int i, dupe;
    int n = 5;
    int count;
    int list[5] = {4,3,2,3,1};
    qsort(list, 5, sizeof(int), int_Compare);
    printf("%i", list[n - 1]);
    dupe = list[n - 1];
    count = 1;
    for (i = n - 2; i >= 0; i--)
    {
        if (list[i] != dupe)
        {
            printf("%i", list[i]);
            dupe = list[i];
            count ++;
        }
        if (count == 3)
        {
            break;
        }
    }
    printf("\n");
    return 0;
}

int int_Compare(const void *a, const void *b) 
{
    const int *ya = (const int *)a;
    const int *yb = (const int *)b;

    /* integer comparison: returns negative if b > a 
	and positive if a > b */ 
    return *ya - *yb;
}