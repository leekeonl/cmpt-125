#include <stdio.h>
#include <stdlib.h>

#include "list.h"


// returns a pointer to a new header for an empty list, or NULL if
// memory allocation fails.
list_t* list_create( void );

// frees all the memory used by the list
void list_destroy( list_t* list );

// returns a pointer to a new list element containing integer i and
// next-pointer set to NULL, or NULL if memory allocation fails.
element_t* element_create( int i );

// Appends a new element containing integer i to the end of the
// list. Returns 0 on success, else 1.
int list_append( list_t* list, int i );

// Prepends a new element containing integer i to the head of the
// list. Returns 0 on success, else 1.
int list_prepend( list_t* list, int i );

// Returns a pointer to the ith list element, where the list head is
// 0, head->next is 1, etc., or NULL if i is out of range (i.e. larger
// than (number of list elements -1 ))
element_t* list_index( list_t* list, unsigned int i );

// Prints a list in human-readable form from the first to last
// elements, between curly braces.
void list_print( list_t* list );



list_t* list_create( void ){
  list_t* l = malloc(sizeof(list_t));
  if(l){
      l->head = NULL;
      l->tail = NULL;
}
    
  return l;
}

void list_destroy( list_t* list ){
  element_t* el = list->head;
  while(el){
      element_t* next = el->next;
      free(el);
      el = next;
}

  free(list);
}

element_t* element_create( int i ){
  element_t* el = malloc(sizeof(element_t));
  if(el){
      el->next = NULL;
      el->val = i;
    }
  return el;
}


int list_append( list_t* list, int i ){
  element_t* el = element_create(i);
    
    if(list->head == NULL){
        list->head = el;
  }

    if(list->tail){
        list->tail->next = el;
  }
  
    if(el == NULL){
        return 1;
  }


  list->tail = el;
  return 0;
}


int list_prepend( list_t* list, int i ){
  element_t* el = element_create(i);
    
    if(list->tail == NULL){
        list->tail = el;
  }
  
    if(list->head){
        el->next = list->head;
  }

    if(el == NULL){
        return 1;
  }

  list->head = el;

  return 0;
}


element_t* list_index( list_t* list, unsigned int i ){
  if(list->head == NULL){
    return NULL;
  }

  unsigned int current = 0;
  element_t* el = list->head;

  while(current < i){
      if(el->next == NULL){
            return NULL;
      }
      current++;
      el = el->next;
    }

  return el;
}


void list_print( list_t* list ){
  printf("{");

  for(element_t* el = list->head; el; el = el->next){
      printf(" %d", el->val);
  }

  printf(" }\n");
}