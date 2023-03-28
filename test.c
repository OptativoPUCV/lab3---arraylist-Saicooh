#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "arraylist.c"


char msg[300];
int test_id = -1;


int success(){
  printf("SUCCESS\n");
  exit(0);
}

void err_msg(char* msg){
    //if(test_id!=-1) return;
    printf("   [ FAILED ] ");
    printf("%s\n",msg);
    //print_trace();
}

void ok_msg(char* msg){
    //if(test_id!=-1) return;
    printf ("   [ OK ] ");
    printf("%s\n",msg);
}

void info_msg(char* msg){
    //if(test_id!=-1) return;
    printf ("   [ INFO ] %s\n",msg);
}

int test_suite(int(*test)(), char* msg, int max_score, int id, int req_id){
    if(test_id==-1 || test_id==id){
        printf("\n%s\n", msg);
        int score=test();

        if(id==req_id && score == max_score) success();

        printf("   partial_score: %d/%d\n", score, max_score); 
        
        return score;
    }
    return 0;
}


/*************  TESTS  ******************/
ArrayList* initialize_exList(){
    info_msg("Creando Lista:{0,2,4,6} (capacity=5)");
    ArrayList * L = (ArrayList *)malloc(sizeof(ArrayList));
    L->data = (void**)malloc(sizeof(void*) * 5);
    L->capacity = 5;

    for (int i = 0; i < 4; i++){
        int *j = (int*) malloc(sizeof(int));
        *j=i*2;
        L->data[i]=j;
    }
    L->size=4;
    return L;
}

ArrayList* initialize_emptyList(){
    info_msg("Creando Lista vacia (size=0)");
    ArrayList * L = (ArrayList *)malloc(sizeof(ArrayList));
    L->data = (void**)malloc(sizeof(void*) * 2);
    L->capacity = 2;
    L->size = 0;

    return L;
}

int test_create(){
    ArrayList* l = createList();
    if(l==NULL){
        err_msg("createList retorna NULL");
        return 0;
    }

    if(l->capacity != 2 || l->size != 0 || l->data == NULL){
        err_msg("Debes inicalizar los componentes de la lista");
        return 0;
    }

    ok_msg("createList");
    return 10;
}

void print_list(ArrayList* l){
    printf("   lista:{");
    for(int i=0; i<l->size; i++){
        printf("%d, ", *(int*)l->data[i]);
    }
    printf("}\n");
}

int test_append(){
    ArrayList* l=initialize_emptyList();

    info_msg("llamando a append(l,1)");
    int *j = (int*) malloc(sizeof(int));
    *j=1; append(l,j);
    info_msg("llamando a append(l,2)");
    j = (int*) malloc(sizeof(int));
    *j =2; append(l,j);

    //the list should be {1,2,3,4}
    info_msg("Verificando que la lista sea {1,2}");
    if(l->size != 2){
        err_msg("el tamaño de la lista (size) no es correcto");
        return 0;
    }

    if(l->capacity != 2){
        err_msg("la capacidad de la lista se debe mantener (2)");
        return 0;
    }

    if(l->data[0] == NULL || l->data[1] == NULL || 
        *(int*)l->data[0] != 1 || *(int*)l->data[1] != 2){

        err_msg("la lista no tiene los elementos correctos");
        print_list(l);
        return 0;
    }

    ok_msg("append 1/2");

    info_msg("agregando un nuevo elemento: append(l,3)");
    j = (int*) malloc(sizeof(int));
    *j=3; append(l,j);

    //the list should be {1,2,3}
    info_msg("Verificando que la lista sea {1,2,3}"); 

    if(l->capacity != 4){
        err_msg("la capacidad de la lista se debe duplicar (4)");
        return 5;
    }   

    if(l->data[0] == NULL || l->data[1] == NULL || l->data[2] == NULL ||
        *(int*)l->data[0] != 1 || *(int*)l->data[1] != 2 || *(int*)l->data[2] != 3){
        err_msg("la lista no tiene los elementos correctos");
        print_list(l);
        return 5;
    }

    ok_msg("append 2/2");

    return 10;
}

int test_push(){
    ArrayList* l=initialize_exList();

    info_msg("llamando a push(l,1,0)");
    int *j = (int*) malloc(sizeof(int));
    *j=1; push(l,j,0);


    //the list should be {1,0,2,4,6}
    info_msg("Verificando que la lista sea {1,0,2,4,6}");
    if(l->size != 5){
        err_msg("el tamaño de la lista (size) no es correcto");
        return 0;
    }

    if(l->capacity != 5){
        err_msg("la capacidad de la lista se debe mantener (5)");
        return 0;
    }

    if(l->data[0] == NULL || l->data[1] == NULL || l->data[2] == NULL || l->data[3] == NULL || l->data[4] == NULL ||
        *(int*)l->data[0] != 1 || *(int*)l->data[1] != 0 || *(int*)l->data[2] != 2 || *(int*)l->data[3] != 4 || *(int*)l->data[4] != 6){

        err_msg("la lista no tiene los elementos correctos");
        print_list(l);
        return 0;
    }

    ok_msg("PASSED");

    info_msg("agregando un nuevo elemento: push(l,3,2)");
    j = (int*) malloc(sizeof(int));
    *j=3; push(l,j,2);

    //the list should be {1,0,3,2,4,6}
    info_msg("Verificando que la lista sea {1,0,3,2,4,6}");

    //printf("   [ INFO ] size: %d, capacity: %d\n", l->size, l->capacity);
    print_list(l);

    if(l->capacity != 10){
        err_msg("la capacidad de la lista se debe duplicar (10)");
        return 5;
    }

    if(l->data[0] == NULL || l->data[1] == NULL || l->data[2] == NULL || l->data[3] == NULL || l->data[4] == NULL || l->data[5] == NULL ||
        *(int*)l->data[0] != 1 || *(int*)l->data[1] != 0 || *(int*)l->data[2] != 3 || *(int*)l->data[3] != 2 || *(int*)l->data[4] != 4|| *(int*)l->data[5] != 6){
        err_msg("la lista no tiene los elementos correctos");
        print_list(l);
        return 5;
    }

    ok_msg("push 2/2");

    return 10;
}

int test_pop(){
    ArrayList* l=initialize_exList();

    info_msg("llamando a pop(0)");
    pop(l,0);
    
    //the list should be {2,4,6}
    info_msg("Verificando que la lista sea {2,4,6}");
    if(l->size != 3){
        err_msg("el tamaño de la lista (size) no es correcto");
        return 0;
    }

    if(l->data[0] == NULL || l->data[1] == NULL || l->data[2] == NULL ||
        *(int*)l->data[0] != 2 || *(int*)l->data[1] != 4 || *(int*)l->data[2] != 6){
        err_msg("la lista no tiene los elementos correctos");
        print_list(l);
        return 0;
    }
    ok_msg("PASSED");

    info_msg("llamando a pop(-1)");
    pop(l,-1);

    //the list should be {2,4}
    info_msg("Verificando que la lista sea {2,4}");
    if(l->size != 2){
        err_msg("el tamaño de la lista (size) no es correcto");
        return 0;
    }

    if(l->data[0] == NULL || l->data[1] == NULL ||
    *(int*)l->data[0] != 2 || *(int*)l->data[1] != 4){
        err_msg("la lista no tiene los elementos correctos");
        print_list(l);
        return 0;
    }

    ok_msg("PASSED");

    l=initialize_emptyList();
    info_msg("llamando a pop(0) en una lista vacia");
    pop(l,0);

    //the list should be {}
    info_msg("Verificando que la lista sea {}");
    if(l->size != 0){
        err_msg("el tamaño de la lista (size) no es correcto (debe ser 0)");
        return 0;
    }
    

    ok_msg("El metodo pop() funciona correctamente");

    return 10;
}

int test_get(){
    ArrayList* l=initialize_exList();

    info_msg("llamando a get(0)");
    int *j = get(l,0);
    if(j==NULL || *j != 0){
        if(j==NULL) printf("   [ FAILED ] get(0) -> NULL\n");
        else
            printf("   [ FAILED ] get(0) -> %d\n", *j);
        return 0;
    }
    ok_msg("PASSED");

    info_msg("llamando a get(-1)");
    j = get(l,-1);
    if(j ==NULL || *j != 6){
        if(j==NULL) printf("   [ FAILED ] get(0) -> NULL\n");
        else
        printf("   [ FAILED ] get(-1) -> %d\n", *j);
        return 0;
    }
    ok_msg("PASSED");

    info_msg("llamando a get(5)");
    j = get(l,5);
    if(j != NULL){
        printf("   [ FAILED ] get(5) -> %d (debería ser NULL)\n", *j);
        return 0;
    }
    ok_msg("el metodo get() funciona correctamente");

    return 10;
}

int test_clean(){
    ArrayList* l=initialize_exList();

    info_msg("llamando a clean()");
    clean(l);

    //the list should be {}
    info_msg("Verificando que la lista sea {}");
    if(l->size != 0){
        err_msg("el tamaño de la lista (size) no es correcto (debe ser 0)");
        return 0;
    }

    ok_msg("El metodo clean() funciona correctamente");

    return 10;
}

//all methods are tested
int test_all(){
    info_msg("Creando una lista vacia: ArrayList *l = createList();");
    ArrayList *l = createList();
    int *j;
    int i;

    info_msg("agregando 10 elementos a la lista: {0,1,2,3,4,5,6,7,8,9}");
    for(i=0;i<10;i++){
        j = (int*) malloc(sizeof(int));
        *j=i;
        append(l,j);
    }

    info_msg("Verificando que la lista sea {0,1,2,3,4,5,6,7,8,9}");
    if(l->size != 10){
        err_msg("el tamaño de la lista (size) no es correcto");
        return 0;
    }   

    if(l->data[0] == NULL || l->data[1] == NULL || l->data[2] == NULL || l->data[3] == NULL || l->data[4] == NULL || l->data[5] == NULL || l->data[6] == NULL || l->data[7] == NULL || l->data[8] == NULL || l->data[9] == NULL ||
        *(int*)l->data[0] != 0 || *(int*)l->data[1] != 1 || *(int*)l->data[2] != 2 || *(int*)l->data[3] != 3 || *(int*)l->data[4] != 4|| *(int*)l->data[5] != 5 || *(int*)l->data[6] != 6 || *(int*)l->data[7] != 7 || *(int*)l->data[8] != 8 || *(int*)l->data[9] != 9){
        err_msg("la lista no tiene los elementos correctos");
        print_list(l);
        return 0;
    }
    ok_msg("PASSED");

    info_msg("llamando a pop(0)x3");
    pop(l,0);
    pop(l,0);
    pop(l,0);

    //the list should be {3,4,5,6,7,8,9}
    info_msg("Verificando que la lista sea {3,4,5,6,7,8,9}");
    if(l->size != 7){
        err_msg("el tamaño de la lista (size) no es correcto");
        return 0;
    }

    if(l->data[0] == NULL || l->data[1] == NULL || l->data[2] == NULL || l->data[3] == NULL || l->data[4] == NULL || l->data[5] == NULL || l->data[6] == NULL ||
        *(int*)l->data[0] != 3 || *(int*)l->data[1] != 4 || *(int*)l->data[2] != 5 || *(int*)l->data[3] != 6 || *(int*)l->data[4] != 7|| *(int*)l->data[5] != 8 || *(int*)l->data[6] != 9){
        err_msg("la lista no tiene los elementos correctos");
        print_list(l);
        return 0;
    }

    ok_msg("PASSED");

    info_msg("llamando a pop(6)");
    pop(l,6);
    info_msg("llamando a pop(3)");
    pop(l,3);

    //the list should be {3,4,5,7,8}
    info_msg("Verificando que la lista sea {3,4,5,7,8}");
    if(l->size != 5){
        err_msg("el tamaño de la lista (size) no es correcto");
        return 0;
    }

    if(l->data[0] == NULL || l->data[1] == NULL || l->data[2] == NULL || l->data[3] == NULL || l->data[4] == NULL ||
        *(int*)l->data[0] != 3 || *(int*)l->data[1] != 4 || *(int*)l->data[2] != 5 || *(int*)l->data[3] != 7 || *(int*)l->data[4] != 8){
        err_msg("la lista no tiene los elementos correctos");
        print_list(l);
        return 0;
    }

    ok_msg("PASSED");

    //iterating with get
    info_msg("imprimiendo la lista con get");
    for(i=0;i<l->size;i++){
        j = get(l,i);
        if(j == NULL || *j != *(int*)l->data[i]){
            printf("   [ FAILED ] get(%d) -> %d\n", i, *j);
            return 0;
        }else{
            printf("   get(%d) -> %d; ", i, *j);
        }
    }
    printf("\n");

    ok_msg("PASSED");


    return 10;
}

int main( int argc, char *argv[] ) {
    
    if(argc>1) test_id=atoi(argv[1]);
    srand(time(NULL));

    int total_score=0;
    total_score+=test_suite(test_create, "Test Create...", 10, 0, test_id);
    total_score+=test_suite(test_append, "Test append...", 10, 1, test_id);    
    total_score+=test_suite(test_push, "Test push...", 10, 2, test_id);
    total_score+=test_suite(test_pop, "Test pop...", 10, 3, test_id);
    total_score+=test_suite(test_get, "Test get...", 10, 4, test_id);
    total_score+=test_suite(test_clean, "Test clean...", 10, 5, test_id);
    if (total_score == 60)
        total_score+=test_suite(test_all, "Test all...", 10, 6, test_id);

    
    
    if(argc==1)
      printf("\ntotal_score: %d/70\n", total_score);

    

    return 0;
}