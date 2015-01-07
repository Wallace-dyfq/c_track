/*
 * CS 11, C Track, lab 7
 *
 * FILE: hash_table.c
 *
 *       Implementation of the hash table functionality.
 *
 */

/*
 * Include the declaration of the hash table data structures
 * and the function prototypes.
 */

/* todo array as pointer could not be index like a[i], use a+i instead  */
/* be careful when comparing char *. need to use strcmp instead of == */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"
#include "memcheck.h"


/*** Hash function. ***/

int hash(char *s)
{
  char * p = s;
  int hashed_value;
  hashed_value = 0;
  /* while (*p != '0') */
  /* { */
  /*   hashed_value += *p; */
  /* } */
  int i;
  for(i = 0; i < strlen(s); ++i)
    hashed_value += p[i];
  
  hashed_value = hashed_value % NSLOTS;
  return hashed_value;
}


/*** Linked list utilities. ***/

/* Create a single node. */
node *create_node(char *key, int value)
{
  node *result = (node *)malloc(sizeof(node));
  /* check if memory is enough */
  if (result == NULL)
  {
    fprintf(stderr, "Fatal Error: Out of Memory. "
            "Terminating program. \n");
    exit(1);
  }
  result->key = key;
  result->value = value;
  result->next = NULL;
  return result;
}


/* Free all the nodes of a linked list. */
void free_list(node *list)
{
  node *n;
  while(list != NULL)
  {
    n = list;
    list = list->next;
    /* 'n' now points to the first element of the list
     while 'list' now points to everythin but the first
    element. Since nothing points to 'n', it can be freed */
    free(n->key);
    
    free(n);
  }

}


/*** Hash table utilities. ***/

/* Create a new hash table. */
hash_table *create_hash_table()
{
  
  hash_table *ht = (hash_table *)malloc(sizeof(hash_table));
  
  /* check if memory is enough */
  if (ht == NULL) {
    fprintf(stderr, "Fatal Error: Out of Memory. "
            "Terminating program. \n");
    exit(1);
  }
  int i;
  ht->slot = (node * *)malloc(sizeof(node*) * NSLOTS);
  

  node **tmp = ht->slot;

  for(i = 0; i < NSLOTS; ++i)
  {
    
    *tmp = NULL;
    tmp ++;
  }
    
  return ht;
}


/* Free a hash table. */
void free_hash_table(hash_table *ht)
{
  /* free the list in each slot */
  int i ;
  node **tmp = ht->slot;
  
  for (i = 0; i < NSLOTS; ++i)
  {
    node *tmpnode = *tmp;
    tmp++;
    free_list(tmpnode);  /* !!! */
 
  }

  /* free the hash table itself */
  free(ht->slot);
  free(ht);

}


/*
 * Look for a key in the hash table.  Return 0 if not found.
 * If it is found return the associated value.
 */
int get_value(hash_table *ht, char *key)
{
  int hashed_value = hash(key);
  /* printf("%s has hased value %d\n", key, hashed_value); */
  node *tmp = *(ht->slot + hashed_value);
  while(tmp != NULL)
  {
   
   
    if (strcmp(tmp->key, key) != 0)

    {
       tmp = tmp->next;

    }
    else
    {
      /* printf("%s has value: %d\n", tmpkey, tmp->value); */
      return tmp->value; 
    }
    
  }
  /* not found, return 0 */
  return 0;

}


/*
 * Set the value stored at a key.  If the key is not in the table,
 * create a new node and set the value to 'value'.  Note that this
 * function alters the hash table that was passed to it.
 */
void set_value(hash_table *ht, char *key, int value)
{
  int key_exist = get_value(ht, key);
  int hashed_value = hash(key);
  node **tmp =  ht->slot + hashed_value;
  if (key_exist != 0)
  {
    /* need to find the node with the same key */
     node *tmpnode = *tmp;
    /* while (tmpnode->key != key) */
     while(strcmp(tmpnode->key, key) != 0)
    {
      tmpnode = tmpnode->next;
    }
     free(key);
    tmpnode->value = value;
  }

  else  /* key not exist */
  {     /* create a new node and place in the first of the list */
    node * new_node = create_node(key, value);
    new_node->next = *(ht->slot + hashed_value);
    *( ht->slot + hashed_value) = new_node;
  }

}


/* Print out the contents of the hash table as key/value pairs. */
void print_hash_table(hash_table *ht)
{
  int i;
 
  node *cur;
  for(i = 0; i < NSLOTS; ++i)
  { cur = *(ht->slot + i);
    while(cur != NULL){
      printf("%s %d\n", cur->key, cur->value);
      cur = cur->next;
    }
  }
}


