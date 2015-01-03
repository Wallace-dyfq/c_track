#include <stdio.h>  /* printf, scanf, puts, NULL */
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
int main() {
  printf ("Enter your name: !\n");
  char s[100];
  scanf("%99s", s);
  srand(time(NULL));
  
  int n;
  n = rand() % 10 + 1;
  int i = 1;
  while (i++ <= n)
  {
    if (n % 2 != 0)
      printf("%d: hello, %s!\n",n, s);
    else
      printf("%d: hi there, %s!\n", n ,s);
  }
  
  return 0;
}
