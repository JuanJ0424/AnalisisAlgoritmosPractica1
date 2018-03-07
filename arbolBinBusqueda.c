//*****************************************************************
//arbolBinBusqueda.c
//*****************************************************************
//*****************************************************************
//Leyva Barrientos Oswaldo
//Medina Luqueño Ana Ximena
//Juan José Zenón Vela
//Curso: Análisis de algoritmos
//(C) Febrero 2018
//ESCOM-IPN
//Implementación de un árbol binario de búsqueda iterativo con inserción y recorrido inorden
//Compilación de la libreria: "gcc -c arbolBinBusqueda.c " (Generación del código objeto)
//*****************************************************************


//*****************************************************************
//Bibliotecas incluidas
//*****************************************************************
#include <stdlib.h>
#include "arbolBinBusqueda.h"

//*****************************************************************
//crearNodo (Declaración)
//*****************************************************************
//Descripción: Función que crea un nuevo nodo de árbol binario.
//
//Recibe: Variable entera para almacenar en el nodo a crear.
//Devuelve: Referencia al nodo que se acaba de crear.
//*****************************************************************
struct nodo *crearNodo(int dato){
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->hijoIzq = NULL;
    nuevoNodo->hijoDer = NULL;

    return nuevoNodo;
}
//*****************************************************************
//crearArbolBinBusqueda (Declaración)
//*****************************************************************
//Descripción: Función que crea un nuevo árbol binario con una raíz vacía.
//
//Recibe:
//Devuelve: Referencia al árbol que se acaba de crear.
//*****************************************************************
struct arbolBinBusqueda *crearArbolBinBusqueda(){
    struct arbolBinBusqueda *nuevoArbol = (struct arbolBinBusqueda *)malloc(sizeof(struct arbolBinBusqueda));
    nuevoArbol->raiz = NULL;

    return nuevoArbol;
}
//*****************************************************************
//insertar (Declaración)
//*****************************************************************
//Descripción: Función que inserta un dato en un árbol binario de manera
//iterativa.
//
//Recibe: Referencia a un árbol binario de búsqueda y un dato a ingresar.
//Devuelve: 
//*****************************************************************
void insertar(struct arbolBinBusqueda *arbol, int dato){
    //******************************************************************    
    //Variables del método
    //******************************************************************
    struct nodo *x = arbol->raiz; //Nodo para recorrer el árbol
    struct nodo *y = NULL; //Nodo de seguimiento para la modificación del árbol
    struct nodo *nuevoNodo = crearNodo(dato); //Nodo a agregar al árbol
    //******************************************************************

    //******************************************************************    
    //Algoritmo
    //******************************************************************
    while(x != NULL){
        y = x;
        if(nuevoNodo->dato < x->dato)
            x = x->hijoIzq;
        else
            x = x->hijoDer;
    }
    if(y == NULL)
        arbol->raiz = nuevoNodo;
    else if(nuevoNodo->dato < y->dato)
        y->hijoIzq = nuevoNodo;
    else
        y->hijoDer = nuevoNodo;
    //******************************************************************
}
//*****************************************************************
//guardarRecorridoInorden (Declaración)
//*****************************************************************
//Descripción: Función que almacena en un arreglo, los datos encontrados en un
//árbol binario de búsqueda mediante un recorrido en inorden, iterativamente.
//
//Recibe: Referencia a un árbol binario de búsqueda y un arreglo de enteros, de
//dimensión igual o mayor al número de nodos en el árbol.
//Devuelve: 
//*****************************************************************
void guardarRecorridoInorden(struct arbolBinBusqueda *arbol, int *A, int n){
    //******************************************************************    
    //Variables de la función
    //******************************************************************
    struct nodo *actual; //Nodo para recorrer el árbol
    struct nodo *pre; //Nodo índice para recordar el recorrido
    int i = 0; //Variable para recorrer el arreglo
    //******************************************************************
 
    //******************************************************************    
    //Algoritmo
    //******************************************************************
    if(arbol->raiz == NULL)
        return;
    
    actual = arbol->raiz;
    while(actual != NULL && i < n){
        if(actual->hijoIzq == NULL){
            A[i] = actual->dato;
            i++;
            actual = actual->hijoDer;
        }
        else{
            pre = actual->hijoIzq;
            while(pre->hijoDer != NULL && pre->hijoDer != actual)
                pre = pre->hijoDer;
            if(pre -> hijoDer == NULL){
                pre->hijoDer = actual;
                actual = actual->hijoIzq;
            }
            else{
                pre->hijoDer = NULL;
                A[i] = actual->dato;
                i++;
                actual = actual->hijoDer;
            }
        }
    }
    //******************************************************************
}