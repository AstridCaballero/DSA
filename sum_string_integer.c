#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mySum(char *s1, char *s2);

int main(void)
{
    char arr_1[3]= {'2','3','4'};
    char arr_2[3]= {'9','5','7'};
    mySum(arr_1, arr_2);
    return 0;
}

void mySum(char *s1, char *s2)
{
    int i;
    int len_s1 = strlen(s1);    
    char sum[len_s1];
    int sum_int;
    int carry = 0;    
    int mod;    
    for (i = (len_s1 - 1); i >= 0; i--)
    {  
        if (carry == 1)
        {
            // subtract '0' from char and it will be treated as int
            sum_int = (s1[i] - '0') + (s2[i] - '0') + 1;
        }  
        else
        {
            // subtract '0' from char and it will be treated as int
            sum_int = (s1[i] - '0') + (s2[i] - '0');  
        }
        
        if (sum_int >= 10)
        {
            mod = sum_int % 10;
            // add '0' to the int to get a char as a result
            sum[i] = mod + '0';            
            carry = 1;
        }
        else
        {
            // add '0' to the int to get a char as a result
            sum[i] = sum_int + '0';            
            carry = 0;
        }    
    }
    // create new array with space for one more element if the last sum has carry = 1
    if (carry == 1)
    {
        char final_sum[len_s1 + 1];
        // store carry in first position of array
        final_sum[0] = '1';
        // bring all numbers from sum
        for (i = 1; i < len_s1 + 1; i++)
        {
            final_sum[i] = sum[i - 1];
        }  
        printf("%s\n", final_sum);
    }
    else
    {
        printf("%s\n", sum);
    }
    
    // sum = (s1[0] - '0') + (s2[0] -'0');
    // char number = sum + '0';      
    // printf("%i\n", sum);
    // printf("%c\n", number);    
}