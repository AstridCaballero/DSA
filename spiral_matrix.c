#include <stdio.h>
#include <stdlib.h>

// parameter matrix goes after the parameters that give the size of the matrix
// 'size' parameter is declared first than 'matrix' 
void spiral(int size, char (*matrix)[size]);

int main(void)
{
    int i, j;
    int n = 2;
    char (*matrix)[n]= malloc(sizeof(char[n][n]));
    if (matrix == NULL)
    {
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("enter char: ");
            scanf(" %c", &matrix[i][j]);
        }
    }
    spiral(n, matrix);
    free(matrix);
    return 0;
}

// parameter matrix goes after the parameters that give the size of the matrix
// 'size' parameter is declared first than 'matrix'
void spiral(int size, char (*matrix)[size])
{
    int i, j, x, y, new_x, new_y;
    int first = 0;
    int last = size - 1;

    x = size / 2;
    if (size % 2 != 0)     
        y = x;   
    else   
        y = x - 1;

    new_x = 0;
    new_y = 0;
    // while NOT (new_x and new_y are equal to (x,y))
    while (!(new_x == x && new_y == y))
    {
        // traverse to the right
        for (i = first; i <= last; i++)
        {
            printf("%c ", matrix[first][i]);
            new_x = first;
            new_y = i;            
        }
        // update 'first' (upper and left bound)
        first++;
        // traverse to the bottom
        for (j = first; j <= last; j++)
        {
            printf("%c ", matrix[j][last]);
            new_x = j;
            new_y = last;            
        }
        // update 'last' (lower and right bound)
        last--;
        // traverse to the left
        for (i = last; i >= first - 1; i--)
        {
            printf("%c ", matrix[last + 1][i]);
            new_x = last + 1;
            new_y = i;
        }
        // traverse to the top
        for (j = last; j >= first; j--)
        {
            printf("%c ", matrix[j][first - 1]);
            new_x = j;
            new_y = first - 1;
        }
    } 
    printf("\n"); 
}