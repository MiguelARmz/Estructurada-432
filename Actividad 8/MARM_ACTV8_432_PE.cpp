//Miguel Angel Ramirez Monjaraz                  372205                                      //
//Ensenada, Baja California a 30 de Septiembre del 2023                                      //
//Programa que llena vectores y matriz, ademas las desplega                                  //
//Nombre de la actividad: MARM_ACT8_01_432                                                   //

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define M 10

//Funciones extras
void menu();
int valida_num(int ri, int rf);
bool no_repetir(int vect2[], int n);

//Funciones para llenar 
void vect_manual(int vect1[], int m);
void vect_alea(int vect2[], int m, int ri, int rf);
void vector3(int vect1[], int vect2[], int vect3[], int m);
void matriz12(int vect1[], int vect2[], int matriz[4][4]);

//Funciones para imprimir 
void imprimir_vects(int vect1[], int vect2[], int vect3[], int m);
void imprimir_mat(int matriz[4][4]);
int main()
{
    menu();
}

// Funcion del menu//
void menu()
{
    int res, m, vect1[M], vect2[M], vect3[M*2], matriz[4][4];
    do{
        printf("\n                 MENU          ");
        printf("\n Presiones el numero indicado para lo que quiera realizar");
        printf("\n1 - Llenar vector 1 de manera manual");
        printf("\n2 - Llenar vector 2 de forma aleatorea");
        printf("\n3 - Llenar vector 3 con el vector 1 y 2");
        printf("\n4 - Imprimir todos los vectores anteriores");
        printf("\n5 - Llenar matriz 4x4 con vector 1 y 2");
        printf("\n6 - Imprimir matriz");
        printf("\n0 - PARA SALIR");
        printf("\nQue accion deseas realizar?  ");
        scanf("%d", &res);
        switch(res)
        {
            case 1:

                printf("\nSe llenara el vector 1 de manera manual");
                vect_manual(vect1, M);
                break;

            case 2:
                printf("\nSe llenara de manera aleatoria el vector 2");
                vect_alea(vect2, M, 1, 10);
                break;

            case 3:
                printf("\n Has llenado el vector 3, con el vector 1 y 2");
                vector3(vect1, vect2, vect3, M);
                break;

            case 4:
                printf("\nSe mostraran los vectores llenados anteriormente ");
                imprimir_vects(vect1, vect2, vect3, M);
                break;
                
            case 5:
                printf("\nSe llenara la matriz con el vector 1 y 2");
                matriz12(vect1, vect2, matriz);
                break;
            
            case 6:
                printf("\nHas decidido mostrar la matriz");
                imprimir_mat(matriz);
                break;
            case 0:
                printf("Saliste");
                res = 0;
            default:
                break;
        }
    }while(res != 0);
}

// Funcion que nos ayuda en la 2 funcion para evitar los numeros repetidos //
bool no_repetir(int vect2[],int n)
{
    int i;
    for (i = 0; i <10; i++)
    {
        if (n == vect2[i])
        {
            return true;
        }            
    }
    return false;
}

// Funcion para validar numeros que ingresan //
int valida_num(int ri, int rf)
{
    int n;
    char xnum[30];
    printf("\nDame un numero entre el %d y %d: ", ri, rf);
    fflush(stdin);
    gets(xnum);
    n = atoi(xnum);
    if (n > rf)
    {
        printf("\n El numero esta fuera del rango, te pasaste");
        n = 70;
    }
    
    if (n < ri)
    {
        printf("\n El numero esta fuera del rango, fue menor al rango propuesto");
        n = 30;
    }

    return n;
}

//FUNCIONES DE LA PRACTICA//


void vect_manual(int vect1[], int m)
{
    int i;
    for(i = 0; i < m; i++)
    {
        vect1[i] = valida_num(30, 70);
    }
}




void vect_alea(int vect2[], int m, int ri, int rf)
{
    int rango, i, n;
    rango = (rf - ri) + 1;
    srand(time(NULL)); 
    for(i = 0; i < m; i++)
    {
        do
        {
            n = (rand()%rango) + ri;
        } while (no_repetir(vect2, n));
        vect2[i] = n;  
    }
}





void vector3(int vect1[], int vect2[], int vect3[], int m)
{
    int i;
    for(i = 0; i < m; i++)
    {
        vect3[i] = vect1[i];
    }

    for(i = 0; i < m; i++)
    {
        vect3[i+10] = vect2[i];
    }
}





void imprimir_vects(int vect1[], int vect2[], int vect3[], int m)
{
    int i;
    printf("\nVECTOR 1");
    printf("\n[");
    for (i = 0; i < m; i++)
    {
        printf("%d, ", vect1[i]);
    }
    printf("]");
    printf("\n");

    printf("\nVECTOR 2");
    printf("\n[");
    for (i = 0; i < m; i++)
    {
        printf("%d, ", vect2[i]);
    }
    printf("]");
    printf("\n");

    printf("\nVECTOR 3");
    printf("\n[");
    for (i = 0; i < m*2; i++)
    {
        printf("%d, ", vect3[i]);
    }
    printf("]");
    printf("\n");
}






void matriz12(int vect1[], int vect2[], int matriz[4][4])
{
    int j, i, k;
    k = 0;
    for (j = 0; j < 2; j++)
    {
        for (i = 0; i < 4; i++)
        {
            matriz[j][i] = vect1[k];
            k = k + 1;
        }
    }

    matriz[2][0] = vect1[8];
    matriz[2][1] = vect1[9];
    matriz[2][2] = vect2[0];
    matriz[2][3] = vect2[1];

    for (i = 0; i < 4; i++)
    {
        matriz[3][i] = vect2[i+2];
    }

}






void imprimir_mat(int matriz[4][4])
{
    int j, i;
    printf("\n");
    for (j = 0; j < 4; j++)
    {
        printf("\n[");
        for(i = 0; i < 4; i++)
        {
            printf("%d, ", matriz[j][i]);
        }
        printf("]");
    }
    printf("\n");

}