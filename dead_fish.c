#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    int c = 0;
    int count = 0;
    char *arr;
    int *list;

    printf("Enter lenght of string: ");
    scanf("%i", &n);
    n = n + 1;
    arr = malloc(n);
    list = malloc(n * sizeof(n));

    for (i = 0; i < n - 1; i++)
    {
        printf("Enter command %i: ", i + 1);
        scanf(" %c", &arr[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        switch (arr[i])
        {
        case 'i':
            c++;
            break;
        case 'd':
            c--;
            break;
        case 's':
            c = c * c;
            break;
        case 'o':
            list[count] = c;
            count++;
            break;
        }
    }
    // print
    for (i = 0; i < count; i++)
    {
        printf("%i ", list[i]);
    }
    printf("\n");
    free (arr);
    free (list);
    return 0;
}