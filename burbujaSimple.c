//*****************************************************************
//Leyva Barrientos Oswaldo
//Medina Luqueño Ana Ximena
//Juan José Zenón Vela
//Curso: Análisis de algoritmos
//(C) Febrero 2018
//ESCOM-IPN
//Práctica 1: Pruebas a Posteriori (algoritmos de ordenamiento)
//Implementación del algoritmo de ordenamiento por burbuja simple
//Compilación: "gcc burbujaSimple.c tiempo.x  -o burbujaSimple(tiempo.c si se tiene la implementación de la libreria o tiempo.o si solo se tiene el codigo objeto)"
//Ejecución: "./burbujaSimple n" (Linux y MAC OS)
//*****************************************************************

//*****************************************************************
//BIBLIOTECAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void burbujaSimple(int *A, int n);

//*****************************************************************
//VARIABLES GLOBALES
//*****************************************************************

//*****************************************************************
//PROGRAMA PRINCIPAL 
//*****************************************************************
int main (int argc, char* argv[])
{	
	//******************************************************************	
	//Variables del main
	//******************************************************************	
	double utime0, stime0, wtime0,utime1, stime1, wtime1; //Variables para medición de tiempos
	int n; //n determina el tamaño del algoritmo dado por argumento al ejecutar
	int i; //Variables para loops
	//******************************************************************

	//******************************************************************	
	//Recepción y decodificación de argumentos
	//******************************************************************	

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecución y cadena=n)
	if (argc!=2) 
	{
		printf("\nIndique el tamano del algoritmo - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	//Tomar el segundo argumento como tamaño del algoritmo
	else
	{
		n=atoi(argv[1]);
	}
	//******************************************************************
	
	//******************************************************************	
	//Crear y llenar el arreglo con los datos a ordenar
	//******************************************************************
	int *A = (int *)malloc(n * sizeof(int));
	for(i = 0; i < n; i++)
		scanf("%d", &A[i]);
	//******************************************************************

	//******************************************************************	
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************	
	uswtime(&utime0, &stime0, &wtime0);
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo
	//******************************************************************	
	burbujaSimple(A, n);
	//******************************************************************

	//******************************************************************	
	//Evaluar los tiempos de ejecución 
	//******************************************************************
	uswtime(&utime1, &stime1, &wtime1);
	
	//Cálculo del tiempo de ejecución del programa
	printf("\n");
	printf("Real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("User (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("Sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("Real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("User (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("Sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************

	//Terminar programa normalmente	
	exit (0);	
}

//************************************************************************
//DEFINICIÓN DE FUNCIONES 
//************************************************************************
void burbujaSimple(int *A, int n){
	//******************************************************************	
	//Variables de la función
	//******************************************************************
	int i, j; //Variables para loops
	int aux; //Variable de apoyo para swapping
	//******************************************************************
	
	//******************************************************************	
	//Algoritmo
	//******************************************************************
	for(i = 0; i <= n - 2; i++){
		for(j = 0; j <= n - 2 - i; j++){
			if(A[j] > A[j + 1]){
				aux = A[j];
				A[j] = A[j + 1];
				A[j + 1] = aux;
			}
		}
	}
	//******************************************************************
}