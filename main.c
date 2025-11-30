#include <stdio.h>
#include "array_list.h"

void print_list(Arrlist *list){
	printf("Lista:\n");
	int *x;
	for (int i=0; i < list->size; i++){
		x = getlist(list, i);
		printf("%d, ", *x );
	}
	printf("\n\n");
}
	

int main() {
	Arrlist* listilla= createlist(3, sizeof(int));
	int ins;
	int *print;
	for (int i=1; i < 4; i++){
		addlist(listilla, &i);
	}
	
	ins = 5;
	addlist(listilla, &ins);
	print_list(listilla);
	ins = 4;
	insertlist(listilla, &ins, 3);
	print_list(listilla);
	
	print=getlist(listilla, 1);
	printf("%d\n\n", *print );
	
	removelist(listilla, 0);
	removelist(listilla, 2);
	print_list(listilla);
	
	deletelist(listilla);
	return 0;
}

