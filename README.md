
Implementando un Montículo Binario (Heap)
=====

---
**ANTES DE COMENZAR**

* Abra su cuenta en repl.it
* En el home de repl.it busque el lab y clónelo para comenzar a trabajar
* Seleccione el lenguaje (C) y escriba el comando para el botón run: `bash test.sh`
* Sólo puede modificar los archivos *arralist.c* y *main.c*
* Para testear sus códigos basta con que apriete el botón **Run**
* Actualice seguido sus cambios, debe ingresar su contraseña de github y [token](https://drive.google.com/file/d/1s3PyI_HCn0HAx5dm7h0jRiC-G9Cq2p-g/view?usp=sharing)
* No está permitido usar comandos de git (a menos que el profesor lo indique)

---


En este laboratorio implementaremos una **lista**. Para ello usaremos la siguiente estructura (arreglo **no circular**):

````c
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;
````

Los componentes de la estructura son los siguientes:

* `data`: un arreglo dinámico para almacenar *punteros* a los datos.
* `capacity`: el tamaño actual del arreglo
* `size`: la cantidad de datos válidos almacenados en la lista


Se recomienda que el tamaño del arreglo (`capacity`) sea mayor a la cantidad de datos (`size`) de la lista. De esta manera, no es necesario expandir el arreglo cada vez que se insertan nuevos datos.

![image](https://docs.google.com/drawings/d/e/2PACX-1vRNc-KhLkO_GhuKtaU3nCEof64HACT-zrCfX9qjWgOk7nwhd3Sp_tg_sJ17xWInHzVvyiyClsPWZ2FK/pub?w=518&h=223)

Ejercicios
----

1. Implemente la función `ArrayList *createList()`. Esta función crea un nuevo dato de tipo ArrayList inicializando sus variables. Considere que la capacidad incial es de 2 casillas para el arreglo.
   > Recuerde reservar memoria para el ArrayList y también para el arreglo dinámico `data`.

2. Implemente la función `void append(ArrayList * l, void * data)`. Esta función agrega el dato al final de la lista (es decir, en la posición `size`). 

    > Si el arreglo está lleno aumente la capacidad al **doble** usando la función `realloc` así:
    `data = realloc(data, nueva_capacidad)`

    > Recuerde aumentar el valor de la variable `size`.

3. Implemente la función `void push(ArrayList * l, void * data, int i)`. Esta función ingresa el dato en la `i`-ésima posición de la lista (`i=0` es la primera posición). 

    > Si el arreglo está lleno, primero debe aumentar su capacidad al doble.

    > Recuerde mover los elementos siguientes una casilla a la derecha.

    > Si `i` es mayor a `size`, la función no debe hacer nada.

4. Implemente la función `void* get(ArrayList * l, int i)`. Esta función retorna el dato de la posición `i` de la lista. Si `i>=size`, entonces retorna NULL. Además, si `i<0` los valores son obtenidos desde el final hacia el principio de la lista.

![image](https://docs.google.com/drawings/d/e/2PACX-1vTXHZC-2EsYtoTZWTcqZ7mdst7Lvpd2PP22ie9wx1kIp1lmNy-dkQ6OrK-F1VqqnwQBn8kpWGupbAnT/pub?w=376&h=156)

5. Implemente la función `void* pop(ArrayList * l, int i)`. Esta función elimina **y retorna** el dato de la posición `i` de la lista. Valores negativos corresponden a los datos obtenidos desde el final al principio de la lista (vea la función get).

    > Recuerde que al eliminar un dato, debe mover los elementos que se encuentran a la derecha, una casilla hacia la izquierda

6. Implemente la función `void clean(ArrayList * list)`. Esta función inicializa la capacidad y tamaño de la lista a sus valores iniciales y reduce el arreglo `data` a su tamaño inicial (2).


Ya tiene implementada su lista.
Para probarla puede usar el código del archivo `main.

Para compilar y ejecutar:

    gcc main.c arraylist.c -o main
    ./main 

Y listo!
