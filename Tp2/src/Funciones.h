#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/** \brief El menu que te dirije a las opciones
* \param list Employee*
* \param len int
*/
void menu(Employee *list, int len);
/** \brief genera un id que va incrementando
* \return id++
*/
int autoId();
/** \brief da una baja logica a un id ingresado
* \param list Employee*
* \param id int
* \return int return -1 si no se pudo validar y 0 si se valido correctamente
*/
int baja(Employee *list,int id);
/** \brief ordena el array separando los vacios y lo que no estan vacios
* \param list Employee*
* \param idEliminado int
* \param idUltimo int
* \return int -1 si no se pudo ordenar y 0 si se puedo
*/
int orden(Employee *list, int idEliminado, int idUltimo);
/** \brief se pide e ingresa datos por consola
* \param list Employee*
* \param len int
* \param nombreAux char
* \param apellidoAux char
* \param salarioAux float
* \param sector int
* \param id int
*/
void ingresarDatos(Employee *list, int len, char nombreAux[],char apellidoAux[],float salarioAux,int sector, int id);
/** \brief se saca el promedio y total de los salarios
* \param list Employee*
* \param len int
* \param total float
* \return promedio devuelve el promedio
*/
float cuentas(Employee *list,int len,float *total);
/** \brief muestra por consola el total, promedio y la cantidad de empleados que superan el salario promedio
* \param list Employee*
* \param len int
*/
void printSalario(Employee * list,int len);
/** \brief busca en el array el lugar vacio mas proximo
* \param list Employee*
* \param len int
* \return -1 si no encuentra vacio sino devuelve la posicion vacia
*/
int vacioProximo(Employee *list,int len);
#endif /* FUNCIONES_H_ */
