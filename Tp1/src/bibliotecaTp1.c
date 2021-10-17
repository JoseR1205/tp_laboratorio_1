
#include "bibliotecaTp1.h"

float IngresarFloat(float num){
	printf("\ningresar numero \n");
	fflush(stdin);
	scanf("%f", &num);
	return num;
}

float suma(float num1,float num2){
	float resultado;
	resultado = num1+num2;
	return resultado;
}
float resta(float num1,float num2){
	float resultado;
	resultado = num1-num2;
	return resultado;
}
float division(float num1,float num2,int *error){
	float resultado;
	if(num2!=0){
		*error = 0;
		resultado = num1/num2;
	}else{
		*error = 1;
	}
	return resultado;
}
float multiplicacion(float num1,float num2){
	float resultado;
	resultado = num1*num2;
	return resultado;
}
float factorial(float num1,int *error){
	int resultado = 1;
	float devolverR=0;
	if(num1>0){
		for(int ind = (int)num1 ; ind>1 ; ind--){
			resultado = resultado * ind;
		}
		*error = 0;
	}else{
		if(num1==0){
			*error =0;
		}else{
			*error = 1;
		}
	}
	devolverR=(float)resultado;
	return devolverR;
}
void calcularOperaciones(float num1,float num2,float resultados[],int *errorDiv,int *errorFactor,int *errorFactor2, int verificarDatoA, int verificarDatoB, int *verificarCalculo){
	if(verificarDatoA==0 && verificarDatoB==0){
		resultados[0]=suma(num1,num2);
		resultados[1]=resta(num1,num2);
		resultados[2]=division(num1,num2,&*errorDiv);
		resultados[3]=multiplicacion(num1,num2);
		resultados[4]=factorial(num1,&*errorFactor);
		resultados[5]=factorial(num2,&*errorFactor2);
		*verificarCalculo=0;
	}else{
		printf("error falta ingresar datos\n");
	}
}
void informarResultados(float resultados[],int errorDiv,int errorFactor,int errorFactor2,int verificarCalculo){
	if(verificarCalculo==0){
		printf("\nEl resultado de A+B es: %f \n",resultados[0]);
		printf("\nEl resultado de A-B es: %f \n",resultados[1]);
		if(errorDiv==0){
			printf("\nEl resultado de A/B es: %f \n",resultados[2]);
		}else{
			printf("\nNo es posible dividir por cero \n");
		}
		printf("\nEl resultado de A*B es: %f \n",resultados[3]);
		if(errorFactor==0){
			printf("\nEl factorial de A es: %f \n",resultados[4]);
		}
		if(errorFactor2==0){
			printf("\nEl factorial de B es: %f \n",resultados[5]);
		}
	}else{
		printf("\n Error se necesita calcular operaciones antes \n");
	}
}

