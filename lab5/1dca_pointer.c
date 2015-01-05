#include <stdlib.h>
#include <stdio.h>  /* srand, rand */
#include <time.h>
#include "memcheck.h"
/* This function initialize the cell with number of elemenet equaling to size.
   The cell is dynamically allocated. The elements in the cell is set randomly to 0 or 1.
   0 means empty and 1 means full.
 We set the first and last cells to be always empty. */
void initialize(int arr[], int size);

/* display function print out the cell elements by element.  */
void display(int arr[], int size);

/* update the cell according to these two rules:
    If the current cell is empty, and one of the two adjacent cells is full (but not both), set the current cell to be full.
    Otherwise set the current cell to be empty.
 */
void update(int arr[], int size);


/* just display and update the cell */
void evolve(int arr[], int size, int ngenerations);

int main(int argc, char* argv[]) {

  if (argc != 3 )
  {
    fprintf(stderr, "usage %s filename requires two arguments: the numbers of cells in the 1dCA and the number of generations to compute.", argv[0]);
    exit(1);
  }

  int ncells;
  int ngenerations;
  
  ncells = atoi(argv[1]);
  ngenerations = atoi(argv[2]);

  if (ncells <= 0 || ngenerations <= 0 )
  {
    fprintf(stderr, "usage %s filename requires both positive number of cells and generations", argv[0]);
    exit(1);
  }
  int *cell;
  cell = (int *) calloc ( ncells, sizeof(int) );

  if (cell == NULL)
  {
    fprintf(stderr, "Error! Memory allocation failed!\nNot enough spaces!!!\n");
    exit(1);  /* abort the program */
  }

  initialize(cell, ncells);
  
  evolve(cell, ncells, ngenerations);

  free(cell);

  print_memory_leaks();


  return 0;
}

/* ============== Implementations ======================= */

void initialize(int arr[], int size) {

  srand(time(NULL) );
  int *p = arr;
  *p = 0;  /* the first element should always be 0 or empty*/
  p++;
  int i;
  for (i = 1; i < size-1; ++i)
  {
    *p = rand() % 2;
    p++;
  }
  *p = 0;  /* the last element should always be 0 or empty */
}

void display(int arr[], int size) {
  int *p = arr;
  int i ;
  for (i = 0; i < size; i++) {
    if ( *p  == 1)
      printf("*");
    else
      printf(".");
    p++;
  }
  printf("\n");
}


void update(int arr[], int size)
{
  int *p_p  = arr;  /* pointer before p */
  int *p = arr + 1;
  int *p_n = arr + 2;  /* point   after p */
  int i = 1;
  for(; i < size - 1; ++i)
  {
    if (*p == 0 && ( (*p_p == 0 && *p_n == 1) || (*p_p == 1 && *p_n == 0)) )
      *p = 1;
    else
      *p = 0;
  }
}
void evolve(int arr[], int size, int ngenerations) {
  int i;
  for(i = 0; i < ngenerations; i++)
  {
    display(arr, size);
    update(arr, size);
  }
}
