#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int main( int argc, char* argv[] ){
  list_t* list = list_create();

  for( int i=0; i<5; i++ ){
    list_append( list, i );}
  
    for( int i=-1; i>-5; i-- ){
        list_prepend( list, i );}
    
    printf("This is the list: ");
    list_print( list );

    int index = 2;
    element_t* el = list_index( list, index );
  
   if( el == NULL ){
      printf( "index %d not found\n", index );
      return 1; // fail
    }
  
    printf( "value at index %d is %d\n", index, el->val );
    printf("Move on to next tasks\n");
    if( el->val != -2 ) {return 1;}
  
// Task 2
    
    printf("Task 2\n");
	element_t* el_2 = element_create(96);
	if(el_2->val != 96){
		printf("Should Not have 96!\n");
		return 1;
	}

	if(el_2 == NULL){
		printf("Mem fails");
		return 1;
	}

	element_t* el_3 = element_create(99);
	list_t* list_2 = list_create();
    
	for(int i = 0; i < 5; i++){
		list_append( list_2, i);}
    
	for(int i = -1; i > -5; i--){
		list_prepend(list_2, i);}
    
	if (list->tail->val != 4){
		printf("TAIL ERROR\n");
		return 1;
	}

	el_3->next = list_index(list_2, 3);
	free(el_3->next);
	el_3 = element_create(100);
	if(el_3->next != NULL){
		printf("el_3->next is should be NULL but if not than return 1\n");
		return 1;
	}
	printf("Task 2 Passed\n");




	//Task 3
	printf("Task 3\n");
	list_t* list_3 = list_create();
	element_t* el_4 = list_index(list_3, 5);
	if(el_4 != NULL){
		printf("el_4 is should be NULL but if not than return 1\n");
		return 1;
	}
	printf("Task 3 Passed\n");




	//Task 4
	printf("Task 4\n");
	list_t* list_4 = list_create();
	list_prepend(list_4, 1996);
	if(list_4->tail->val != 1996) {
		printf("list_4->tail should be 1996 but if not than return 1\n");
		return 1;
	}
	printf("Task 4 Passed\n");




	//Task 5
	printf("Task 5\n");
	list_t* list_5 = list_create();
	list_5->head = element_create(10000);
	list_5->head->next = element_create(10000);
	list_5->tail = list_5->head->next;
	free(list_5);
	list_5 = list_create();

	if(list_5->tail != NULL) {
		printf("list_5->head should be NULL but if not than return 1\n");
		return 1;
	}
	printf("Task 5 Passed\n");


	//Task 6
	printf("Task 6\n");
	list_t* list_6 = list_create();
	list_print(list_6);
	printf("Task 6 Passed\n");

    // destroy the array 
	list_destroy(list);
	list_destroy(list_2);
	list_destroy(list_3);
	list_destroy(list_4);
	list_destroy(list_5);
	list_destroy(list_6);

	printf("DONE \n");
	return 0;// tests pass
}

