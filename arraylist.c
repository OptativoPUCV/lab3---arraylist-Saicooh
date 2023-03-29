#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList 
{
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
    l -> data = realloc(l -> data, l -> capacity * sizeof(void **));
  }

  l -> data[l -> size] = data;

  l -> size++;
  
}

void push(ArrayList * l, void * data, int i)
{
  if (i > l -> size) return;

  if (l -> size == l -> capacity)
  {
    l -> capacity *= 2;
    l -> data = realloc(l -> data, l -> capacity * sizeof(void **));
  }

  for (int auxIn = l -> size ; auxIn > i ; auxIn--)
    l -> data[auxIn] = l -> data[auxIn - 1];

  l -> data[i] = data;

  l -> size++;

}

void *pop(ArrayList * l, int i)
{
  
    return NULL;
}

void *get(ArrayList * l, int i)
{
  if(i >= l -> size) return NULL;
  if(i < 0) i = i + l -> size;

  return l -> data[i];
  
    return NULL;
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l)
{
  free(l);
  l = createList();
}
