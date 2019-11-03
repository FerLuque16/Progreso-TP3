#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

Employee* employee_new()
    {
        Employee *this;

        this=malloc(sizeof (Employee));

		return this;
    }

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)

    {
        Employee *empleado;
		int id,horaT,sueldo;

		id=atoi(idStr);

		horaT=atoi(horasTrabajadasStr);
		sueldo=atoi(sueldoStr);

		empleado=employee_new();

		employee_setId(empleado,id);
		employee_setNombre(empleado,nombreStr);
		employee_setHorasTrabajadas(empleado,horaT);
		employee_setSueldo(empleado,sueldo);



		return empleado;
    }


void employee_delete(Employee* this)
{
        if(this!=NULL)
        {
            free(this);
        }



}


int employee_setId(Employee* this,int id)
    {
        int retorno=-1;
        if(this!=NULL && id>0)
            {
                this->id=id;
                retorno=0;

            }

        return retorno;
    }


int employee_getId(Employee* this,int* id)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                *id=this->id;
                retorno=0;
            }

        return retorno;
    }

int employee_setNombre(Employee* this,char* nombre)
    {
        int retorno=-1;

        if(this!=NULL )
            {
                strcpy(this->nombre,nombre);
                retorno=0;

            }
        return retorno;
    }

int employee_getNombre(Employee* this,char* nombre)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                strcpy(nombre,this->nombre);
                retorno=0;
            }

        return retorno;
    }

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                this->horasTrabajadas=horasTrabajadas;
                retorno=0;
            }

        return retorno;

    }

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                *horasTrabajadas=this->horasTrabajadas;
                retorno=0;
            }

        return retorno;
    }


int employee_setSueldo(Employee* this,int sueldo)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                this->sueldo=sueldo;
                retorno=0;
            }

        return retorno;

    }

int employee_getSueldo(Employee* this,int* sueldo)
    {
        int retorno=-1;

        if(this!=NULL)
            {
                *sueldo=this->sueldo;
                retorno=0;
            }

        return retorno;
    }

int employee_compareName(void* arg1,void* arg2)
{
    Employee* emp1;
    Employee* emp2;

    emp1=(Employee*) arg1;
    emp2=(Employee*) arg2;

    return strcmp(emp1->nombre,emp2->nombre);

}

int employee_compareHorasTrabajadas(void* arg1, void* arg2)
{
    int retorno=-1;
    Employee* emp1;
    Employee* emp2;

    emp1=(Employee*) arg1;
    emp2=(Employee*) arg2;

    if(emp1->horasTrabajadas > emp2->horasTrabajadas)
    {
        retorno=1;
    }
    else if(emp1->horasTrabajadas == emp2->horasTrabajadas)
    {
        retorno=0;
    }


    return retorno;
}

int employee_compareSueldo(void* arg1, void* arg2)
{
    int retorno=-1;
    Employee* emp1;
    Employee* emp2;

    emp1=(Employee*) arg1;
    emp2=(Employee*) arg2;

    if(emp1->sueldo>emp2->sueldo)
    {
        retorno=1;
    }
    else if(emp1->sueldo==emp2->sueldo)
    {
        retorno=0;
    }

    return retorno;

}

void employee_printEmployee(Employee* this)
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    employee_getId(this,&id);
    employee_getNombre(this,nombre);
    employee_getHorasTrabajadas(this,&horasTrabajadas);
    employee_getSueldo(this,&sueldo);

    printf("%5s %10s %10s %10s\n" ,"ID","NOMBRE","HORAS","SUELDO");
    printf("\n%5d %10s %10d %10d\n" ,id,nombre,horasTrabajadas,sueldo);
    system("pause");
}


















