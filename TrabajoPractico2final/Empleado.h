#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} employee;

int initEmployee(employee*,int);
int getFreeSpace(employee*,int);
int addEmployee(employee*,int,char*,char*,float,int,int);
int findEmployeeById(employee*,int,int id);
int removeEmployee(employee*,int,int);
int sortEmployee(employee*,int,char*,char*,int);
int printEmployee(employee*,int);
int firstEmployee(int);
void modifyEmployee(employee*,int,char*,char*,float,int,int,int);
int averageSalary(employee*,int);
float totalSalary(employee*,int);
int excSalary(employee*,int);




#endif // EMPLEADO_H_INCLUDED
