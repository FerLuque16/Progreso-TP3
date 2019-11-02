#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    /*Employee *emp;
    FILE *archivo;
    char id[4096];
    char nombre[4096];
    char horasTrabajadas[4096];
    char sueldo[4096];

    archivo=fopen("data.csv","r");

    fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);

    do
    {
        fscanf(archivo,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
        emp=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

       ll_add(pArrayListEmployee,emp);
    }while(!feof(archivo));*/

    FILE *archivo;
    int retorno=-1;

    archivo=fopen(path,"r");

    if(archivo!=NULL)
        {
            retorno=parser_EmployeeFromText(archivo,pArrayListEmployee);
        }


    fclose(archivo);
    //archivo=NULL;




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
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee *emp;
    int auxId;
    char id[4096];
    char nombre[4096];
    char horasTrabajadas[4096];
    char sueldo[4096];
    int retorno=-1;
    int largo;

    printf("Ingrese nombre : ");
    scanf("%s",nombre);
    printf("\nIngrese horas trabajadas : ");
    scanf("%s",horasTrabajadas);
    printf("\nIngrese sueldo : ");
    scanf("%s" ,sueldo);


    largo=ll_len(pArrayListEmployee);
    auxId=largo+1;

    sprintf(id,"%d",auxId);

    //HACER UN PRINTF DE LOS DATOS Y UNA CONFIRMACION


    emp=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

    if(emp!=NULL)
    {
        ll_add(pArrayListEmployee,emp);
        retorno=0;
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
    //ll_sort(pArrayListEmployee,compareName,0); //1 para ascendente. 0 para descendente
    //ll_sort(pArrayListEmployee,compareHorasTrabajadas,0); //1 para ascendente. 0 para descendente
    ll_sort(pArrayListEmployee,compareSueldo,0); //1 para ascendente. 0 para descendente


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

