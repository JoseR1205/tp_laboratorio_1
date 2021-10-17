/*
 * bibliotecaTp1.h
 *
 *  Created on: 7 sep. 2021
 *      Author: pc
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef BIBLIOTECATP1_H_
#define BIBLIOTECATP1_H_

/// \fn float suma(float num1, float num2)
/// \brief Pide dos numeros para ser sumados
/// \param Primer float a sumar
/// \param Segundo float a sumar
/// \return retorna un flotante como la suma de ambos numeros.
float suma(float num1,float num2);
/// \fn float resta(float num1, float num2)
/// \brief Pide 2 numeros para restar
/// \param Primer float para ser restado
/// \param Segundo float para restar
/// \return retorna un float como la resta de ambos numeros
float resta(float num1,float num2);
/// \fn float division(float num1,float num2,int *error)
/// \brief pide 2 numeros para dividir y se comprueba si no se divide por 0
/// \param Primer float para dividir
/// \param Segundo float como divisor
/// \param Tercer int para comprobar si el divisor es 0
/// \return retorna un float con el resultado de la division.
float division(float num1,float num2,int *error);
/// \fn float multiplicacion(float num1, float num2)
/// \brief Pide 2 numeros para multiplicar
/// \param Primer float para multiplicar
/// \param Segundo float para multiplicar
/// \return retorna un float como la multiplicacion de ambos numeros
float multiplicacion(float num1,float num2);
/// \fn float factorial(float num1,int *error)
/// \brief Pide un numero para calcular el factorial y se compruba si se puede o no factriar
/// \param Primer float para factoriar
/// \param Segundo int es para comprobar si es un numero negativo
/// \return retorna un float como factorial
float factorial(float num1,int *error);
/// \fn float ingresarFloat(float num)
/// \brief pide un numero para guardar
/// \param Primer float para guardar
/// \return retorna un float
float IngresarFloat(float num);
/// \fn void calcularOperaciones(float num1,float num2,float resultados[],int *errorDiv,int *errorFactor,int *errorFactor2, int verificarDatoA, int verificarDatoB, int *verificarCalculo)
/// \brief Pide numeros para llamar a todas las funciones que hacen calculos y los resultados los guarda en un array tambien verifica si estos calculos de pueden hacer
/// \param Primer float para hacer todos los calculos
/// \param Segundo float tambien para hacer todos los calculos
/// \param Tercer float pide un array para que se guarden los resultados ahi
/// \param Cuarto int para recibir un valor y comprobar si se puede dividir
/// \param Quinto int para comprobar si se puede sacar el factorial
/// \param Sexto int para comprobar si se puede sacar el factorial
/// \param Septimo int para verificar si se ingreso anteriormente un valor
/// \param Octavo int para verificar si se ingreso anteriormente el segundo valor
/// \param Noveno int se recibe un valor para avisar que se hizo el calculo
void calcularOperaciones(float num1,float num2,float resultados[],int *errorDiv,int *errorFactor,int *errorFactor2, int verificarDatoA, int verificarDatoB, int *verificarCalculo);
/// \fn void informarResultados(float resultados[],int errorDiv,int errorFactor,int errorFactor2,int verificarCalculo)
/// \brief Pide el array con los resultados y verifica que se tiene que mostrar tambien
/// \param Primer float se pide un array con todos los resultados ingresados
/// \param segundo int Se compruba si se dividio por 0 o no
/// \param Tercer int comprueba si se ingreso un numero menor a 0
/// \param Cuarto int comprueba si se ingreso un numero menor a 0
/// \param Quinto int verifica si se hizo el calculo anteriormente para mostrar los resultados
void informarResultados(float resultados[],int errorDiv,int errorFactor,int errorFactor2,int verificarCalculo);
#endif /* BIBLIOTECATP1_H_ */





