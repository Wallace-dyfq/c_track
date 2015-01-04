#include <stdio.h>
#include <stdlib.h>  /* atoi */
#include <string.h> /* strcmp */
#include <assert.h> /* assert */

#define MAXIMUM 32
/* arr be the array of integers, and num be the total number of elements in array, b = 0 -> minimum sort, b = 1 -> bubble sort */
void sorter(int arr [], int num, int b);

void minimum_sort(int arr [], int num);

void bubble_sort(int arr [], int num);

void display(int arr[], int num);

void swap(int * a , int * b) ;

int main(int argc, char * argv[] ) {

  int bubble = 0; /* if set to 1, use buble sort instead of minimum sort*/
  int quiet = 0;  /* if set to 1, supress the output */
  int i;
  int arr[MAXIMUM];
  int count = 0;  /* count the number of int */
  for (i = 1; i < argc; ++i)
  {
    if (strcmp(argv[i], "-b") == 0 )
    {
      bubble = 1;
    }
    else if (strcmp(argv[i], "-q") == 0 )
    {
      quiet = 1;
    }
    else /* put int element into the array*/
    {
      if (count >= MAXIMUM)
      {
        fprintf(stderr, "usage: %s filename should not take in more than %d number of integers. [Maximum 32]", argv[0], MAXIMUM);
        exit(1);
      }
      arr[count] = atoi(argv[i] );
      count++;
    }

  }

  if (count <= 0)
  {
    fprintf(stderr, "usage: %s filename should not take in some number of integers. [Maximum 32]", argv[0], MAXIMUM);
    exit(1);
  }
    



 

  /* printf("take in total %d numbers of integer\n", count); */
  /* printf("\t before sorting!\n"); */
  sorter(arr, count, bubble);
  /* printf("\t after sorting!\n"); */

  
  if (quiet != 1)
    display(arr, count);
  return 0;
}


void sorter(int arr[], int num, int b) {

  if (b ==1 )
    bubble_sort(arr, num);
  else
    minimum_sort(arr, num);

  /* Check that the array is sorted correctly. */
  int i;
  for ( i = 1; i < num; i++)
  {
    assert(arr[i] >= arr[i-1]);
  }

}

void minimum_sort(int arr [], int num){
  /* printf("called minimum_sort\n"); */
  int start;
  for ( start = 0; start < num; ++start)
  {  int smalleast = start, index;
    for ( index = start+1; index < num; index++)
    {  if (arr[index] < arr[smalleast])
        smalleast = index;
    }
    swap(arr + smalleast, arr + start);
  }
}

void bubble_sort(int arr [], int num) {
  /* printf("called bubble sort\n"); */
  while (1)
  {
    int  swapped = 0; /* 0 ->false. 1 -> true*/
    int i;
    for( i = 1; i < num; ++i)
    {
      if (arr[i-1] > arr[i])
      {
        swap(arr + i - 1, arr + i);
        swapped = 1;
      }
    }
    if (swapped == 0)
      break;
  }
}

void display(int arr[], int num)
{
  int i;
  for ( i = 0; i < num; ++i)
    printf("%d\n", arr[i]);
}

void swap(int * a , int * b) {
  int tmp = *b;
  *b = *a;
  *a = tmp;
}
