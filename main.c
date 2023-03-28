#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

int main( int argc, char *argv[] ){

    ArrayList* numbers= createList();

    int i=0;
    printf("Agregando los elementos 0,1,2,3,4 al comienzo y final de la lista\n  ");
    for(; i<5; i++){
        int* num = (int*)malloc(sizeof(int));
        *num = i;
        append(numbers, num);
        push(numbers,num, 0);
    }

    for(i=0; i<get_size(numbers); i++)
        printf("%d ", *(int*)get(numbers, i));
    printf("\n");
    printf("  Tamano de la lista: %d\n", get_size(numbers));
    
    printf("\nEliminando el primer y ultimo elemento de la lista\n  ");
    pop(numbers, 0);
    pop(numbers, -1);

    for(i=0; i<get_size(numbers); i++)
        printf("%d ", *(int*)get(numbers, i));
    printf("\n");
    printf("  Tamano de la lista: %d\n", get_size(numbers));
    
    printf("\nModificando el primer elemento de la lista (100)\n  ");
    *(int*)get(numbers, 0) = 100;

    for(i=0; i<get_size(numbers); i++)
        printf("%d ", *(int*)get(numbers, i));
    printf("\n");
    printf("  Tamano de la lista: %d\n", get_size(numbers));
    printf("  *Note que el primer y el ultimo elemento son el mismo (100)\n");


    printf("\nLimpiando la lista\n");
    clean(numbers);

    printf("  Tamano de la lista: %d\n", get_size(numbers));



    return 0;
}