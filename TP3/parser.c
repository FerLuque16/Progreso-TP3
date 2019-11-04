#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee *emp;
    char id[4096];
    char nombre[4096];
    char horasTrabajadas[4096];
    char sueldo[4096];
    int retorno=-1;
    int r;

   // archivo=fopen("data.csv","r");
   pFile = fopen("data.csv","r");

    if(pFile!=NULL)
    {
    r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
    do
    {
        r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
        if(r==4)
        {

        emp=employee_newParametros(id,nombre,horasTrabajadas,sueldo);

        if(emp!=NULL)
            {
                ll_add(pArrayListEmployee,emp);
                retorno=0;
            }

        }
        else
            break;


    }while(!feof(pFile));
    }
    else
    {
        printf("No se pudo abrir el archivo");
        exit(EXIT_FAILURE);
    }


    fclose(pFile);


    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
