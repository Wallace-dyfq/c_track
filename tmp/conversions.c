#include <stdio.h>

int main()
{
  int i, j;
  double d;

  i = 3;
  j = 4;
  d = i / j;
  printf(" d = i / j = %f\n", d);

  d = ((double) i) / ((double) j) ;
  printf(" d = ((double)) i / ((double) j) = %f\n", d);


  return 0;
}
