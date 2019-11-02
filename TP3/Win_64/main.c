#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

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
    LinkedList* listaEmpleados = ll_newLinkedList();//Crea una lista en memoria

    //printf("1. Cargar");

    do{
            system("cls");
            printf("1. Cargar\n2.Añadir empleado\n3.Largo\n4.Listar\n5.Ordenar\n\n");
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
                controller_addEmployee(listaEmpleados);
                break;

            case 3:
                largo=ll_len(listaEmpleados);
                printf("%d\n" ,largo);
                system("pause");
                break;

            case 4:

                controller_ListEmployee(listaEmpleados);
                system("pause");
                break;

            case 5:
                system("cls");
                printf("Ordenando. Espere por favor");
                controller_sortEmployee(listaEmpleados);
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;

            case 10:
                break;
        }
    }while(option != 10);
    return 0;
}
