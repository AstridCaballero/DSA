#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
    int n, i, j;
    char *arr;

    printf("enter length of word: ");
    scanf("%i", &n);
    n = n + 1;
    arr = malloc(n);
    for (i = 0; i < (n - 1); i++)
    {
        printf("Enter letter in position %i: ", i + 1);
        // add a space before %c for scanf to work. https://stackoverflow.com/questions/3744776/simple-c-scanf-does-not-work
        scanf(" %c", &arr[i]);
        printf("\n");
    }
    char (*list)[n] = malloc(sizeof(char[n][n]));
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (j == i)
            {
                list[i][j] = toupper(arr[j]);
            }
            else
            {
                list[i][j] = arr[j];
            }            
        }
    }
    // print
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%c", list[i][j]);
        }
        printf("\n");
    }
    free (arr);
    free (list);
    return 0;
}