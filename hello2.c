#include <stdio.h>

int main() {
  printf ("Enter your name: !\n");
  char s[100];
  scanf("%99s", s);
  printf("Hello %s!\n", s);
  return 0;
}
