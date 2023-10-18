//                             Ensenada, Baja California a 07 de Octubre del 2023     //
// Nombre:              Miguel Angel Ramirez Monjaraz                                  //
// Matricula:           372205                                                         //
// Programa:            Libreria PROPIA, DEL MIGUEL, SOBRE FUNCIONES REUTILIZABLES     //
// Nombre del programa: MARM_ACT9_01
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Gauss.h"

#define N 500

typedef struct _alum
{
    int status;
    int matri;
    char nombre[30];
    char appaterP[30];
    char apmater[30];
    int sexo;
    int edad;
} Talum;

Talum gen_regmanu();
Talum gen_rega_alea();
Talum eliminar_regis(Talum vect[], int *n);
void imprimir_registros(Talum vect[], int n);
void ordenar_regis(Talum vect[], int n);
void buscar_regi(Talum vect[], int n);
void letrero();
void menu();

int main()
{
    menu();
    return 0;
}
void menu()
{
    int x = 0;
    int i = 0, op;
    Talum vect[500];
    do
    {
        letrero();
        op = valid_num(0, 6, "Ingresa la accion a realizar: ");
        int j = i + 10;
        switch (op)
        {
        case 0:
            op = 0;
        case 1:
            if (i <= 490) 
            {
                for (i; i < j; i++) 
                {
                    vect[i] = gen_rega_alea();
                }
            } 
            else 
            {
                printf("Te queda solo una opción más para ingresar 10 registros automáticamente\n");
            }
            printf("%d", i);
            break;
        case 3:
            eliminar_regis(vect, &i);
            break;
        case 2:
            if (i < 500) {
                vect[i] = gen_regmanu();
                i++;
            } else 
            {
                printf("Sin espacio para continuar el registro\n");
                op = 0;
            }
            break;
        case 4:
            buscar_regi(vect,i);
            break;
        case 5:
            ordenar_regis(vect, i);
            break;
        case 6:
            imprimir_registros(vect, i);
            break;
        default:
            break;
        }
    } while (op != 0);
}

void letrero()
{
    printf("                     MENU              \n");
    printf("1 - AGREGAR (AUTOM 10 REGISTROS)\n");
    printf("2 - AGREGAR MANUAL\n");
    printf("3- ELIMINAR REGISTRO (lógico)\n");
    printf("4.- BUSCAR\n5- ORDENAR\n6.- IMPRIMIR\n0.- SALIR\n ");
}

Talum gen_regmanu()
{
    Talum regis;
    regis.status = 1;
    regis.matri = valid_num(300000, 399999, "Ingresa tu martirucla");
    printf("Ingresa tu nombre: ");
    fflush(stdin);
    gets(regis.nombre);
    printf("Ingresa tu apellido parterno: ");
    fflush(stdin);
    gets(regis.appaterP);
    printf("Ingresa tu apellido materno: ");
    fflush(stdin);
    gets(regis.apmater);
    printf("Presiona: \n");
    printf("1 - Hombre \n");
    printf("2 - Mujer \n");
    regis.sexo = valid_num(1, 2, "Ingresa tu sexo");
    regis.edad = valid_num(1, 100, "Ingresa tu edad");
    return regis;
}

Talum gen_rega_alea()
{
    Talum regis;

    char *nHombre[10] = {"Erick", "Juan", "Pedro", "Luis", "Carlos", "Miguel", "Alejandro", "José", "Javier", "Antonio"};
    char *nMujer[10] = {"Maria", "Ana", "Laura", "Sofia", "Paula", "Isabel", "Carmen", "Patricia", "Raquel", "Marta"};
    char *apPater[10] = {"Gonzalez", "Lopez", "Rodriguez", "Martinez", "Perez", "Fernandez", "Gomez", "Sanchez", "Ramirez", "Torres"};
    char *apMater[10] = {"Flores", "Morales", "Vazquez", "Jimenez", "Reyes", "Diaz", "Torres", "Gutierrez", "Ruiz", "Mendoza"};
    regis.status = 1;
    regis.matri = (rand() % 100000) + 300000;
    int sexo = rand() % 2;
    if (sexo == 1)
    {
        strcpy(regis.nombre, nHombre[rand() % 10]);
    }
    else
    {
        strcpy(regis.nombre, nMujer[rand() % 10]);
    }
    strcpy(regis.appaterP, apPater[rand() % 10]);
    strcpy(regis.apmater, apMater[rand() % 10]);
    regis.sexo = sexo;
    regis.edad = (rand() % 88) + 13;
    return regis;
}

Talum eliminar_regis(Talum vect[], int *n)
{
    int matri = valid_num(300000, 399999, "Ingresa la matricula del registro que deseas borrar: ");
    int k = 0;
    Talum veck[N];

    for (int i = 0; i < *n; i++)
    {
        if (matri != vect[i].matri)
        {
            //Va metiendo los datos que no sean de la matricula buscada
            veck[k] = vect[i];
            k++;
        }
    }

    if (k == *n)
    {
        // Lo que hace es que si el for anterior se completo completamente es porque no se borro ninguna matricula y retorna el vector dado
        printf("Matrícula no encontrada\n");
        return vect[N];
    }
    else
    {
        printf("Registro con matrícula %d eliminado.\n", matri);
        *n = k; 
        // Va actualizando el registro que le dimos porque  eliminamos el registro 
        for (int i = 0; i < k; i++)
        {
            vect[i] = veck[i];
        }
        //retorno ya el vector dados
        return vect[k];
    }
}

void imprimir_registros(Talum vect[], int n)
{
    printf("-------------------------------------------------------------------------------------\n");
    printf("|  N°  |  MATRICULA  |    NOMBRE   |  AP.PATERNO  |  AP. MATERNO  |  SEXO  |  EDAD  |\n");
    printf("-------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("| %4d | %11d | %12s | %12s | %13s | %5d | %5d |\n", i, vect[i].matri, vect[i].nombre, vect[i].appaterP, vect[i].apmater, vect[i].sexo, vect[i].edad);
    }
    printf("-------------------------------------------------------------------------------------\n");
}

void ordenar_regis(Talum vect[], int n)
{
    int i, j;
    Talum temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (vect[j].matri < vect[i].matri)
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
}

void buscar_regi(Talum vect[], int n)
{
    int i;
    int matri = valid_num(300000, 399999, "Ingresa la matricula del registro que deseas buscar: ");

    for (i = 0; i < n; i++)
    {
        if (matri == vect[i].matri)
        {
            printf("Se encontro el usuario con matricula %d en el registro.\n", matri);
            printf("-------------------------------------------------------------------------------------\n");
            printf("|  N°  |  MATRICULA  |    NOMBRE   |  AP.PATERNO  |  AP. MATERNO  |  SEXO  |  EDAD  |\n");
            printf("-------------------------------------------------------------------------------------\n");
            printf("| %4d | %11d | %12s | %12s | %13s | %5d | %5d |\n", i, vect[i].matri, vect[i].nombre, vect[i].appaterP, vect[i].apmater, vect[i].sexo, vect[i].edad);
            printf("-------------------------------------------------------------------------------------\n");
            return;
        }
    }
    if(i == n)
    {
        printf("No se encontro el usario con matricula %d", matri);
    }
}