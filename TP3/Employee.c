#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

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

int employee_compareId(void* arg1, void* arg2)
{
    int retorno=-1;
    Employee* emp1;
    Employee* emp2;

    emp1=(Employee*) arg1;
    emp2=(Employee*) arg2;

    if(emp1->id>emp2->id)
    {
        retorno=1;
    }
    else if(emp1->id==emp2->id)
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

int employee_menuEdit(Employee* this)
{
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    int option;
    char rta1[21],rta2[21],rta3[21];

    do
    {
        printf("1. Editar nombre\n2. Editar horas trabajadas\n3. Editar sueldo\n4. Salir");
        scanf("%d" ,&option);

        switch(option)
        {


            case 1:
                if(getString(nombre,"Ingrese el nombre: ","ERROR. Datos no validos",1,1000000,3)==0)
                {
                    if(employee_confirmation(rta1,"Desea modificar el nombre? Ingrese si o no: ","DATOS INCORRECTOS",3)==0 && strcmp(rta1,"si")==0)
                    {
                        if(employee_setNombre(this,nombre)==0)
                        {
                            printf("El nombre se ha editado correctamente");
                            system("pause");
                        }
                        else
                        {
                            printf("No se editado el nombre");
                            system("pause");
                        }


                    }
                    else
                    {
                        printf("No se ha editado");
                        system("pause");
                    }

                }
                else
                {
                    printf("No se ha podido editar el nombre");
                    system("pause");
                }
                break;

            case 2:
                if(getInt(&horasTrabajadas,"Ingrese las horas trabajadas: ","ERROR. Datos no validos",1,1000000,3)==0)
                {
                    if(employee_confirmation(rta2,"Desea modificar las horas trabajadas? Ingrese si o no: ","DATOS INCORRECTOS",3)==0 && strcmp(rta2,"si")==0)
                    {
                        if(employee_setHorasTrabajadas(this,horasTrabajadas)==0)
                        {
                            printf("Las horas se han editado correctamente");
                            system("pause");
                        }
                        else
                        {
                            printf("No se ha editado el nombre");
                            system("pause");
                        }

                    }
                    else
                    {
                        printf("No se ha editado");
                        system("pause");
                    }
                }
                else
                {
                    printf("No se ha podido editar las horas");
                    system("pause");

                }


                break;

            case 3:
                if(getInt(&sueldo,"Ingrese el sueldo: ","ERROR. Datos no validos",1,1000000,3)==0)
                {
                    if(employee_confirmation(rta3,"Desea modificar el sueldo? Ingrese si o no: ","DATOS INCORRECTOS",3)==0 && strcmp(rta3,"si")==0)
                    {
                        if(employee_setSueldo(this,sueldo)==0)
                        {
                            printf("Se ha editado el sueldo correctamente");
                            system("pause");
                        }
                        else
                        {
                            printf("No se ha podido editar el sueldo");
                            system("pause");
                        }

                    }
                    else
                    {
                        printf("No se ha editado");
                        system("pause");
                    }
                }
                else
                {
                    printf("No se ha podido editar el sueldo");
                    system("pause");
                }

                break;

            case 4:
                break;

            default:
                printf("Opcion no valida");
                system("pause");
                break;

        }

    }while(option != 4);


    return 0;


}

int employee_confirmation(char* input,char message[],char eMessage[],int retry)
{
    int retorno=-1;
    char auxStr[21];

    if(input!=NULL && message!=NULL && eMessage != NULL)
    {
        do
        {
            system("cls");
            printf("%s",message);
            scanf("%s",auxStr);

            strlwr(auxStr);

            if(strcmp(auxStr,"si")==0 || strcmp(auxStr,"no")==0)
            {
                strcpy(input,auxStr);
                retorno=0;
                break;

            }
            else
            {
                printf("%s" ,eMessage);
                system("pause");
                retry--;
            }
        }
        while(retry>=0);
    }

    if(retry==-1)
    {
        retorno=-1;
    }
    return retorno;
}

int employee_findEmployeeById(LinkedList* pArrayListEmployee)
{
    int i;
    int len;
    int id;
    int retorno=-1;
    Employee *auxEmp;

    if(getInt(&id,"Ingrese el id del empleado: ","ID NO VALIDO",1,10000,3)==0)
    {

        len=ll_len(pArrayListEmployee);


        for(i=0;i<len;i++)
        {
            auxEmp=ll_get(pArrayListEmployee,i);
            if(auxEmp->id==id)
            {
            retorno=i;
            }
        }
    }
    else
    {
        printf("No se pudo encontrar al empleado deseado");
        system("pause");
    }

    return retorno;


}

int employee_SortMenu(LinkedList* pArrayListEmployee)
{
    int option;

    do
    {
        system("cls");
        printf("------------------------MENU DE ORDENAMIENTO--------------------------\n\n");
        printf("1. Ordenar nombres de forma ascendente\n2. Ordenar nombres de forma descendente\n3. Ordenar por sueldo de mayor a menor\n"
               "4. Ordenar por sueldo de menor a mayor\n5. Ordenar por horas trabajadas de mayor a menor\n6. Ordenar por horas trabajadas de menor a mayor\n"
               "7. Ordenar por ID de mayor a menor\n8. Atras");



        printf("\n\nIngrese la opcion a realizar");
        scanf("%d" ,&option);
        switch(option)
        {
            case 1:
                system("cls");
                printf("Ordenando. Espere por favor");
                ll_sort(pArrayListEmployee,employee_compareName,1);
                system("cls");
                printf("Se ha ordenado correctamente");
                system("pause");

                break;

            case 2:
                system("cls");
                printf("Ordenando. Espere por favor");
                ll_sort(pArrayListEmployee,employee_compareName,0);
                system("cls");
                printf("Se ha ordenado correctamente");
                system("pause");

                break;

            case 3:
                system("cls");
                printf("Ordenando. Espere por favor");
                ll_sort(pArrayListEmployee,employee_compareSueldo,0);
                system("cls");
                printf("Se ha ordenado correctamente");
                system("pause");

                break;

            case 4:
                system("cls");
                printf("Ordenando. Espere por favor");
                ll_sort(pArrayListEmployee,employee_compareSueldo,1);
                system("cls");
                printf("Se ha ordenado correctamente");
                system("pause");

                break;

            case 5:
                system("cls");
                printf("Ordenando. Espere por favor");
                ll_sort(pArrayListEmployee,employee_compareHorasTrabajadas,0);
                system("cls");
                printf("Se ha ordenado correctamente");
                system("pause");

                break;

            case 6:
                system("cls");
                printf("Ordenando. Espere por favor");
                ll_sort(pArrayListEmployee,employee_compareHorasTrabajadas,1);
                system("cls");
                printf("Se ha ordenado correctamente");
                system("pause");

                break;

            case 7:
                system("cls");
                printf("Ordenando. Espere por favor");
                ll_sort(pArrayListEmployee,employee_compareId,0);
                system("cls");
                printf("Se ha ordenado correctamente");
                system("pause");

                break;

            case 8:
                break;

            default:
                printf("Opcion no valida");
                break;

        }

    }while(option!=8);
    return 0;
}

















