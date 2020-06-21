#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned int hash(unsigned int x, int m); 
bool isPrime(int n); 
int nextPrime(int N); 

int main(void)
{
    // prepare variables
    int p, i, j, year, m; 
    unsigned int index;  
    int val_year, val_count, val_test;     
    
    // Get data
    printf("Input number of people: ");
    scanf("%i", &p);
    // Store date
    int (*people)[2] = malloc(sizeof(int[p][2]));
    if (people == NULL)
    {
        return 1;
    }
    // define size of hash table 'm'
    // http://cseweb.ucsd.edu/~kube/cls/100/Lectures/lec16/lec16-8.html
    // '1.3 times the maximum number of keys (people * 2) that will actually be in the table'
    // and m must be a prime number
    m = (p * 2) * 1.3;
    // get the next prime number after 'm'   
    m = nextPrime(m);

    // hash table, the idea was to have only one column but as I don't know at the moment how to 
    // reverse engineer the hash value to get the year I am creating a 2D array instead
    // so I store the year in the first column, and the counts of people alived in the scond column.
    // using and array of pointers to integers:
    int (*years)[2] = malloc(sizeof(int[m][2]));   
    // set hash table to zero
    memset(years, 0, m * sizeof(*years)); 
    // val_test = years[6][1];

    // // if the array is an array of integers then:
    // int years[m][2];
    // memset(years, 0, sizeof(years));
    // val_test = years[6][1];
   
    for (i = 0; i < p; i++)
    {        
        printf("Enter DOB year: ");
        scanf("%i", &people[i][0]);        
        printf("Enter DOD year: ");
        scanf("%i", &people[i][1]);
        val_test = people[i][1]; 
    }

    // loop each year in people and add +1 in hash table years if person is alived
    for (i = 0; i < (2 * p); i++)
    {
        if( i < p)
        {
            // cheking DOB over the array people
            year = people[i][0]; 
            // hash the yearxs
            index = hash(year, m);
            // Only use unique values of 'year', to avoid checking the same year more than once
            // so if a 'year' has been already compare the value in years[index][1] will be != 0
            if (years[index][0] == 0)
            {
                // loop each person 
                for (j = 0; j < p; j++)
                {
                    // check if person is alive
                    if(people[j][0] <= year && people[j][1] >= year)
                    {
                        // Add 1 to value at the index location in the hash table
                        years[index][1] += 1;
                        // Don't know yet how to reverse engineer the has value so for now I will have to
                        // store the year in the hash table as well
                        years[index][0] = year;
                        val_year = years[index][0];
                        val_count = years[index][1];
                    }
                }
            }
        }
        else
        {
            // Checking over the DOD over the array people again
            year = people[i - p][1];
            // hash the year
            index = hash(year, m);
            // Only use unique values of 'year', to avoid checking the same year more than once
            // so if a 'year' has been already compare the value in years[index][1] will be != 0
            if (years[index][1] == 0)
            {
                // loop each person 
                for (j = 0; j < p; j++)
                {
                    // check if person is alive
                    if(people[j][0] <= year && people[j][1] >= year)
                    {                        
                        // Add 1 to value at the index location in the hash table
                        years[index][1] += 1;
                        // Don't know yet how to reverse engineer the has value so for now I will have to
                        // store the year in the hash table as well
                        years[index][0] = year;
                        val_year = years[index][0];
                        val_count = years[index][1];
                    }
                }
            }
        }     
    }
    // loop hash table and find highest number
    j = years[0][1];

    for (i = 1; i < m; i++)
    {
        if (j < years[i][1])
        {
            j = years[i][1];
        }
    } 
    printf("the highest population was %i in year(s): ", j);
    // loop hash table again and get the index if it has the highest value
    // I would reverse engineer the index value to get the year but at the moment I don't know how to do it
    // so I will get the year from the first column of my 2D array years.
    for (i = 0; i < m; i++)
    {
        if (years[i][1] == j)
        {
            printf("%i ", years[i][0]);
        }
    }
    printf("\n");
    free (people);   
    return 0;
} 

// hash function for integers
// https://www.coursera.org/lecture/data-structures/hashing-integers-mW2wn
unsigned int hash(unsigned int x, int m) 
{
    // years have a lenght of four digits, so 10^4
    // pick a prime number > 10^4
    int p = 10019;
    // get size of hash table 'm'    
    // get randon 'a' value range[1, p - 1] and 'b' value range [0, p - 1]
    int a = 34;
    int b = 2;
    x = ((a * x + b) % p) % m;    
    return x;
}

// https://www.geeksforgeeks.org/program-to-find-the-next-prime-number/
// Function that returns true if n  
// is prime else returns false  
bool isPrime(int n)  
{  
    int i;
    // Corner cases  
    if (n <= 1)  return false;  
    if (n <= 3)  return true;  
    
    // This is checked so that we can skip   
    // middle five numbers in below loop  
    if (n % 2 == 0 || n % 3 == 0) return false;  
    
    for (i = 5; i * i <= n; i = i + 6)  
        if (n % i == 0 || n % (i + 2) == 0)  
           return false;  
    
    return true;  
}  

// https://www.geeksforgeeks.org/program-to-find-the-next-prime-number/
// Function to return the smallest 
// prime number greater than N 
int nextPrime(int N) 
{   
    // Base case 
    if (N <= 1) 
        return 2; 
  
    int prime = N; 
    bool found = false; 
  
    // Loop continuously until isPrime returns 
    // true for a number greater than n 
    while (!found) { 
        prime++; 
  
        if (isPrime(prime)) 
            found = true; 
    } 
  
    return prime; 
} 