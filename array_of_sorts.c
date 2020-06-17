#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m, i, j;
    char *arr;
    char *key_arr;
    char *tem;
    int count = 0;

    printf("Enter size of string to sort: ");
    scanf("%i", &n);
    n = n + 1;
    arr = malloc(n * sizeof(char));
    tem = malloc(n * sizeof(char));

    for (i = 0; i < n - 1; i++)
    {
        printf("enter letter in position %i: ", i + 1);
        scanf(" %c", &arr[i]);
    }

    printf("Enter size of the string key: ");
    scanf("%i", &m);
    m = m + 1;
    key_arr = malloc(m * sizeof(char));

    for (i = 0; i < m - 1; i++)
    {
        printf("enter letter in position %i: ", i + 1);
        scanf(" %c", &key_arr[i]);
    }

    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (arr[j] == key_arr[i])
            {
                tem[count] = arr[j];
                count++;
            }
        }
    }
    // print
    for (i = 0; i < n; i++)
    {
        printf("%c", tem[i]);
    }
    printf("\n");
    free (arr);
    free (key_arr);
    free (tem);

    return 0;
}