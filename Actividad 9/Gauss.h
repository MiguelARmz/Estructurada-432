//                             Ensenada, Baja California a 07 de Octubre del 2023     //
//Nombre:              Miguel Angel Ramirez Monjaraz                                  //
//Matricula:           372205                                                         //
//Programa:            Libreria PROPIA, DEL MIGUEL, SOBRE FUNCIONES REUTILIZABLES     //
//Nombre del programa: MARM_ACT9_01   
#include <stdio.h>
#include <stdlib.h>                                               
#define A 4


int busque_Sec(int vect[], int n,int num);
int sin_repetir(int vect[], int n,int num);
int sin_repetirMat(int mat[][A], int m, int n,int num);
int valid_num(int ri, int rf, char msge[]);
void ordenar(int vect[],int m);

int valid_num(int ri, int rf, char msge[])
{
    char xnum[30];
    int num;
    do
    {
        puts(msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
    } while (num < ri || num > rf);
    return num;
}

void ordenar(int vect[], int m)
{
    int i, j;
    int temp;
    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            if (vect[j] < vect[i])
            {
                temp = vect[i];
                vect[i] = vect[j];
                vect[j] = temp;
            }
        }
    }
}

int busque_Sec(int vect[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (num == vect[i])
        {
            return i;
        }
    }
    return -1;
}

int sin_repetir(int vect[], int n, int num)
{
    for (int i = 0; i < n; i++)
    {
        if (num == vect[i])
        {
            return 1;
        }
    }
    return 0;
}

int sin_repetirMat(int mat[][A], int m, int n,int num)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            
            if (num == mat[i][j])
            {
                return 1;
            }
        }
    }
    return 0;
}

