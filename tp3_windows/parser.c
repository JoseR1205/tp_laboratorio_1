#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char idAux[5];
	char nombreAux[125];
	char horasAux[50];
	char sueldoAux[50];
	if(pFile != NULL && pArrayListEmployee != NULL){
		Employee* aux;
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux);
		do{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux)==4){
				aux = employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);
				if(aux!=NULL){
					ll_add(pArrayListEmployee, aux);
				}
			}
		}while(feof ( pFile ) ==0);
		retorno = 0;
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* aux;
	if(pFile != NULL && pArrayListEmployee != NULL){
		do{
			aux = employee_new();
			if(fread(aux,sizeof(Employee),1,pFile)==1){
				ll_add(pArrayListEmployee, aux);
			}else{
				employee_delete(aux);
				break;
			}
		}while(feof ( pFile ) == 0);
		retorno = 0;
	}
    return retorno;
}
