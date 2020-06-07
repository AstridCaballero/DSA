#include <stdio.h>

int main(void)
{
   int n = 50;
   int *p = &n;
   // prints the address where 50 is stored
   printf("%p\n", &n);
   // Prints the pointer value which is the address where 50 is stored
   printf("%p\n", p);
   // GOES TO p and prints the value inside the address
   printf("%d\n", *p);
   // GOES TO the address storing the value n and prints the value inside that address
   printf("%i\n", *&n);
}