#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "utn.h"
#include "string.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{


    FILE *archivo;
    int retorno=-1;

    archivo=fopen(path,"r");

    if(archivo!=NULL)
        {
            retorno=parser_EmployeeFromText(archivo,pArrayListEmployee);
        }


    fclose(archivo);

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
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int id)
{
    Employee *emp;
    //employee
    //int auxId;
    char auxId[4096];
    char nombre[4096];
    char horasTrabajadas[4096];
    char sueldo[4096];
    int retorno=-1;
    int flag=0;
    int confirm;
    char rta[21];
   // int largo;

    if(getString(nombre,"Ingresar nombre: ","DATOS NO VALIDOS",1,128,3)==0)
                {
                    printf("Se ha registrado el nombre correctamente");
                    system("pause");
                    flag++;

                }
                else
                {
                    printf("No se ha podido agregar al empleado");
                    system("pause");
                }
    if(flag==1)
    {


        if(getStringNumeros(horasTrabajadas,"Ingrese las horas trabajadas: ","DATOS NO VALIDOS",1,128,3)==0)
                {
                    printf("Se han registrado las horas correctamente");
                    system("pause");
                    flag++;
                }
                else
                {
                    printf("No se ha podido agregar al empleado");
                    system("pause");
                }
    }

    if(flag==2)
    {
        if(getStringNumeros(sueldo,"Ingrese el sueldo: ","DATOS NO VALIDOS",1,128,3)==0)
                {
                    printf("Se ha registrado el sueldo correctamente: ");
                    system("pause");
                    flag++;
                }
                else
                {
                    printf("No se ha podido agregar al empleado");
                    system("pause");

                }
    }


    if(flag==3)
    {

    id++;
    sprintf(auxId,"%d",id);

    printf("%5s %10s %10s %10s\n" ,"ID","NOMBRE","HORAS","SUELDO");
    printf("\n%5d %10s %10s %10s\n" ,id,nombre,horasTrabajadas,sueldo);
    system("pause");

    confirm=employee_confirmation(rta,"Desea dar de alta al empleado? Ingrese si o no: ","Respuesta no valida",3);

    if(confirm==0 && strcmp(rta,"si")==0)
    {
        emp=employee_newParametros(auxId,nombre,horasTrabajadas,sueldo);

        if(emp!=NULL)
        {
            ll_add(pArrayListEmployee,emp);
            retorno=0;
        }
    }
    else
    {
        printf("No se ha dado de alta al empleado");
        system("pause");
    }

    }


    //HACER UN PRINTF DE LOS DATOS Y UNA CONFIRMACION



   /* emp=employee_newParametros(auxId,nombre,horasTrabajadas,sueldo);

    if(emp!=NULL)
    {
        ll_add(pArrayListEmployee,emp);
        retorno=0;
    }*/

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
    Employee* emp;
    int auxID;
    //char nombre[128];
    //int horasTrabajadas;
    //int sueldo;

   /* printf("Ingrese el ID del empleado a editar : ");
    scanf("%d", &auxID);*/

    auxID=employee_findEmployeeById(pArrayListEmployee);
    if(auxID!=-1)
    {

    emp=ll_get(pArrayListEmployee,auxID);

    employee_printEmployee(emp);

    employee_menuEdit(emp);
    }



    /*printf("Ingrese nombre : ");
    scanf("%s",nombre);
    printf("\nIngrese horas trabajadas : ");
    scanf("%d",&horasTrabajadas);
    printf("\nIngrese sueldo : ");
    scanf("%d" ,&sueldo);

    employee_setNombre(emp,nombre);
    employee_setHorasTrabajadas(emp,horasTrabajadas);
    employee_setSueldo(emp,sueldo);

    employee_printEmployee(emp);*/
    /*do
    {

    }while();
    */

    return 1;
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
    Employee* emp;
    int auxID;
    //controller_ListEmployee(pArrayListEmployee);
   /* system("cls");
    printf("Ingrese el ID del empleado a dar de baja : ");
    scanf("%d", &auxID);*/
    auxID=employee_findEmployeeById(pArrayListEmployee);
    if(auxID!=-1)
    {
    emp=ll_get(pArrayListEmployee,auxID);

    employee_printEmployee(emp);

    ll_remove(pArrayListEmployee,auxID);
    }

    return 1;
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


    Employee *emp;
    int len;
    int i;
    int id;
    char nombre[4096];
    int horasT;
    int sueldo;

    len=ll_len(pArrayListEmployee);

    system("cls");
    printf("%5s %10s %10s %10s\n" ,"ID","NOMBRE","HORAS","SUELDO");

    for(i=0;i<len;i++)
    {

        if(i%50==0 && i!=0)
        {
            system("pause");
        }

        emp=ll_get(pArrayListEmployee,i);

        employee_getId(emp,&id);
        employee_getNombre(emp,nombre);
        employee_getHorasTrabajadas(emp,&horasT);
        employee_getSueldo(emp,&sueldo);

        printf("\n%5d %10s %10d %10d\n" ,id,nombre,horasT,sueldo);



    }


    return 1;
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
    //ll_sort(pArrayListEmployee,employee_compareName,0); //1 para ascendente. 0 para descendente
    //ll_sort(pArrayListEmployee,employee_compareHorasTrabajadas,0); //1 para ascendente. 0 para descendente
    //ll_sort(pArrayListEmployee,employee_compareSueldo,0); //1 para ascendente. 0 para descendente
    //ll_sort(pArrayListEmployee,employee_compareId,0);
    employee_SortMenu(pArrayListEmployee);


    return 1;
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
    return 1;
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
    return 1;
}

