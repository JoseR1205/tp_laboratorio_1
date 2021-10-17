

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Funciones.h"
#include "biblioteca.h"
#define LENT 1000
int main(void) {
	setbuf(stdout,NULL);
	Employee lista[LENT];
	initEmployees(lista, LENT);
	menu(lista,LENT);
	return 0;
}
