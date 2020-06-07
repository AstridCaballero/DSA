/*
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int get_withdraw(char *prompt);
int is_number(char *arr[]);

//Check argv[] has only digits
int is_number(char *arr[])
{
    int arg_array = 3;
    for (int j = 1; j < 3; j++)
    {
        // check if first number is int
        if ( j == 1)
        {
            int l = strlen(arr[j]);
            for (int i = 0; i < l; i++)
            {
                if (isdigit(arr[j][i]) == false)
                {
                    return 1;
                    break;
                }      
            }
        }
        // checks if second number is float
        else
        {
            char *ptr;
            double test;
            test = strtod(arr[j], &ptr);
            if (!isspace( *ptr ) && *ptr != 0)
            {
                return 1;
                break;
            }              
    }
    return 0;   
}

// prompt user for amount to withdraw
int get_withdraw(char *prompt)
{
    int n;
    do
    {
        n = get_int("%s", prompt);

    } while ((n < 0 && n > 2000) || (n % 5 != 0));
    return n;    
}
*/
