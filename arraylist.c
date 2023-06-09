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

ArrayList *createList(void) {

ArrayList *lista = (ArrayList *) malloc(sizeof(ArrayList));

  lista->capacity = 2;
  lista->size = 0;
  lista->data = (void **)malloc(sizeof(void*));
  
    return lista;
}

void append(ArrayList * l, void * data){

if(l->size == l->capacity){

  l->capacity *= 2;
  l->data = (void**)realloc(l->data, l->capacity * sizeof(void*));
  l->data[l->size] = data;
  l->size ++;
}else{
  l->data[l->size] = data;
  l->size ++;
}
  
}

void push(ArrayList * l, void * data, int i){

  if(i > l->size) return;
  
  if(l->size == l->capacity){

    l->data = (void**)realloc(l->data, l->capacity * 2);
    l->capacity *= 2;

  }

  for(int j = l->size - 1 ; j >= i ; j--){
    
    l->data[j+1] = l->data[j];
  }

  l->data[i] = data;
  l->size++;
}


void* pop(ArrayList * l, int i){

  
  if(0 == l->size) return NULL;

  if(i < 0){

    i = i + l->size;
    
  }

  void* aux = l->data[i];
  
  for(int j=i ; j < l->size-1 ; j++){

    l->data[j] = l->data[j+1];
  }

  l->size--;
  
    return aux;
}

void* get(ArrayList * l, int i){
  
  if(i >= l->size ) return NULL;
  
  if(i < 0){

  return l->data[i+l->size];

    
  }

  
    return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){

  free(l);

  l=createList();
  
}
