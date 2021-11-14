#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"
#include "LinkedList.h"

int criterio(void* var1,void* var2){
	int retorno = 0;
	if(var1!=NULL && var2!=NULL){
		if(((Employee*)var1)->sueldo > ((Employee*)var2)->sueldo){
			retorno = 1;
		}
		if(((Employee*)var1)->sueldo < ((Employee*)var2)->sueldo ){
			retorno = -1;
		}
	}
	return retorno;
}

Employee* buscarPorId(LinkedList* this,int idIngresado){
	Employee* empleadoAux;
	if(this != NULL && idIngresado >0){
		for(int i = 0; i<ll_len(this);i++){
			empleadoAux=ll_get(this, i);
			if(empleadoAux->id==idIngresado){
				break;
			}
		}
	}
	return empleadoAux;
}

void employee_delete(Employee* this){
	if(this != NULL){
		free(this);
	}
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr){
	Employee* pEmpleado = employee_new();
	employee_setId(pEmpleado, atoi(idStr));
	employee_setNombre(pEmpleado, nombreStr);
	employee_setHorasTrabajadas(pEmpleado, atoi(horasTrabajadasStr));
	employee_setSueldo(pEmpleado, atoi(sueldoStr));
	return pEmpleado;
}

Employee* employee_new(){
	Employee* pEmpleado = (Employee*)malloc(sizeof(Employee));
	return pEmpleado;
}

int employee_setId(Employee* this,int id){
	int retorno=-1;
	if(this!=NULL && id>0){
		this->id=id;
		retorno = 0;
	}
	return retorno;
}
int employee_getId(Employee* this,int* id){
	int retorno=-1;
	if(this!=NULL && id>0){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre != NULL){
		strcpy(this->nombre,nombre);
		retorno = 0;
	}
	return retorno;
}
int employee_getNombre(Employee* this,char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno = 0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno=-1;
	if(this!=NULL && horasTrabajadas > 0){
		this->horasTrabajadas=horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno=-1;
	if(this!=NULL && horasTrabajadas > 0){
		*horasTrabajadas = this->horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
	int retorno=-1;
	if(this!=NULL && sueldo > 0){
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo){
	int retorno=-1;
	if(this!=NULL && sueldo > 0){
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

int autoId(LinkedList* Lthis){
	int idAux;
	int idMayor=0;
	if(Lthis != NULL){

		for(int i = 0; i< ll_len(Lthis);i++){
			employee_getId(ll_get(Lthis, i), &idAux);
			if(idMayor<idAux){
				idMayor = idAux;
			}
		}
	}
	return idMayor+1;
}
