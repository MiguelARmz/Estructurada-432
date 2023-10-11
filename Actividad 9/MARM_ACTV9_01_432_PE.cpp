//                             Ensenada, Baja California a 07 de Octubre del 2023     //
//Nombre:              Miguel Angel Ramirez Monjaraz                                  //
//Matricula:           372205                                                         //
//Programa:            Que contiene como menu varias acciones, desde llenar un vector //
//                     hasta una matriz, ademas de tener una opcion individual        //
//Nombre del programa: MARM_ACT9_01   


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Gauss.h"
#define M 15
#define A 4

int llena_mat(int mat[][A], int m, int n, int ri, int rf);
int llenar_vect(int vect[], int m, int ri, int rf);

void mostrar_mat(int mat[][A], int m, int n);
void mostrar_vect(int vect[], int m);

void menu();
int main()
{
    menu();
}
void menu()
{
    int resp = 1;
    int op;
    do
    {
        printf("     MENU     \n");
        printf("1 - Llenar vector aleatorio sin repetir\n");
        printf("2 - Llenar matriz aleatorio sin repetir\n");
        printf("3 - Mostrar vector llenado aleatoriamente\n");
        printf("4 - Mostrar matriz llenado aleatoriamente\n");
        printf("5 - Ordenar el vector\n");
        printf("6 - Buscar valor en el vector\n");
        printf("0 - Salir\n");
        op = valid_num(1,6,"Ingrese la opcion a realizar:");
        switch (op)
        {
            int vect[M];
            int mat[A][A];
            int num;
        case 1:
            llenar_vect(vect, M, 100, 200);
            break;
        case 2:
            llena_mat(mat, A, A, 1, 16);
            break;
        case 3:
            mostrar_vect(vect, M);
            break;
        case 4:
            mostrar_mat(mat, A, A);
            break;
        case 5:
            ordenar(vect, M);
            break;
        case 6:
            int x;
            printf("Que numeor buscas?: ");
            scanf("%d",&num);
            x =busque_Sec(vect, M, num);
            if ( x != 0)
            {
                printf("El numero si se encontro en la posicion %d con indice de %d\n",x + 1,x);
            }
            break;
        default:
            break;
        }
        printf("Presiona:\n");
        printf("1 - Continuar\n");
        printf("2 - Para salir\n");
        resp = valid_num(1,2,"Deseas continuar? \n");
    } while (resp == 1);
}

int llenar_vect(int vect[], int m, int ri, int rf)
{
    int numero, rango;
    rango = (rf - ri) + 1;
    srand(time(NULL));
    for (int i = 0; i <= m; i++)
    {
        do
        {
            numero = (rand() % rango) + ri;

        } while (sin_repetir(vect, m, numero) == 1);
        vect[i] = numero;
    }
    return vect[M];
}

int llena_mat(int mat[][4], int m, int n, int ri, int rf)
{
    int numero, rango;
    srand(time(NULL));
    rango = (rf - ri) + 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            do
            {
                numero = (rand() % rango) + ri;
                
            } while (sin_repetirMat(mat,m,n,numero) == 1);
            mat[i][j] = numero;
        }
    }
    return mat[4][4];
}

void mostrar_vect(int vect[], int m)
{
    for (int i = 0; i < m; i++)
    {
        printf("[");
        printf("%d", vect[i]);
        printf("]\n");
    }
}

void mostrar_mat(int mat[][A], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("[");
            printf("%d", mat[i][j]);
            printf("]");
        }
        printf("\n");
    }
}
