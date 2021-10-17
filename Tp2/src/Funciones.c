#include "Funciones.h"
#include "biblioteca.h"
#include "ArrayEmployees.h"
void menu(Employee *list, int len){
	int opcion=0;
	char nombreAux[51];
	char apellidoAux[51];
	float salarioAux=0;
	int sector=0;
	int idSeleccionado;
	int modificar;
	int maxid;
	int flagPrimero=-1;
	int idAux;
	int opcionInfo;
	while(opcion !=5){
		if(utn_getInt(&opcion, "\n1. ALTAS \n2. MODIFICAR \n3. BAJA \n4. INFORMAR \n5. Cerrar\n Ingresar Opcion\n", "\nError esa opcion no esta disponible\n", 1, 5, 500)==0 && list != NULL && len > 0){
			switch(opcion){
				case 1:
					idAux =  autoId();
					ingresarDatos(list, len, nombreAux, apellidoAux, salarioAux, sector,idAux);
					orden(list, vacioProximo(list, len), idAux);
					flagPrimero = 0;
					break;
				case 2:
					if(flagPrimero == 0){
						maxid=printEmployees(list, len);
						if(utn_getInt(&idSeleccionado, "\nseleccioner id para modificar\n", "\nError Id¡¡\n", 1, 1000, 2)==0){
							idSeleccionado = findEmployeeById(list, len, idSeleccionado);
							if(idSeleccionado<maxid&&idSeleccionado>-1){
								if(utn_getInt(&modificar, "\nIngresar la opcion a modificar\n1_Nombre\n2_Apellido\n3_Salario\n4_Sector", "volver a ingresar numero", 1, 4, 2)==0){
									switch (modificar) {
										case 1:
											utn_getChar(list[idSeleccionado].name, "ingresar Nuevo nombre", "error", 51, 5);
											break;
										case 2:
											utn_getChar(list[idSeleccionado].lastName, "ingresar Nuevo apellido", "error", 51, 5);
											break;
										case 3:
											utn_getFloat(&list[idSeleccionado].salary, "ingresar Salario nuevo", "error", 0, 999999, 5);
											break;
										case 4:
											utn_getInt(&list[idSeleccionado].sector, "ingresar sector nuevo", "error", 1, 1000, 5);
											break;
									}
								}
							}else{
								printf("El id ingresado no existe \nVolviendo al menu...\n");
							}
						}
					}else{
						printf("dar de alta un empleado");
					}
					break;
				case 3:
					if(flagPrimero == 0){
						maxid=printEmployees(list, len);
						if(utn_getInt(&idSeleccionado, "\nseleccioner id para dar de baja\n", "\nError Id¡¡\n", 1, 1000, 2)==0){
							idSeleccionado = findEmployeeById(list, len, idSeleccionado);
							if(idSeleccionado < maxid && idSeleccionado > -1){
								if(baja(list, idSeleccionado)==0){
									orden(list, idSeleccionado, maxid);
									printf("Se dio de baja correctamente");
								}
							}else{
								printf("La id no existe \nVolviendo al menu...");
							}
						}
					}else{
						printf("dar de alta un empleado");
					}
					break;
				case 4:
					if(flagPrimero == 0){
						if(utn_getInt(&opcionInfo, "\n1_Listar empleado por orden alfabetica por apellido y sector\n2_Total y promedio de los salarios", "error", 1, 3, 20)==0){
							if(opcionInfo==1){
								sortEmployees(list, len, 1);
								printEmployees(list, len);
							}else{
								printSalario(list, len);
							}
						}
					}else{
						printf("dar de alta un empleado");
					}
					break;
			}
		}
	}


}
void printSalario(Employee * list,int len){
	float total;
	float promedio = cuentas(list, len, &total);
	int promedioMas=0;
	for(int i = 0;i<len;i++){
		if(list[i].isEmpty==1 && list[i].salary>promedio){
			promedioMas++;
		}
	}
	printf("\nEl total de los salarios es : %f \nEl promedio es : %f\nLa cantidad de personas con salario superior al promedio son : %d \n",total,promedio,promedioMas);
}
float cuentas(Employee *list,int len,float *total){
	float acumulador=0;
	float contador=0;
	float promedio;
	for(int i = 0;i<len;i++){
		if(list[i].isEmpty==1){
			acumulador = acumulador + list[i].salary;
			contador++;
		}
	}
	*total = acumulador;
	promedio = acumulador/contador;
	return promedio;
}
int vacioProximo(Employee *list,int len){
	int retorno = -1;
	for(int i=0;i<len;i++){
		if(list[i].isEmpty==0){
			retorno = i;
			break;
		}
	}
	return retorno;
}
void ingresarDatos(Employee *list, int len, char nombreAux[],char apellidoAux[],float salarioAux,int sector, int id){
	if(utn_getChar(nombreAux, "\ningresar nombre del empleado\n", "\nerror volver a ingresar nombre\n", 51, 20)==0){
		if(utn_getChar(apellidoAux, "\nIngresar apellido del empleado\n", "\nerror volver a ingresar apellido", 51, 20)==0){
			if(utn_getFloat(&salarioAux, "\nIngresar Sueldo\n", "\nError volver ingresar sueldo\n ", 1, 999999, 5)==0){
				if(utn_getInt(&sector, "\nIngresar sector\n", "\nError volver a ingresar sector", 1, 1000, 5)==0){
					addEmployee(list, len, id, nombreAux, apellidoAux, salarioAux, sector);
				}
			}
		}
	}
}

int orden(Employee *list, int idEliminado, int idUltimo){
	int retornar = -1;
	if(list != NULL && idEliminado < idUltimo){
		list[idEliminado] = list[idUltimo-1];
		list[idUltimo-1].isEmpty = 0;
		retornar = 0;
	}
	return retornar;
}

int baja(Employee *list,int id){
	int retorno =-1;
		if(list !=NULL && id > -1){
			list[id].isEmpty=0;
			retorno = 0;
		}
	return retorno;
}

int autoId(){
	static int id =1;
	return id++;
}
