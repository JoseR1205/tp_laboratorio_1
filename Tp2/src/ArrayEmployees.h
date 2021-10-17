
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
} Employee;

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);

#endif /* ARRAYEMPLOYEES_H_ */
