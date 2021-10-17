#include "ArrayEmployees.h"

int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	if(list != NULL && len > 0){
		retorno = 0;
		for(int i = 0; i<len ; i++){
			list[i].isEmpty = 0;
		}
	}
	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	int idA = id-1;
	if(list != NULL && len == 1000 && list[idA].isEmpty==0){
		list[idA].id=id;
		strcpy(list[idA].lastName,lastName);
		strcpy(list[idA].name,name);
		list[idA].salary = salary;
		list[idA].sector=sector;
		list[idA].isEmpty=1;
		retorno = 0;
	}
	return retorno;
}
int findEmployeeById(Employee* list, int len,int id)
{
	int idP = -1;
	if(list != NULL && len > 0){
		for(int i=0;i<len;i++){
			if(list[i].id==id){
				idP = i;
				break;
			}
		}
	}
	return idP;
}
int removeEmployee(Employee* list, int len, int id)
{
	int retorno =-1;
	if(list != NULL && id > -1){
		list[id].isEmpty=0;
		retorno = 0;
	}
	return retorno;
}
int sortEmployees(Employee* list, int len, int order)
{
	int retorno =-1;
	Employee auxE;
	if(list!=NULL && len > -1){
		if(order==1){
			for(int i = 0 ; i < len ; i++){
				for(int j = 0 ; j < len-i ; j++){
					if((list[j].lastName[0]>list[j+1].lastName[0])&&list[j+1].isEmpty==1){
							auxE = list[j];
							list[j]=list[j+1];
							list[j+1]=auxE;
					}
				}
			}
		}else{
			for(int i = 0 ; i < len ; i++){
				for(int j = 0 ; j > len-i ; j++){
					if((list[j].lastName[0]<list[j+1].lastName[0])&&list[j+1].isEmpty==1){
						auxE = list[j];
						list[j]=list[j+1];
						list[j+1]=auxE;
					}
				}
			}
		}

		retorno = 0;
	}
	return retorno;
}
int printEmployees(Employee* list, int length)
{
	int retorno = -1;
	int i = 0;
	if(list!=NULL && length > 0){
		while(list[i].isEmpty==1){
			printf("\n id:%d Apellido:|%s| Nombre:|%s| Salario:|%f| Sector:|%d|",list[i].id,list[i].lastName,list[i].name,list[i].salary,list[i].sector);
			i++;
		}
		retorno = i;
	}
	return retorno;
}
