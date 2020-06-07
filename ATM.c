#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int is_number(char *arr[]);

int main(int argc, char *argv[])
{    
    float balance;
    int w;
    //Check if argv[] exits
    if(argc == 3)
    {
        int d = is_number(argv);        
        if (d == 0)
        {
            balance = atof(argv[2]);
            w = atoi(argv[1]);               
        }
        else
        {
            printf("Usage: input numbers only\n");
            return 1;
        }        
    }
    else
    {
        printf("Usage: input amount to withdraw and balance\n");
        return 2;
    }    
    
    float charge = 0.50;    
    if ((balance - charge >= w))
    {
        if (w % 5 == 0)
        {
            balance = balance - charge - w;              
            printf("%.2f\n", balance);
        }  
        else
        {
            printf("%.2f\n", balance);
        }       
    }
    else
    {
        printf("%.2f\n", balance);
    }       
}

//Check argv[] has only digits
int is_number(char *arr[])
{
    int arg_array = 3;
    int i;
    for (i = 1; i < arg_array; i++)
    {               
        char *ptr;
        double test;
        // strtod converts the string pointed to by the argument str to a floating-point number (type double)
        test = strtod(arr[i], &ptr);
        if (!isspace( *ptr ) && *ptr != 0)
        {
            // input was not a valid float
            return 3;
            break;
        }              
    }
    return 0;   
}