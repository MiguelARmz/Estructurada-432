//                             Ensenada, Baja California a 03 de Noviembre del 2023    //
// Nombre:              Miguel Angel Ramirez Monjaraz                                  //
// Matricula:           372205                                                         //
// Programa:            Librerira de Gauss                                             //
// Nombre del programa: MARM_ACT11_01
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//definicion de funciones void//
void imprimir(char cadena[]);
void a_mayusculas(char cadena[]);
void vocales_conso(char cadena[],char vocal[],char consonate[]);
void separar_nombre(char cadena[]);
void validar_datos(char cadena[]);
void eliminarEspacioInicial(char cadena[]);



//definicion de funcion int //
int letras_simbolos(char cadena[]);
int tam_carac(char cadena[]);
int vali_rango(char msge[],int ri,int rf);



int vali_rango(char msge[],int ri,int rf)
{
    int  num;
    char xnum[30];
    do
    {
        puts(msge);
        fflush(stdin);
        gets(xnum);
        num = atoi(xnum);
    }while(num < ri || num > rf);
    return num;

}




int tam_carac(char cadena[])
{
    int i;
    for(i=0;cadena[i] != '\0';i++);
    return i;
}
int letras_simbolos(char caracter[]) 
{
    for (int i = 0; caracter[i] != '\0'; i++) {
        if (!((caracter[i] >= 65 && caracter[i] <= 90) ||    // Letras mayúsculas
              (caracter[i] >= 97 && caracter[i] <= 122) ||   // Letras minúsculas
              (caracter[i] == 39 || caracter[i] == 44 ||    // Caracteres permitidos
               (caracter[i] >= 45 && caracter[i] <= 47) ||  
               (caracter[i] == 95 || caracter[i] == 96) ||  
              caracter[i] == 32)))                            // Espacio
        {
            return 0;
        } 
        else 
        {
            if(caracter[0] == 32)
            {
                return 0;
            }
            if (caracter[i - 1] == 32 && caracter[i] == 32) 
            {
                return 0;
            }
        }
    }
    return 1; 
}


void validar_datos(char msge[],char cadena[])
{
    int i=1;
    do
    {
        puts(msge);
        fflush(stdin);
        gets(cadena);
        if(letras_simbolos(cadena))
        {
            i=0;
        }
    } while (i == 1);
}

void a_mayusculas(char cadena[])
{
    int i;
    for(i=0;cadena[i] != '\0';i++)
    {
        if(cadena[i] >= 97)
        {
            if(cadena[i] <= 122)
            {
                cadena[i] = cadena[i] - 32;
            }
        }
    }
}
void vocales_conso(char cadena[],char vocal[],char consonante[])
{
    int j,i=0,k=0;
    for(j=0;cadena[j] != '\0';j++)
    {
        if (cadena[j] != 'A' && cadena[j] != 'E' && cadena[j] != 'I' && cadena[j] != 'O' && cadena[j] != 'U')
        {
            consonante[i] = cadena[j];
            i++;
        }
        else
        {   //VOCALES//
            vocal[k] = cadena[j];
            k++;
        }
    }
    consonante[i] = '\0';
    vocal[i] = '\0';

}
void separar_nombre(char cadena[]) 
{
    char compues_prohi[20][8] = {"DA", "DAS", "DE", "DEL", "DER", "DI", "DIE", "DD", "Y", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON"};
    char nueva_cadena[100]; 
    int i = 0;
    int j = 0;
    int longitud = tam_carac(cadena);

    while (i < longitud) {
        int longitud_palabra = 0;
        while (i < longitud && cadena[i] != ' ') {
            longitud_palabra++;
            i++;
        }

        char palabra[15];
        strncpy(palabra, &cadena[i - longitud_palabra], longitud_palabra);
        palabra[longitud_palabra] = '\0';

        int es_compuesto = 0;
        for (int k = 0; k < 20; k++) {
            if (strcmp(palabra, compues_prohi[k]) == 0) {
                es_compuesto = 1;
                break;
            }
        }

        if (!es_compuesto) {
            for (int k = 0; k < longitud_palabra; k++) {
                nueva_cadena[j] = palabra[k];
                j++;
            }
            nueva_cadena[j] = ' ';
            j++;
        }
        while (i < longitud && cadena[i] == ' ') {
            i++;
        }
    }

    nueva_cadena[j] = '\0';
    strcpy(cadena, nueva_cadena);
}
void quitar_ene(char cadena[])
{
    int i,longi;
    longi = tam_carac(cadena);
    for(i =0 ;i<longi;i++)
    {
        if(cadena[i] == -92)
        {
            cadena[i] = 'X';    
        }
        if(cadena[i] == -91)
        {
            cadena[i] = 'X';    
        }
                
    }
}

void eliminarEspacioInicial(char cadena[]) 
{
    if (cadena[0] == ' ') 
    {
        int longitud = tam_carac(cadena);
        for (int i = 0; i < longitud; i++) 
        {
            cadena[i] = cadena[i + 1];
        }
    }
}

