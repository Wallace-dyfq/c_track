#include <stdio.h>

int main()
{
  int my_array[10];
  for (int i = 0; i< 10; ++i)
      printf("my_array[%d] = %d\n", i, my_array[i]);

  int my_array2[10] = {1, 2, 3, 4, 5};
  
  for (int i = 0; i< 10; ++i)
    printf("my_array2[%d] = %d\n", i, my_array2[i]);

  return 0;
}
