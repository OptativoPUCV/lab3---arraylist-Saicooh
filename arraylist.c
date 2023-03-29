#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void)
{
  ArrayList *lista = NULL;
  
  lista = (ArrayList *) malloc(sizeof(ArrayList));

  if (lista == NULL) exit(EXIT_FAILURE);

  lista -> data = malloc(2 * sizeof(void **));
  
  lista -> capacity = 2, lista -> size = 0;
  
  return lista;
}

void append(ArrayList * l, void * data)
{
  if (l -> size == l -> capacity)
  {
    l -> capacity *= 2;
    l -> data = realloc(l-> data, l -> capacity * sizeof(void **);
  }

  l->size++;
  
}

void push(ArrayList * l, void * data, int i){

}

void* pop(ArrayList * l, int i){
    return NULL;
}

void* get(ArrayList * l, int i){
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l)
{
  free(l);
  l = *createList(l);
    
}
