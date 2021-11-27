#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Biblioteca.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int cargar=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        utn_getInt(&option, "\n1.Cargar archivo(texto)\n2.Cargar Archivo(binario)\n3.Alta\n4.Modificar\n5.Eliminar\n6.Mostrar empleados\n7.Ordenar Sueldo\n8.Guardar en archivo(texto)\n9.Gurdar en archivo(binario)\n", "\nError", 1, 10, 5);
        switch(option)
        {
            case 1:
            	if(cargar == 0){
            		controller_loadFromText("data.csv",listaEmpleados);
            		cargar = 1;
            	}else{
            		printf("\nYa se cargo un archivo anteriormente");
            	}
                break;
            case 2:
            	if(cargar == 0){
            		controller_loadFromBinary("data2.csv", listaEmpleados);
            		cargar = 1;
            	}else{
            		printf("\nYa se cargo un archivo anteriormente");
            	}
            	break;
            case 3:
            	if(cargar ==1){
            		controller_addEmployee(listaEmpleados);
            	}else{
            		printf("No se cargo archivo o Se elimino la lista");
            	}

				break;
            case 4:
            	if(cargar ==1){
                	controller_editEmployee(listaEmpleados);
				}else{
					printf("No se cargo archivo o Se elimino la lista");
				}
                break;
            case 5:
            	if(cargar ==1){
                	controller_removeEmployee(listaEmpleados);
				}else{
					printf("No se cargo archivo o Se elimino la lista");
				}
				break;
            case 6:
            	if(cargar ==1){
                	controller_ListEmployee(listaEmpleados);
				}else{
					printf("No se cargo archivo o Se elimino la lista");
				}
            	break;
            case 7:
            	if(cargar ==1){
                	controller_sortEmployee(listaEmpleados);
				}else{
					printf("No se cargo archivo o Se elimino la lista");
				}

				break;
            case 8:
            	if(cargar ==1){
            		controller_saveAsText("data.csv", listaEmpleados);
            		cargar = 0;
            		printf("\nSe cargo correctamente\n");
            	}
				break;
            case 9:
            	if(cargar ==1){
            		controller_saveAsBinary("data2.csv", listaEmpleados);
					cargar = 0;
					printf("\nSe cargo correctamente\n");
				}
            	break;

        }
    }while(option != 10);
    return 0;
}



