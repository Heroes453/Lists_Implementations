#ifndef ARRAY_LIST.H
#define ARRAY_LIST_H

typedef struct{
	void **data; //almacenamiento de elementos
	int size; //Num de elementos de la lista
	int capacity; //Max obj
	int element_size;//tamaño de elementos
}Arrlist;

//Crear o borrar listas
Arrlist* createlist(int ini_capacity, int size);
void deletelist(Arrlist *list);

//Operaciones
void addlist(Arrlist *list, void *element); 
void insertlist(Arrlist *list, void *element, int index); 
void *getlist(Arrlist *list, int index); 
int removelist(Arrlist *list, int index); 
void clearlist(Arrlist *list);

//Adicionales pero importantes
void adjust_capacity(Arrlist *list, int min_cap);
void adjust_size(Arrlist *list);
Arrlist* clonelist(Arrlist *list);



#endif
