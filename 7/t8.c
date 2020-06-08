#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

void list_sort(list_t * list);
void LLcatenate(list_t * L1, list_t * L2);
void LLappendNode(list_t * list, element_t * newNode);

void list_sort(list_t * list){

    if (list->head == list->tail){
        return;
    }

    int pivot = list->head->val;
    element_t * pivot_node = list->head;
    list->head = list->head->next;


    list_t * first = list_create();
    list_t * second = list_create();
    element_t * curr = list->head;
    element_t * next;
    while (curr != NULL) {
        next = curr->next;
        curr->next = NULL;
        if (curr->val <= pivot) {
            LLappendNode(first, curr);
        } 
        else {
            LLappendNode(second, curr);
        }
        curr = next;
    }
    list->head = NULL;
    list->tail = NULL;

    list_sort(first);
    list_sort(second);

    LLcatenate(list, first);
    LLappendNode(list, pivot_node);
    LLcatenate(list, second);
}
void LLcatenate(list_t * L1, list_t * L2){
    if (L2->head == NULL){
        assert(L2->tail == NULL);
    } 
    else if (L1->head == NULL) {
        assert(L1->tail == NULL);
        *L1 = *L2;
    } 
    else {
        L1->tail->next = L2->head;
        L1->tail= L2->tail;
    }
    free(L2);
}
void LLappendNode(list_t * list, element_t * newNode) {
    if (newNode != NULL) {
        newNode->next = NULL;
        if (list->tail == NULL) {
            assert(list->head == NULL);
            list->head = newNode;
            list->tail = newNode;
        } 
        else {
            list->tail->next = newNode; 
            list->tail = newNode;
        }
    }
}

