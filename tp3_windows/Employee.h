#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief genera espacio en memoria

 * \return Employee
 *
 */
Employee* employee_new();
/** \brief Se ingresa los datos a Employee
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/** \brief Libera el espacio de la memoria de un empleado
 *
 * \param path char*
 * \param this Employee*
 *
 */
void employee_delete(Employee* this);

/** \brief se settea el id en un empleado
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id);

/** \brief se pide el id de un empleado por parametro
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief se settea el nombre en un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief se pide el nombre de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief se settea las horas de trabjo de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief se pide las horas de trabajo de un empleado
 *
 * \param this Employee*
 * \param horasTrabajdas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief se settea el sueldo de un empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief se pide el sueldo de un empleado
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief se busca el id mas grande en la lista para ingresar auto id a los nuevo empleados
 *
 * \param Lthis Employee*
 * \return int
 *
 */
int autoId(LinkedList* Lthis);
Employee* buscarPorId(LinkedList* this,int idIngresado);

/** \brief se comprueba el saldo y devuelve el criterio
 *
 * \param var1 void*
 * \param var2 void*
 * \return int
 *
 */
int criterio(void* var1,void* var2);
#endif // employee_H_INCLUDED
