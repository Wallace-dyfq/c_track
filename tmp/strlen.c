#include <stdio.h>
#include <string.h>

int main ()
{
   char str[50];
   int len;

   strcpy(str, "a");

   len = strlen(str);
   printf("Length of |%s| is |%d|\n", str, len);
   printf("a in int is %d \n", 'a');
   
   return(0);
}
