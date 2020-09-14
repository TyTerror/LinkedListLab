// list/list.c
// 
// Implementation for linked list.
//
// <Tyler Ramsey>

#include <stdio.h>
#include<stdlib.h> 
#include "list.h"


int list_size = 0;

list_t *list_alloc(){
    list_t *t = (list_t *)malloc(sizeof(list_t));//Creating memory space
    return t;
}

void list_free(list_t *l){
    node_t *node = l->head;
    while (node != NULL){
        node_t *temp = node;
        node = node->next;
        free(temp);
    }
    free(node);
    return;
}



void list_print(list_t *l) {
  printf("---------- \n");
  node_t *currentNode = malloc(sizeof(node_t));
  currentNode = l->head;
  while (currentNode != NULL){
    if (currentNode->next != NULL){
      printf("%d ", currentNode->value);
    } else {
      printf("%d\n", currentNode->value);
      printf("---------- \n");
    }
    currentNode = currentNode->next;
  }
  return;
}



int list_length(list_t *l){
    node_t *currentNode = malloc(sizeof(node_t));
    currentNode = l->head;
    int length = 0;

    if (currentNode == NULL){ //Empty Exception
        return -1;
    }

    while (currentNode != NULL){
        length++;
        currentNode = currentNode->next;
    }
    return length;
}


void list_add_to_back(list_t *l, elem value) {
  node_t *currentNode = malloc(sizeof(node_t)); //allocate space
  node_t *newNode = malloc(sizeof(node_t)); //allocate space
  newNode->value = value;
  
  if (l->head == NULL){//No head Exception
    l->head = newNode;
    list_size++;
    return;
  }
  
  currentNode = l->head;
  while (currentNode->next != NULL){
    currentNode = currentNode->next;
  }
   currentNode->next = newNode;
   list_size++;
   return; 
}


void list_add_to_front(list_t *l, elem value) {
	node_t *newNode = malloc(sizeof(node_t)); //allocate space
	newNode->value = value;
    newNode->next = l->head;
    l->head = newNode; //set to head
  list_size++;
}

void list_add_at_index(list_t *l, elem value, int index){
  if (index < 0){//Should be error
        return;
    }
  if (index > list_size){//Should be error
        return;
    }

    if (index == 0){
        list_add_to_front(l, value);
    }

    node_t *currentNode = l->head;

    int i = 0;
    for (i = 0; i < index - 1; i++){

        if (currentNode->next == NULL){
            return;
        }

        currentNode = currentNode->next;
    }

    node_t *t = (node_t *)malloc(sizeof(node_t));

    t->value = value;
    t->next = currentNode->next;
    currentNode->next = t;
  list_size++;
}

elem list_remove_from_back(list_t *l){

    elem value;
    if (l->head == NULL){ // Empty list error
        return -1;
    }

    if (l->head->next == NULL){
        value = l->head->value;
        free(l->head);
        return value;
    }

    node_t *currentNode = l->head;

    while (currentNode->next->next != NULL){
        currentNode = currentNode->next;
    }

    value = currentNode->next->value;
    free(currentNode->next);
    currentNode->next = NULL;
    list_size--;
    return value;
}

elem list_remove_from_front(list_t *l){
    elem value;
    if (l->head == NULL){
        return -1; //Empty list exception
    }

    node_t *t = l->head->next;
    value = l->head->value;
    free(l->head);
    l->head = t;
  list_size --;
    return value;
}

elem list_remove_at_index(list_t *l, int index){
    elem value;
  if (l->head == NULL){ //Empty list error
    return;
  }
  if (index < 0){//Not valid index error
    return;
  }
    if (index == 0){
        return list_remove_from_front(l);
    }

    node_t *currentNode = l->head;
    node_t *t = NULL;

    int i = 0;
    for (i = 0; i < index - 1; i++){

        if (currentNode->next == NULL){
            return -1;
        }
        currentNode = currentNode->next;
    }

    t = currentNode->next;
    value = t->value;
    currentNode->next = t->next;
    free(t);
  list_size --;
    return value;
}

bool list_is_in(list_t *l, elem value){
  if (l->head == NULL){//Empty list error
    return false;
  }
    node_t *currentNode = l->head;
    while (currentNode != NULL){
        if (currentNode->value == value){
            return true;
        }
        currentNode = currentNode->next;
    }

    return false;
}


elem list_get_elem_at(list_t *l, int index){
    node_t *currentNode = l->head;
    int i = 0;
  if (l->head == NULL){//Empty list error
    return -1;
  }
  if (index < 0){//Out of range error
    return -1;
  }
    for (i = 0; i < index; i++){
        if (currentNode->next == NULL){
            return -1;
        }
        currentNode = currentNode->next;
    }
    return currentNode->value;
}

int list_get_index_of(list_t *l, elem value){
  if (l->head == NULL){//Empty list error
    return -1;
  }
    int iter = 0;
    node_t *currentNode = l->head;

    while (currentNode != NULL){

        if (currentNode->value == value){
            return iter;
        }
        iter++;
        currentNode = currentNode->next;
    }

    return -1;
}