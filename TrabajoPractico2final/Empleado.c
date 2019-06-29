#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Empleado.h"
#include "utn.h"


/** \brief Indica que todas las posiciones del array estan libres,
 * Esta funcion pone la bandera (isEmpty) en TRUE en todas
 * las posiciones del array.
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \return int Retorna (-1) si hay error, (0) si no hay error
 */
int initEmployee(employee* emp,int CANT)
{
    int i;
    int retorno=-1;
    for(i=0; i<CANT; i++)
    {
        emp[i].isEmpty=1;
        retorno=0;
    }
    return retorno;
}
/** \brief Obtiene un espacio libre del array
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \return int Retorna (-1) si hay error, la posicion del array si no hay error.
 */
int getFreeSpace(employee* emp, int CANT)
{
    int i,retorno=-1;
    for(i=0; i<CANT; i++)
    {
        if(emp[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}
/** \brief Da de alta el empleado en una posicion libre del array
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param name char auxiliar, nombre del empleado
 * \param lastName char auxiliar, apellido del empleado
 * \param salary float auxiliar, salario del empleado
 * \param id int auxiliar, id del empleado
 * \return int Retorna (-1) si hay error, (0) si no hay error.
 */
int addEmployee(employee *emp,int CANT,char* name,
                char* lastName, float salary,int sector,int id)
{
    int i,retorno=-1;
    i=getFreeSpace(emp,CANT);
    if(i!=-1)  //si hay espacio libre
    {

        emp[i].isEmpty=0;
        strcpy(emp[i].name,name);
        strcpy(emp[i].lastName,lastName);
        emp[i].salary=salary;
        emp[i].sector=sector;
        emp[i].id=id;
        retorno=0;

    }
    return retorno;
}
/** \brief Busca el empleado por id
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param id int auxiliar, id a ser buscado en el array
 * \return int Retorna (-1) si hay error o si el id no se encontro,
 * la posicion del array si no hay error.
 */
int findEmployeeById(employee* emp, int CANT,int id)
{
    int i;
    int retorno=-1;
    for(i=0; i<CANT; i++)
    {
        if(emp[i].isEmpty==0)  //si esta ocupado
        {
            if(emp[i].id==id)
            {
                retorno=i;
                break;
            }
        }
        retorno=-1;
    }
    return retorno;
}
/** \brief Elimina el empleado buscandolo por id
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param id int auxiliar, id a ser eliminado en el array
 * \return int Retorna (-1) si no se encuentra el id
 * o no se elimina el empleado, 0 si se elimina correctamente
 */
int removeEmployee(employee* emp,int CANT,int id)
{
    int iAux,retorno=-1;
    char rta;
    iAux=findEmployeeById(emp,CANT,id);
    if(iAux!=-1) //lo encontro
    {
        do
        {
            printf("Eliminar registro? S/N: ");
            fflush(stdin);
            rta=toupper(getch());
        }
        while(rta!='S'&&rta!='N');
        if(rta=='S')
        {
            emp[iAux].isEmpty=1;
            system("cls");
            printf("Accion: Registro eliminado correctamente\n");
            retorno=0;
        }
        if(rta=='N')
        {
            system("cls");
            printf("Accion: No se elimino el registro\n");
            retorno=-1;
        }
    }
    else
    {
        system("cls");
        printf("Accion: No se encuentra el ID\n");
    }

    return retorno;
}
/** \brief Ordena el empleado ascendente o descendente segun se desee
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param name char auxiliar, nombre del empleado
 * \param lastName char auxiliar, apellido del empleado
 * \param opcion int, opcion deseada para ordenar el empleado
 * \return int Retorna (0) cuando se ordena
 */
int sortEmployee(employee* emp,int CANT,char* name, char* lastName,int opcion)
{
    employee empAux;
    int i, j;
    if(opcion==1)
    {
        for(i=0; i<CANT-1; i++)
        {
            for(j=i; j<CANT; j++)
            {
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0)
                {
                    if(emp[i].sector>emp[j].sector)
                    {
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
        for(i=0; i<CANT-1; i++)
        {
            for(j=i; j<CANT; j++)
            {
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0)
                {
                    if(strcmp(emp[i].lastName,emp[j].lastName)>0&&emp[i].sector==emp[j].sector)
                    {
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                    if(strcmp(emp[i].lastName,emp[j].lastName)==0&&emp[i].sector==emp[j].sector)
                    {
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
    }

    if(opcion==0)
    {
        for(i=0; i<CANT-1; i++)
        {
            for(j=i; j<CANT; j++)
            {
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0)
                {
                    if(emp[i].sector<emp[j].sector)
                    {
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
        for(i=0; i<CANT-1; i++)
        {
            for(j=i; j<CANT; j++)
            {
                if(emp[i].isEmpty==0&&emp[j].isEmpty==0)
                {
                    if(strcmp(emp[i].lastName,emp[j].lastName)<0&&emp[i].sector==emp[j].sector)
                    {
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                    if(strcmp(emp[i].lastName,emp[j].lastName)==0&&emp[i].sector==emp[j].sector)
                    {
                        empAux=emp[i];
                        emp[i]=emp[j];
                        emp[j]=empAux;
                    }
                }
            }
        }
    }
    return 0;
}
/** \brief Valida que se haya cargado un empleado al menos
 * \param flag int
 * \return int Retorna (-1) si ya se cargo un empelado al menos,
 * 0 si no se cargo el empleado.
 */
int firstEmployee(int flag)
{
    int retorno=-1;
    if(flag!=1)
    {
        system("cls");
        printf("___________________________________________________________________\n");
        printf("ERROR! Debera realizar la carga de un empleado\n");
        printf("___________________________________________________________________\n");
        retorno=0;
    }
    return retorno;
}
/** \brief Imprime el empleado por consola
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \return int Retorna (-1) si hay error, la posicion del array si no hay error.
 */
int printEmployee(employee* emp,int CANT)
{
    int i,retorno=-1;
    for(i=0; i<CANT; i++)
    {
        if(emp[i].isEmpty==0)
        {
            printf("___________________________________________________________________\n");
            printf("\tEmpleado:\nApellido: %s Sector: %d ID: %d\n",
                   emp[i].lastName,emp[i].sector,emp[i].id);
            printf("___________________________________________________________________\n");
            retorno=i;
        }

    }
    return retorno;
}
/** \brief Modifica el empleado solicitado por id
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param name char auxiliar, nombre del empleado a modificar
 * \param lastName char auxiliar, apellido del empleado a modificar
 * \param salary float auxiliar, salario del empleado a modificar
 * \param id int auxiliar, id del empleado a modificar
 * \return No retorna nada ya que es una funcion void
 */
void modifyEmployee(employee *emp,int CANT,char* name,
                    char* lastName, float salary,int sector,int id,int opcionModif)
{
    if(opcionModif==1)
        strcpy(emp[id].name,name);
    if(opcionModif==2)
        strcpy(emp[id].lastName,lastName);
    if(opcionModif==3)
        emp[id].salary=salary;
    if(opcionModif==4)
        emp[id].sector=sector;
}
/** \brief Calcula el promedio de salarios
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \return Retorna (-1) si hay error, 0 si se realiza el promedio.
 */
int averageSalary(employee* emp,int CANT)
{
    int i,retorno=-1;
    float salaryAux=0,empContAux=0;
    for(i=0; i<CANT; i++)
    {
        if(emp[i].isEmpty==0)
        {
            salaryAux+=emp[i].salary;
            empContAux++;
            retorno=0;
        }
        else
        {
            break;
        }
    }
    if(retorno!=-1)
    {
        retorno=salaryAux/empContAux;
    }
    return retorno;
}
/** \brief Calcula el total de salarios
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \return Retorna el promedio de salarios en float, retorna(-1) si hay error.
 */
float totalSalary(employee* emp,int CANT)
{
    int i,retorno=-1;
    float totalSalary=0;
    for(i=0; i<CANT; i++)
    {
        if(emp[i].isEmpty==0)
        {
            totalSalary+=emp[i].salary;
            retorno=totalSalary;
        }
    }
    return retorno;
}
/** \brief Calcula la cantidad de empleados que superan la media de salario
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \return Retorna (-1) si hay error, retorna el contador de cantidad
 */
int excSalary(employee* emp,int CANT)
{
    int i,retorno=-1,count=0;
    for(i=0; i<CANT; i++)
    {
        if(emp[i].isEmpty==0)
        {
            if(emp[i].salary>=averageSalary(emp,CANT))
            {
                count++;
            }
            retorno=count;
        }
    }
    return retorno;
}
