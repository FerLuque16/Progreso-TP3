#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"
#include "string.h"

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
    int option = 0;
    int largo;
    int id=1000;
    int added;
    int numero;

    LinkedList* listaEmpleados = ll_newLinkedList();//Crea una lista en memoria

    //printf("1. Cargar");

    do{
            system("cls");
            printf("1. Cargar\n2.Añadir empleado\n3.Largo\n4.Listar\n5.Ordenar\n6.Baja\n7.Editar\n");
            scanf("%d" ,&option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                largo=ll_len(listaEmpleados);
                printf("%d\n" ,largo);
                system("pause");
                break;

            case 2:

                added=controller_addEmployee(listaEmpleados,id);
                if(added==0)
                {
                    id++;
                }
                break;

            case 3:
                largo=ll_len(listaEmpleados);
                printf("%d\n" ,largo);
                system("pause");
                break;

            case 4:
                if(listaEmpleados!=NULL)
                {


                controller_ListEmployee(listaEmpleados);
                system("pause");
                }
                else
                {
                    printf("No hay empleados cargados");
                    system("pause");
                }
                break;

            case 5:
                system("cls");

                controller_sortEmployee(listaEmpleados);
                break;

            case 6:
                controller_removeEmployee(listaEmpleados);
                break;

            case 7:
                controller_editEmployee(listaEmpleados);
                break;

            case 8:
                if(getInt(&numero,"Numero: ","ERROR",1,5,2)==0)
                {
                    printf("%d",numero);
                    system("pause");
                }
                else
                {
                    printf("ERROR");
                }

                //employee_menuEdit(listaEmpleados);

                break;

            case 9:
                /*if(employee_confirmation(letras,"Ingrese si o no: ","ERROR",3)==0 && strcmp(letras,"si")==0)
                {
                    printf("%s",letras);
                    system("pause");
                }
                else
                {
                    printf("Limite sobrepasado");
                    system("pause");
                }*/

                break;

            case 10:
                break;

            default:
                printf("Opcion no valida");
                system("pause");
                break;
        }
    }while(option != 10);
    return 0;
}
