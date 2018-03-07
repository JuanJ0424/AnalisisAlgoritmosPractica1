//*****************************************************************
//insertion.c
//*****************************************************************
//*****************************************************************
//Leyva Barrientos Oswaldo
//Medina Luqueño Ana Ximena
//Zenón Vela Juan José
//Curso: Análisis de algoritmos
//(C) Febrero 2018
//ESCOM-IPN
//Implementación del algoritmo de ordenamiento por inserción
//Compilación de esta implementación: "gcc insertion.c tiempo.x  -o insertion" (Generación del código objeto)
//(tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto
//*****************************************************************

//*****************************************************************
//Bibliotecas incluidas
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "tiempo.h"

//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
//*****************************************************************

//*****************************************************************
//DECLARACION DE ESTRUCTURAS
//*****************************************************************

//*****************************************************************
//DECLARACIÓN DE FUNCIONES
//*****************************************************************
void insertion_sort(int *numbers, int size);

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char const *argv[]){
    double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos

    //Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
    if(argc>=2){
        //******************************************************************
        //Variables del main
        //******************************************************************
        int size = atoi(argv[1]);

        int *numbers = (int *)malloc(sizeof(int)*size);
        //******************************************************************

        //******************************************************************
        //Llenar el arreglo con los datos a ordenar
        //******************************************************************
        for(int i=0;i<size;++i){
            scanf("%d",&numbers[i]);
        }
        //******************************************************************

        //******************************************************************
        //Iniciar el conteo del tiempo para las evaluaciones de rendimiento
        //******************************************************************
        uswtime(&utime0, &stime0, &wtime0);
        //******************************************************************

        //******************************************************************
        //Algoritmo
        //******************************************************************
        insertion_sort(numbers,size);
        //******************************************************************

        //******************************************************************
        //Evaluar los tiempos de ejecución
        //******************************************************************
        uswtime(&utime1, &stime1, &wtime1);

        //Cálculo del tiempo de ejecución del programa
        printf("\n");
        printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
        printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
        printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        printf("\n");
    
        //Mostrar los tiempos en formato exponecial
        printf("\n");
        printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
        printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
        printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
        printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
        printf("\n");
        //******************************************************************
        //Terminar programa normalmente
        exit(0);
    }else{
        printf("Argumentos insuficientes\n");
        exit(1);
    }
    return 0;
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES
//************************************************************************

//*****************************************************************
//insertion_sort (Declaración)
//*****************************************************************
//Descripción: Función que implementa el algoritmo de ordenamiento de inserción
//
//Recibe: Arreglo de números a ordenar y el tamaño del mismo
//Devuelve: Nada.
//*****************************************************************

void insertion_sort(int *numbers, int size){
    //******************************************************************
    //Algoritmo
    //******************************************************************
    for(int i=0;i<=size-1;i++){
        int j = i;
        int temp = numbers[i];
        
        // Se recorren todos los números mayores al elemento en i hacia adelante una posición
        while(j>0 && temp<numbers[j-1]){
            numbers[j] = numbers[j-1];
            j--;
        }
        numbers[j]=temp;    
    }
    //******************************************************************
    // for(int i=0;i<size;i++){
    //     printf("%d\n",numbers[i]);
    // }
}