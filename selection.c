//*****************************************************************
//selection.c
//*****************************************************************
//*****************************************************************
//Leyva Barrientos Oswaldo
//Medina Luqueño Ana Ximena
//Zenón Vela Juan José
//Curso: Análisis de algoritmos
//(C) Febrero 2018
//ESCOM-IPN
//Implementación del algoritmo de ordenamiento por selección
//Compilación de esta implementación: "gcc selection.c tiempo.x  -o main" (Generación del código objeto)
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
void selection_sort(int *numbers,int size);

//*****************************************************************
//PROGRAMA PRINCIPAL
//*****************************************************************
int main(int argc, char const *argv[]) {
    //Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
    if(argc>=2){

        //******************************************************************
        //Variables del main
        //******************************************************************
        double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
        int size = atoi(argv[1]);
        int *numbers = (int *)malloc(sizeof(int)*size);

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
        selection_sort(numbers,size);
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
//selection_sort (Declaración)
//*****************************************************************
//Descripción: Función que implementa el algoritmo de ordenamiento de selección
//
//Recibe: Arreglo de números a ordenar y el tamaó del mismo
//Devuelve: Nada.
//*****************************************************************
void selection_sort(int *numbers,int size) {
    
    int min;
    //******************************************************************
    //Algoritmo
    //******************************************************************
    for (int k = 0; k <= size-1; ++k) {
        min = k;
        for (int i = k+1; i <= size-1; ++i){
            if(numbers[i]<numbers[min]){
                min=i;
            }
        }
        if (min!=k){
            int Temp = numbers[min];
            numbers[min]=numbers[k];
            numbers[k] = Temp;
        }
        //printf("%d\n",numbers[k]);
    }

    //******************************************************************
    // for (int i = 0; i < size; ++i) {
    //     printf("%d\n",numbers[i]);
    // }
}
