#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"

#define DEFAULT_CAP 10
#define GROW_FACT 2

Arrlist* createlist(int ini_capacity, int size){
	if (ini_capacity <= 0){
		ini_capacity = DEFAULT_CAP;
	}	
	Arrlist* list=(Arrlist*)malloc(sizeof(Arrlist));
	if (!list){
		printf("\nNo se pudo inicializar la lista\n");
		return NULL;
	}
	list -> data =(void**)malloc(sizeof(void*)*ini_capacity);
	if(!list->data){
		free(list);
		printf("\nNo se pudo solicitar memoria para almacenar los datos de la lista\n");
		return NULL;
	}
	list->size = 0;
	list->capacity = ini_capacity;
	list->element_size = size;
	return list;
}

void deletelist(Arrlist *list){
	if(!list) return;
	clearlist(list);
	free(list->data);
	free(list);
}

void addlist(Arrlist *list, void * element){
	if (!list || !element) return;
	if (list->size >= list->capacity){
		adjust_capacity(list, list->capacity * GROW_FACT);
	}
	list->data[list->size] = malloc(list->element_size);
	if(!list->data[list->size]){
		printf("\nError al asignar memoria para el elemento\n");
	}
	memcpy(list->data[list->size], element, list->element_size);
	list->size++;
}


void insertlist(Arrlist *list, void *element, int index){
	if (!list || !element ||index < 0) return;
	if (list->size >= list->capacity){
		adjust_capacity(list, list->capacity * GROW_FACT);
	}
	for (int i=list->size; i> index; i--){
		list->data[i] = list->data[i-1];
	}
	list->data[index] = malloc(list->element_size);
	if (!list->data[index]){
		printf("\nError al asignar memoria para el elemento\n");
		return;
	}
	memcpy (list->data[index], element, list->element_size);
	list->size++;
}
	
void* getlist(Arrlist *list, int index){
	if (!list ||index < 0|| index > list->size) return NULL;
	return list->data[index];
}
	
int removelist(Arrlist *list, int index){
	if (!list ||index < 0|| index > list->size) return 0;
	free(list->data[index]);
	for (int i=index; i< list->size; i++){
		list->data[i]= list-> data[i+1];
	}
	list->size--;
	list-> data[list->size]= NULL;
	return 1;
}

void adjust_capacity(Arrlist *list, int min_capacity){
	if(!list || min_capacity <= list->capacity) return;
	void **new_data = (void**) realloc (list->data, sizeof(void*) * min_capacity);
	if (!new_data){
		printf("\nError al asignar memoria\n");
		return;
	}
	list->data = new_data;
	list->capacity = min_capacity;
}

void clearlist(Arrlist *list){
	if(!list) return;
	for (int i=0; i<list->size; i++){
		free(list->data[i]);
		list->data[i] = NULL;
	}
	list-> size =0;	
}

