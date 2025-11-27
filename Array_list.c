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
	if (list){
		printf("\nNo se pudo inicializar la lista\n");
		return NULL;
	}
	list -> data =(void**)malloc(sizeof(void*)*ini_capacity);
	if(!list->data){
		free(list);
		printf("No se pudo solicitar memoria para almacenar los datos de la lista");
		return NULL;
	}
	
	list->size =0;
	list->capacity = ini_capacity;
	list->size = size;
}
int main(){
	
}
