#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleado.h"
#define CANT 1000
#define CHAR 51





int main()
{
    int option,sk,flag=0,idEmp=0,findEmployeeAux,idAux,contEmp=0,idRem,opcionOrd,opcionModif,validaNum;
    char name[51], lastName[51];
    float salary;
    employee emp[CANT];
    do
    {
        printf("\tMenu\n");
        printf("1- Alta empleados\n");
        printf("2- Modificar empleados\n");
        printf("3- Baja empleados\n");
        printf("4- Imprimir empleados\n\n");
        printf("5- Salir\n");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            system("cls");
            if(flag==0)
            {
                if(initEmployee(emp,CANT)==0)
                {
                    initEmployee(emp,CANT);
                    flag=1;
                }
            }
            if(getFreeSpace(emp,CANT)!=-1)
            {
                idEmp++;
                contEmp++;
            }
            else
            {
                printf("No hay espacio para agregar empleados!\n");
                break;
            }
            utn_getStringAvanzado(name,"Ingrese nombre: ","ERROR! El nombre debe ser solo letras\n",CHAR,2);
            utn_getStringAvanzado(lastName,"Ingrese apellido: ","ERROR! El apellido debe ser solo letras\n",CHAR,2);
            utn_getFlotante(&salary,"Ingrese salario: ","ERROR! Ingrese salario positivo\n",1,100000,2);
            utn_getEntero(&sk,"Ingrese sector","ERROR! Ingrese numeros entre 1 y 200\n",1,200,2);
            addEmployee(emp,CANT, name, lastName,salary,sk,idEmp);
            system("cls");
            printf("Accion: Empleado agregado correctamente\n");
            break;
        case 2:
            system("cls");

            if(firstEmployee(flag)!=0)  //si no es la primera vez
            {
                printEmployee(emp,CANT);
                utn_getEntero(&idAux,"Ingrese ID a modificar: ","ERROR! Ingrese numero entre 1 y 1000\n",1,1000,2);
                findEmployeeAux=findEmployeeById(emp,CANT,idAux);
                if(findEmployeeAux!=-1)  //si lo encontro
                {
                    utn_getEntero(&opcionModif,"Ingrese valor que desea modificar\n1 para nombre, 2 para apellido, 3 para salario, 4 para sk: ",
                                  "ERROR! Ingrese numero entre 1 y 5\n",1,5,2);
                    switch(opcionModif)
                    {
                    case 1:
                        utn_getStringAvanzado(name,"Ingrese nombre: ",
                                              "ERROR! El nombre debe ser solo letras\n",CHAR,2);
                        modifyEmployee(emp,CANT, name, lastName, salary,sk,findEmployeeAux,opcionModif);
                        break;
                    case 2:
                        utn_getStringAvanzado(lastName,"Ingrese apellido: ",
                                              "ERROR! El apellido debe ser solo letras\n",CHAR,2);
                        modifyEmployee(emp,CANT, name, lastName, salary,sk,findEmployeeAux,opcionModif);
                        break;
                    case 3:
                        utn_getFlotante(&salary,"Ingrese salario: ",
                                        "ERROR! Ingrese salario positivo\n",1,100000,2);
                        modifyEmployee(emp,CANT, name, lastName, salary,sk,findEmployeeAux,opcionModif);
                        break;
                    case 4:
                        utn_getEntero(&sk,"Ingrese sector: ",
                                      "ERROR! Ingrese numeros entre 1 y 200\n",1,200,2);
                        modifyEmployee(emp,CANT, name, lastName, salary,sk,findEmployeeAux,opcionModif);
                        break;
                        system("cls");
                        printf("Accion: Empleado modificado correctamente\n");
                    }
                }
                else
                {
                    system("cls");
                    printf("No se encuentra el ID\n");
                }
            }
            break;
        case 3:
            system("cls");
            if(firstEmployee(flag)!=0)  //si no es la primera vez
            {
                printEmployee(emp,CANT);
                utn_getEntero(&idRem,"Ingrese ID a eliminar: ",
                              "ERROR! Ingrese numero entre 1 y 1000\n",1,1000,2);
                removeEmployee(emp,CANT,idRem);
            }
            break;
        case 4:
            system("cls");
            if(firstEmployee(flag)!=0)  //si no es la primera vez
            {
                validaNum=utn_getEntero(&opcionOrd,"Ingrese el orden de ordenamiento, 1 para ascendente y 0 para descendente: ",
                                        "ERROR! Ingrese numero 0 o 1\n",0,1,2);
                switch(opcionOrd)
                {
                case 1:
                    if(validaNum!=-1)
                    {
                        sortEmployee(emp,CANT,name,lastName,opcionOrd);
                        printEmployee(emp,CANT);
                        if(totalSalary(emp,CANT)!=-1)
                            printf("El total de salarios es: %.02f\n",totalSalary(emp,CANT));
                        if(averageSalary(emp,CANT)!=-1)
                            printf("El promedio de salarios es: %d\n",averageSalary(emp,CANT));
                        if(excSalary(emp,CANT)!=-1)
                            printf("La cantidad de empleados que superan el salario promedio es de: %d\n",excSalary(emp,CANT));
                        printf("___________________________________________________________________\n");
                    }
                    break;
                case 0:
                    sortEmployee(emp,CANT,name,lastName,opcionOrd);
                    printEmployee(emp,CANT);
                    if(totalSalary(emp,CANT)!=-1)
                        printf("El total de salarios es: %.02f\n",totalSalary(emp,CANT));
                    if(averageSalary(emp,CANT)!=-1)
                        printf("El promedio de salarios es: %d\n",averageSalary(emp,CANT));
                    if(excSalary(emp,CANT)!=-1)
                        printf("La cantidad de empleados que superan el salario promedio es de: %d\n",excSalary(emp,CANT));
                    printf("___________________________________________________________________\n");
                    break;
                }
            }
            break;
        }
    }
    while(option!=5);

    return 0;
}
