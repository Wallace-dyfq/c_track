#include <stdio.h>
#include <stdlib.h>  /* atoi */
#include <string.h> /* strcmp */
#include <assert.h> /* assert */
#include "linked_list.h"
#include "memcheck.h"

node * quicksort(node * list);

int main(int argc, char* argv[] )
{

  int i;
  int quiet = 0;  /* if quiet == 1 then supress the output */
  node *list;
  node *tmp, *prev;
 
 
  int first;  /* see if any integer has been entered */
  first = 1;

  /* read in element */
  for (i = 1; i < argc; ++i)
  {
    if (strcmp(argv[i], "-q") == 0)
      quiet = 1;
    else
    {
      
      if(first)  /* first node, we create a
                    list (pointing it to the first node */
      {
        /* list->data = atoi(argv[i]); */
        /* list->next = NULL; */
        list = create_node(atoi(argv[i]), NULL);
        prev = list;
        first = 0;
      }
      else
      {
        /* tmp = (node*) malloc(sizeof(node)); */
        /* /\* check for malloc failure *\/ */
        /* if (tmp == NULL)  /\* malloc failure *\/ */
        /* { */
        /*   fprintf(stderr, "Error: malloc() failed.\n"); */
        /*   exit(1); */
        /* } */
        /* tmp->data = atoi(argv[i]); */
        /* tmp->next = NULL; */
        /* prev->next = tmp; */
        /* prev = tmp; */

        /* use provided functions */
        tmp = create_node(atoi(argv[i]), NULL);
        prev->next = tmp;
        prev = tmp;
                          
                          
      }
    }
  }
  /* if no integers are entered */
  if (first == 1)
  {
    fprintf(stderr, "usage: %s need you to enter some
      integers (at least one) to sort them!\n", argv[0]);
    exit(1);
  }

  node * sorted = quicksort(list);
  if (quiet == 0)
  {
    print_list(sorted);  /* let's see what have been entered. */
  }

  
  free_list(list);
  free_list(sorted);
  print_memory_leaks();
  return 0;
}
  
  
node*  quicksort(node *list) {
  /* If the list has zero nodes (i.e. it's empty) or one node, 
     copy the list as is and return it (it iss already sorted). 
     Note that this algorithm works fine on empty lists. */
  if (list == NULL )
    return list;

  /* have to set these two condition apart, because if list = NULL,
     list->next would result in segmentation fault */
  else if ( list->next == NULL)
  {
    node *newnode = create_node(list->data, NULL);
    return newnode;
    
  }
  else
  {

    node *copied_first_node = create_node(list->data, NULL);
    node *new_list1 = NULL, *new_list2 = NULL;
    node *tmp_1, *tmp_2;
    node *prev_1, *prev_2;
    int first_1 = 1;
    int first_2 = 1;
    node *first = list;
    int first_data = first->data;
    first = first->next;
  
    for (; first != NULL; first = first->next)
    {
      int cur = first->data;
      if (cur < first_data)  /* put those in new_list1 */
      {
        if (first_1 == 1)
        {
          new_list1 = create_node(first->data, NULL);
          prev_1 = new_list1;
          first_1 = 0;
        }
        else
        {
          tmp_1 = create_node(first->data, NULL);
          prev_1->next = tmp_1;
          prev_1 = tmp_1;
        }
      }
    
      else  /* put those in new_list2 */
      {
        if (first_2 == 1)
        {
          new_list2 = create_node(first->data, NULL);
          prev_2 = new_list2;
          first_2 = 0;
        }
        else
        {        
          tmp_2 = create_node(first->data, NULL);
          prev_2->next = tmp_2;
          prev_2 = tmp_2;
        }
      
      }

    }

   
    node * sorted_list1 = quicksort(new_list1);
     free_list(new_list1);
     
    node * sorted_list2 = quicksort(new_list2);
     free_list(new_list2);
     
    node * sorted_list_tmp = append_lists(sorted_list1, copied_first_node);
     free_list(sorted_list1);
     free_list(copied_first_node);
     
    node * sorted_list = append_lists(sorted_list_tmp, sorted_list2);
    free_list(sorted_list2);
    free_list(sorted_list_tmp);
   
    is_sorted(sorted_list);
    return sorted_list;
  }
  
}
