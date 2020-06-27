#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int * get_arr(int n);
int nextPrime(int N);
bool isPrime(int n);
int hash(int n, int m);

int main(void)
{
    int i;
    int n;
    int index;
    int k;
    int x;
    int y;
    int hash_x;
    int hash_y;
    int count = 0;
    // get data from user
    printf("Enter length of array: ");
    scanf("%i", &n);
    int *arr = malloc(n * sizeof(int));
    arr = get_arr(n);
    // create hash table. max lenght of number is 99 so max lenght is 10^2 - 1
    int m = 100;    
    int *hash_table = malloc(m * sizeof(int));    
    for (i = 0; i < n; i++)
    {
        index = hash(arr[i], m);
        hash_table[index] = arr[i];
    }
    /* get pairs of integers that have difference k */
    // get the difference value
    printf("Enter the difference: ");
    scanf("%i", &k);
    for (i = 0; i < n - 1; i++)
    {
        x = arr[i] - k;
        y = arr[i] + k;
        hash_x = hash(x, m);
        hash_y = hash(y, m);
        if (x == hash_table[hash_x] && (x != 0))
        {
            printf("%i, %i\n", x, arr[i]);
            count ++;
        }
        else if (y == hash_table[hash_y] && (y != 0))
        {
            printf("%i, %i\n", arr[i], y);
            count ++;
        }
    }
    printf("The number of pair of integers that have difference of k = %i is %i\n", k, count);
    return 0;
}

int * get_arr(int n)
{
    int i;
    int * arr = malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        printf("Enter integer number from 1 up to 99: ");
        scanf("%i", &arr[i]);
    }
    return arr;
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

int hash(int n, int m)
{    
    int a, b, p, x;
    // numbers will be from 0 to 99 so the max lenght is (10^2 - 1), 
    // p will be next prime number after 10^2
    p = nextPrime(100);
    a = 34;
    b = 2;
    x = ((a * n + b) % p) % m;
    return x;
}