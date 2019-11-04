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
    int id=1000;
    int added;

    LinkedList* listaEmpleados = ll_newLinkedList();//Crea una lista en memoria


    do{
            system("cls");
            printf("----------------------------------MENU------------------------------------\n\n");
            printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
                   "3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n"
                   "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
                   "10. Salir\n\nIngrese la opcion a realizar: ");
            scanf("%d" ,&option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                if(ll_len(listaEmpleados)!=0)
                {
                    system("cls");
                    printf("Se han cargado los empleados correctamente\n\n");
                    system("pause");
                    break;
                }

                system("cls");
                printf("Ha ocurrido un error y no se han podido cargar los empleados");
                system("pause");


                break;

            case 2:

                controller_loadFromBinary("data.csv",listaEmpleados);
                break;

            case 3:
                if(ll_len(listaEmpleados)!=0)
                {
                    added=controller_addEmployee(listaEmpleados,id);
                    if(added==0)
                    {
                        id++;
                        break;
                    }
                }
                else
                {
                    system("cls");
                    printf("Debe cargar a los empleados primero para poder dar de alta a un nuevo empleado\n\n");
                    system("pause");
                }


                break;

            case 4:
                if(ll_len(listaEmpleados)!=0)
                {
                    controller_editEmployee(listaEmpleados);
                    break;
                }

                system("cls");
                printf("No es posible editar porque no hay empleados cargados\n\n");
                system("pause");

                break;

            case 5:
                if(ll_len(listaEmpleados)!=0)
                {
                    controller_removeEmployee(listaEmpleados);
                    break;
                }

                system("cls");
                printf("No es posible eliminar porque no hay empleados cargados\n\n");
                system("pause");


                break;

            case 6:
                if(ll_len(listaEmpleados)!=0)
                {
                    controller_ListEmployee(listaEmpleados);
                    break;

                }
                system("cls");
                printf("No es posible ordenar porque no hay empleados cargados\n\n");
                system("pause");

                break;

            case 7:
                if(ll_len(listaEmpleados)!=0)
                {
                    controller_sortEmployee(listaEmpleados);
                    break;
                }

                system("cls");
                printf("No es posible listar porque no hay empleados cargados\n\n");
                system("pause");


                break;

            case 8:
                controller_saveAsText("data.csv",listaEmpleados);

                break;

            case 9:
                controller_saveAsBinary("data.csv",listaEmpleados);

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
