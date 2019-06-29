#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "utn.h"
static int getInt(int* pBuffer)
{
    return scanf("%d",pBuffer);
}

static int getFloat(float* pBuffer)
{
    return scanf("%f",pBuffer);
}

/** \brief Obtiene un numero entero
 * \param *pEntero puntero a la variable int
 * \param *msg puntero al array char
 * \param *msgErr puntero al array char
 * \param int min rango de valor minimo del entero a obtener
 * \param int max rango de valor maximo del entero a obtener
 * \param id reintentos reintentos para ingresar bien el entero
 * \return Retorna (-1) si hay error, (0) si no hay error.
 */
int utn_getEntero(  int* pEntero, char* msg,
                    char* msgErr,int min, int max,
                    int reintentos)
{
    int retorno=-1;
    int bufferInt;
    if(pEntero != NULL && msg != NULL && msgErr != NULL
            && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getInt(&bufferInt) == 1) &&
                    (bufferInt >= min && bufferInt <= max))
            {
                *pEntero = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                printf("%s",msgErr);
            }
        }
        while(reintentos>=0);

    }
    return retorno;
}
/** \brief Obtiene un numero flotante
 * \param *pFlotante puntero a la variable float
 * \param *msg puntero al array char
 * \param *msgErr puntero al array char
 * \param int min rango de valor minimo del flotante a obtener
 * \param int max rango de valor maximo del flotante a obtener
 * \param id reintentos reintentos para ingresar bien el flotante
 * \return Retorna (-1) si hay error, (0) si no hay error.
 */
int utn_getFlotante(  float* pFlotante, char* msg, char* msgErr,int min, int max,
                      int reintentos)
{
    int retorno=-1;
    float bufferFloat;
    if(pFlotante != NULL && msg != NULL && msgErr != NULL
            && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getFloat(&bufferFloat) == 1) &&
                    (bufferFloat >= min && bufferFloat <= max))
            {
                *pFlotante = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                printf("%s",msgErr);
            }
        }
        while(reintentos>=0);

    }
    return retorno;
}
/** \brief Valida si es una letra incluido el espacio
 * \param *input puntero al array char
 * \return Retorna (-1) si hay error, (1) si no hay error.
 */
int esLetra(char* input)
{
    int retorno=-1,i=0;
    while (input[i]!='\0')
    {
        if((input[i]!=' ')&&(input[i] < 'a' || input[i] > 'z') && (input[i] < 'A' || input[i] > 'Z'))
        {
            retorno=-1;
            break;
        }
        i++;
    }
    if(input[i]=='\0')
    {
        retorno=1;
    }
    return retorno;
}
/** \brief Obtiene una cadena de caracteres
 * \param *input puntero al array char
 * \param *msg puntero al array char
 * \return No retorna nada ya que es una funcion void
 */
void utn_getString(char* input, char* msg)
{
    fflush(stdin);
    printf("%s", msg);
    fgets(input,100,stdin);
    input[strcspn(input, "\n")] = 0;
}
/** \brief Obtiene una cadena de caracteres validando solo letras
 * \param *input puntero al array char
 * \param *msg puntero al array char
 * \param *msgErr puntero al array char
 * \param int cant entero de la cantidad total del array
 * \param id reintentos reintentos para ingresar bien la cadena
 * \return Retorna (0) si hay error, (1) si no hay error.
 */
int utn_getStringAvanzado(char* input,char* msg,char* msgErr,int cant, int reintentos)
{
    char aux[cant];
    do
    {
        utn_getString(aux,msg);
        if(esLetra(aux)!=-1)
        {
            strcpy(input,aux);
            return 1;
        }
        else
        {
            reintentos--;
            printf("%s",msgErr);
        }
    }
    while(reintentos>=0);
    return 0;
}
