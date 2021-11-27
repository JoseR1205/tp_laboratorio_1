#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Biblioteca.h"
#include "Controller.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{

	int retorno = -1;
	if(path!=NULL && pArrayListEmployee!=NULL){
		FILE* f = fopen(path,"r");
		if(parser_EmployeeFromText(f, pArrayListEmployee)){
			retorno = 0;
		}
		fclose(f);
	}
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* f = fopen(path,"rb");
	if(path!=NULL && pArrayListEmployee!=NULL){
		if(parser_EmployeeFromBinary(f, pArrayListEmployee)==0){
			retorno = 0;
		}
		fclose(f);
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int id = autoId(pArrayListEmployee);
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	char idStr[5];
	char horasStr[10];
	char sueldoStr[10];
	if(utn_getChar(nombre, "\nIngresar Nombre:\n", "\nError", 128, 3)==0){
		if(utn_getInt(&horasTrabajadas, "\nIngresar horas trabajadas\n", "\nError", 1, 9999, 5)==0){
			if(utn_getInt(&sueldo, "\nIngresar Sueldo\n", "\nError", 1, 9999, 5)==0){
				sprintf(idStr, "%d", id);
				sprintf(horasStr, "%d", horasTrabajadas);
				sprintf(sueldoStr,"%d", sueldo);
				ll_add(pArrayListEmployee, employee_newParametros(idStr, nombre, horasStr, sueldoStr));
				retorno = 0;
			}
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* empleadoAux;
	int retorno = -1;
	int idSeleccion;
	controller_ListEmployee(pArrayListEmployee);
	utn_getInt(&idSeleccion, "\nIngresar id a modificar\n", "\nError", 1, 9999, 5);
	empleadoAux =  buscarPorId(pArrayListEmployee, idSeleccion);
	int opcion;
	if(pArrayListEmployee != NULL && empleadoAux!=NULL && empleadoAux->id==idSeleccion){
		utn_getInt(&opcion, "\nIngresar opcion a modificar\n1_Nombre\n2_Horas Trabajadas\n3_Sueldo\n", "error", 1, 3, 5);
		switch(opcion){
			case 1:
				utn_getChar(empleadoAux->nombre, "\nIngresar nombre\n", "\nError", 125, 5);
				break;
			case 2:
				utn_getInt(&empleadoAux->horasTrabajadas, "\nIngresar horas trabajadas\n", "\nError", 1, 999, 5);
				break;
			case 3:
				utn_getInt(&empleadoAux->sueldo, "\nIngesar sueldo\n", "\nError", 1, 9999, 5);
				break;
		}
		retorno = 0;
	}else{
		printf("\nID no existe\n");
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int idSeleccionado;
	Employee* empleadoAux;
	if(pArrayListEmployee!=NULL){
		controller_ListEmployee(pArrayListEmployee);
		utn_getInt(&idSeleccionado, "\nIngresar id para eliminar\n", "\nError", 1, 9999, 5);
		empleadoAux = buscarPorId(pArrayListEmployee, idSeleccionado);
		if(idSeleccionado== empleadoAux->id){
			for(int i = 0;i<ll_len(pArrayListEmployee);i++){
				if(empleadoAux == test_getNode(pArrayListEmployee, i)->pElement){
					employee_delete(empleadoAux);
					ll_remove(pArrayListEmployee, i);
					break;
				}
			}
			retorno = 0;
		}else{
			printf("\nId no existe");
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee* aux;
	int idaux;
	char nombreAux[128];
	int horasAux;
	int sueldoAux;
	if(pArrayListEmployee!=NULL){
		for(int i = 0; i<ll_len(pArrayListEmployee);i++){
			aux = ll_get(pArrayListEmployee, i);
			if(employee_getId(aux, &idaux)==0){
				if(employee_getNombre(aux, nombreAux)==0){
					if(employee_getHorasTrabajadas(aux, &horasAux)==0){
						if(employee_getSueldo(aux, &sueldoAux)==0){
							printf("\nId:|%d| Nombre:|%s| HorasTrabajadas: |%d| Sueldo: |%d|", idaux,nombreAux,horasAux,sueldoAux);
						}
					}
				}
			}
		}
		retorno = 0;
	}


	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;
	int ordenAux;
	if(utn_getInt(&opcion, "\n1) Ordenar sueldo de menor a mayor\n2) Ordenar de mayor a menor", "\nError", 1, 2, 5)==0){
		if(opcion==1){
			ordenAux=1;
		}else{
			ordenAux=-1;
		}
		ll_sort(pArrayListEmployee, criterio, ordenAux);
		retorno = 0;
	}
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
 	FILE* f = fopen(path,"w");
 	Employee* aux;
	if(f!=NULL && path!=NULL&& pArrayListEmployee!=NULL){
		fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");
		for(int i=0; i<ll_len(pArrayListEmployee); i++){
			aux = ll_get(pArrayListEmployee,i);
			fprintf(f,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
			employee_delete(aux);
		}
		fflush(f);
		retorno = 0;
		fclose(f);
	}
	ll_clear(pArrayListEmployee);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(path!=NULL&&pArrayListEmployee!=NULL){
		FILE* f = fopen(path,"wb");
		Employee* aux;
		for(int i = 0; i < ll_len(pArrayListEmployee);i++){
			aux = ll_get(pArrayListEmployee, i);
			fwrite(aux,sizeof(Employee),1,f);
			employee_delete(aux);
		}
		fclose(f);
		ll_clear(pArrayListEmployee);
		retorno = 0;
	}
    return retorno;
}

