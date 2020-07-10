#include <stdio.h>
#include <stdlib.h>

// this code needs to improve the size of the output array
// at the moment has the size of len_a + len_b
// but if there are dupes the output array should be smaller.

int * unique(int *array_a, int *array_b, int len_a, int len_b);

int main(void)
{
    int i;
    int B[3] = {1, 3, 5};
    int A[2] = {3, 4};
    int *C = unique(A, B, 2, 3); 
    for (i = 0; i < 5; i++)
    {
        printf("%i ", *(C + i));
    }
    printf("\n");
    free(C);
    return 0;
}

int * unique(int *array_a, int *array_b, int len_a, int len_b)
{
  int i, j, k;
  int *new_array = malloc((len_a + len_b) * sizeof(int));
  for (i = 0, j = 0, k = 0; i < len_a && j < len_b ; k++)
  {
      if (array_a[i] < array_b[j]) 
      {
          new_array[k] = array_a[i]; 
          i++;                  
      }
      else if (array_a[i] > array_b[j])
      {
          new_array[k] = array_b[j];
          j++;         
      }
      else
      {
          new_array[k] = array_a[i];
          i++;
          j++;         
      }
  }
  if (i == len_a)
  {
      for (; j < len_b; j++, k++)
      {
          new_array[k] = array_b[j];
      }
  }
  else //(j == (len_b - 1))
  {
      for (; i < len_a; i++, k++)
      {
          new_array[k] = array_a[i];
      }
  }
  return new_array;
}