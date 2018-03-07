//*****************************************************************
//arbolBinBusqueda.h
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
//struct nodo (Estructura)
//*****************************************************************
//Descripción: Estructura básica para el nodo de un árbol binario de búsqueda.
//
//Atributos:
//-dato: El dato entero a almacenar en el nodo.
//-hijoDer: Referencia al nodo que se tiene como hijo derecho.
//-hijoIzq: Referencia al nodo que se tiene como hijo izquierdo.
//*****************************************************************
struct nodo{
    int dato;
    struct nodo *hijoIzq;
    struct nodo *hijoDer;
};
//*****************************************************************
//struct arbolBinBusqueda (Estructura)
//*****************************************************************
//Descripción: Estructura para un árbol binario de búsqueda.
//
//Atributos:
//-raiz: Referencia al nodo que se tiene como raíz del árbol.
//*****************************************************************
struct arbolBinBusqueda{
    struct nodo *raiz;
};

//*****************************************************************
//crearNodo (Declaración)
//*****************************************************************
//Descripción: Función que crea un nuevo nodo de árbol binario.
//
//Recibe: Variable entera para almacenar en el nodo a crear.
//Devuelve: Referencia al nodo que se acaba de crear.
//*****************************************************************
struct nodo *crearNodo(int dato);
//*****************************************************************
//crearArbolBinBusqueda (Declaración)
//*****************************************************************
//Descripción: Función que crea un nuevo árbol binario con una raíz vacía.
//
//Recibe:
//Devuelve: Referencia al árbol que se acaba de crear.
//*****************************************************************
struct arbolBinBusqueda *crearArbolBinBusqueda();
//*****************************************************************
//insertar (Declaración)
//*****************************************************************
//Descripción: Función que inserta un dato en un árbol binario de manera
//iterativa.
//
//Recibe: Referencia a un árbol binario de búsqueda y un dato a ingresar.
//Devuelve: 
//*****************************************************************
void insertar(struct arbolBinBusqueda *arbol, int dato);
//*****************************************************************
//guardarRecorridoInorden (Declaración)
//*****************************************************************
//Descripción: Función que almacena en un arreglo, los datos encontrados en un
//árbol binario de búsqueda mediante un recorrido en inorden, iterativamente.
//
//Recibe: Referencia a un árbol binario de búsqueda, un arreglo de enteros de
//dimensión igual o mayor al número de nodos en el árbol, y el número de datos
//a ingresar en el arreglo.
//Devuelve: 
//*****************************************************************
void guardarRecorridoInorden(struct arbolBinBusqueda *arbol, int *A, int n);