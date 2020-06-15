#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    char *arr;
    printf("enter length of string: ");
    scanf("%i", &n);
    n = n + 1;
    arr = malloc(n);
    for (i = 0; i < n - 1; i++)
    {
        printf("enter letter in position %i: ", i + 1);
        scanf(" %c", &arr[i]);
    }
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
        {
            switch (arr[i])
            {
            case 'a':
                arr[i] = '1';
                break;
            case 'e':
                arr[i] = '2';
                break;
            case 'i':
                arr[i] = '3';
                break;
            case 'o':
                arr[i] = '4';
                break;
            case 'u':
                arr[i] = '5';
                break;            
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
    free (arr);
    return 0;
}