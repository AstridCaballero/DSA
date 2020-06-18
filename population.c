#include <stdio.h>
#include <stdlib.h>

int int_Compare (const void *a, const void *b);

int main(void)
{
    // prepare variables
    int n, p, i, j;
    int count = 0;
    
    // Get data
    printf("Input number of people: ");
    scanf("%i", &p);
    // Store date
    int (*people)[2] = malloc(sizeof(int[p][2]));
    if (people == NULL)
    {
        return 1;
    }
    int *years = malloc(p * 2 * sizeof(int));
    if (years == NULL)
    {
        return 1;
    }
    for (i = 0; i < p; i++)
    {        
        printf("Enter DOB year: ");
        scanf("%i", &people[i][0]);        
        printf("Enter DOD year: ");
        scanf("%i", &people[i][1]);          
        // Add half of the total years to the array years (DOB)
        years[i] = people[i][0];          
    }
    // Add the other half number of years to the array years (DOD)     
     for (i = p, j = 0; i < 2 * p; i++, j++)
     {        
        years[i] = people[j][1];                
     }
     // sort years with qsort
     qsort(years, 2 * p, sizeof(int), int_Compare);

    // // count number of unique years
    for (i = 0; i < (2 * p) - 1; i++)
    {               
        if (years[i] < years[i + 1])
        {
            count += 1;                        
        }            
    }   
    // add 1 to the total count to include the last element
    count = count + 1;    

    // create array with unique sorted values
    int *u_years = malloc(count * sizeof(int));
    if (u_years == NULL)
    {
        return 1;
    }
   
    for (i = 0; i < ((2 * p) - 1); i++)
        {         
        if (years[i] != years[i + 1] && n < count)
        {
            u_years[n] = years[i];
            n = n + 1;       
        } 
        else
        {
            n = i;
        }        
    }    
   
    // add last elemnt of array years
     u_years[count - 1] = years[(2 * p) - 1];

    for (i = 0; i < count; i++)
    {
        printf("%i\n",u_years[i]);
    }

    // get the population per year
    int *pop_year = malloc(count * sizeof(int));
    if (pop_year == NULL)
    {
        return 1;
    }
    int c;
    for (i = 0; i < count; i++)
    {        
        c = 0;
        for (j = 0; j < p; j++)
        {
            if(people[j][0] <= u_years[i] && people[j][1] >= u_years[i])
            {                
                // printf("year[%i]: DOB:%i DOD:%i\n", u_years[i], people[j][0], people[j][1]);
                c ++;                
            }           
        }
        pop_year[i] = c;                
    }
    for (i = 0; i < count; i++)
    {
        printf("%i: %i\n", i, pop_year[i]);
    }
    c = pop_year[0];
    for (i = 1; i < count; i++)
    {
        if (c < pop_year[i])
        {
            c = pop_year[i];
        }              
    }
    // Display output
    printf("The heighest population was: %i in year(s):\n", c);

    for (i = 0; i < count; i++)
    {
        if(pop_year[i] == c)
        {
            printf("%i\n", u_years[i]);
        }
    }
    free (pop_year);
    free (people);
    free (years);
    free (u_years);
    return 0;
} 

int int_Compare(const void *a, const void *b) 
{
    const int *ya = (const int *)a;
    const int *yb = (const int *)b;

    /* integer comparison: returns negative if b > a 
	and positive if a > b */ 
    return *ya - *yb;
}