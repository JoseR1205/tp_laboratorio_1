/*
 ============================================================================
 Name        : Tp1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "bibliotecaTp1.h"

int main(void) {
	setbuf(stdout,NULL);
	float A = 0;
	float B = 0;
	float resultados[6];
	int opcion=0;
	int continuar=1;
	int errorDiv=0;
	int errorFactor=0;
	int errorFactor2=0;
	int verificarDatoA=1;
	int verificarDatoB=1;
	int verificarCalculo=1;
	while(continuar ==1){
		printf("\n 1. Ingresar 1er operando (A=%f)",A);
		printf("\n 2. Ingresar 2do operando (B=%f)",B);
		printf("\n 3. Calcular todas las operaciones");
		printf("\n 4. Informar resultados");
		printf("\n 5. Salir \n");
		fflush(stdin);
		scanf("%d", &opcion);
		switch(opcion){
			case 1:
				A = IngresarFloat(A);
				verificarCalculo=1;
				verificarDatoA=0;
				break;
			case 2:
				B = IngresarFloat(B);
				verificarCalculo=1;
				verificarDatoB=0;
				break;
			case 3:
				calcularOperaciones(A, B, resultados, &errorDiv, &errorFactor, &errorFactor2, verificarDatoA, verificarDatoB, &verificarCalculo);
				break;
			case 4:
				informarResultados(resultados, errorDiv, errorFactor, errorFactor2, verificarCalculo);
				break;
			case 5:
				printf("\n fin...");
				continuar=0;
				break;
			default:
				printf("\n error ingresar opcion valida \n");
		}

	}
	return EXIT_SUCCESS;
}
