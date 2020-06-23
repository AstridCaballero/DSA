#include <stdio.h>

int main(void)
{
    int i, j;
    int sum = 0;
    int set[2][2]={{1,3},{1,8}};
    for (i = 0; i < 2; i++)
    {        
        sum += set[i][0];        
    }
    printf("%i\n", sum);
    return 0;
}

