#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * compress(char *S);

int main(void)
{
    char S[7] = {'a','a','a','b','e','e','f'};
    char *S_2 = compress(S);
    int i;
    for (i = 0; i < 7; i++)
    {
        printf("%c ", S_2[i]);
    }
    printf("\n");
    return 0;
}

char * compress(char *S)
{
    int len = strlen(S);
    int counter = 1;
    int i, j;
    int temp = S[0];
    char count;
    char *new_S = malloc(len);
    for (i = 0, j = 1; j < len; j++)
    {        
        if (temp == S[j])
        {
            counter ++;
        }
        else
        {
            new_S[i] = temp;
            i++;
            if (counter != 1)
            {
               count = counter + '0';
               new_S[i] = count;
               i++;
            }            
            temp = S[j];
            counter = 1;
        }  
    }
    new_S[i] = temp;
    if (counter != 1)
    {        
        count = counter + '0';
        new_S[i + 1] = count;
    }    
    return new_S;
}