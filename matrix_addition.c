# include <stdio.h>
# include <stdlib.h>

int main(void)
{
    // Prepare variables
    int i, j;
    // 3x3 matrix
    int r = 3;
    int c = 3;
    // create matrix variable and allocate memory
    int (*m_1)[c] = malloc(sizeof(int[r][c]));
    int (*m_2)[c] = malloc(sizeof(int[r][c]));
    int (*sum)[c] = malloc(sizeof(int[r][c]));

    // get data into matrices and make addition
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("enter value in first matrix: ");
            scanf("%i", &m_1[i][j]);
            printf("enter value in second matrix: ");
            scanf("%i", &m_2[i][j]);
            // amke addition
            sum[i][j]= m_1[i][j] + m_2[i][j];
        }
    }
    // print
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            printf("%i ", sum[i][j]);
        }
        printf("\n");
    }
    
    free (m_1);
    free (m_2);
    free (sum);
    return 0;
}