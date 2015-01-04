#include <stdio.h>

int main() {
  int Y;
  /* given the year for which the date of Easter is to be determined. */
  while(1) {
   
    int result; 
    result = scanf("%d", &Y);
    if (result == EOF)
      break;
    int G;
    G = (Y % 19) + 1;

    /* C is the century */
    int C;
    C = Y / 100 + 1;

    /* X is the skipped leap years */
    int X;
    X = 3 * C / 4 - 12;

    /* Z is a correction factor for the moon's orbit. */
    int Z;
    Z = (8 * C + 5) / 25 - 5;

    /* March ((-D) mod 7 + 7) is a Sunday. */
    int D;
    D = (5 * Y / 4)- X - 10;

    /* E is the "epact" which specifies when a full moon occurs. */
    int E;
    E = (11 * G + 20 + Z - X) % 30;

    if ( (E == 25 && G > 11) ||  E == 24)
      E++;

    /* March N is a "calendar full moon".
       If N is less than 21 then add 30 to N.
    */
    int N;
    N = 44 - E;
    if (N < 21)
      N += 30;
    /* N is a Sunday after full moon. */
    N = N + 7 - ((D + N) % 7) ;

    if (N > 31)
      printf("%d - April %d\n", Y, N - 31);
    else
      printf ("%d - March %d\n", Y, N);
  }
  
  return 0;

}
