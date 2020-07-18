#include <stdio.h>
#define COL 100

/* this program creates groups of children (maximum 100) with age difference of 2 years
 eahc line printed represents a group. And each number in the line represents the 
 age of each child in the group*/

// create a struct to have an array of arrays or a list of lists
// https://www.quora.com/How-do-I-put-an-integer-array-inside-another-array-in-C
typedef struct
{
    int iarray[COL];
}iarray_struct;

void iarray_init(iarray_struct *iarray, int rows, int arr[]);

int main(void)
{
  int ages[6] = {1, 3, 6, 6, 8, 9};
  iarray_struct new_array[6]= {0};
  iarray_init(new_array, 6, ages);
  return 0;
}

void iarray_init(iarray_struct *iarray, int rows, int arr[])
{
    int i, j;
    // the code will iterate based on the number of children, represented by the rows
    // if all the children have an age within 2 years then there will be only one group with 'n' elements
    // if none of the children have an age within 2 years then there will be 'n' groups of one element
    int n = rows;
    // index_left represents the lower bound (minimum age) of each segment
    int index_left = 0;
    int x, y;        
    // iterate over each row, which will represent a list
    for (i = 0; index_left < n; i++)
    {
        x = arr[index_left];
        y = x + 2;
        // iterate over each column, which will represent the age of a child
        // starting at the minimum age of each segment
        for (j = index_left; j < n; j++)
        {
            if (arr[j] <= y)
            {
                iarray[i].iarray[j] = arr[j];
                printf("%i", arr[j]);
            }
            else
            {
                break;
            }                            
        }
        index_left = j;
        printf("\n");
    }       
}