//                             Ensenada, Baja California a 03 de Noviembre del 2023    //
// Nombre:              Miguel Angel Ramirez Monjaraz                                  //
// Matricula:           372205                                                         //
// Programa:            Genera registros de personas con su curp correspondiente       //
// Nombre del programa: MARM_ACT11_01
#include "curp.h"
#define N 2000

//DEFINIENDO ESTRUCTURAS//
typedef struct _alum
{
    char nombre1[30];
    char nombre2[30];
    char appater[30];
    char apmater[30];
}Nombre;

typedef struct _fnaci
{

    char anio[5] ;
    char mes[3] ;
    char dia[3];
}Datos;

typedef struct _registro
{
    int status;
    int matri;
    Nombre persona;
    Datos nacimiento;
    char estado[3];
    char estado_compl[30];
    char sexo[10];
    int edad;
    char curp[18];
}Registro;

//DEFINIENDO FUNCIONES//
Registro gen_rega_alea();
Registro eliminar_regis(Registro vect[], int *n);

void imprimir_registros(Registro vect[], int n);
void ordenar_regis(Registro vect[], int n);
void generarFechaAlea(char anio[],char mes[],char dia[]);
void buscar_regis(Registro vect[], int n);

void menuBusc(Registro vect[],int i,bool orden);
void letrero();
void menu();


int archivoTxt(Registro vect[],int i,int band);
int genMatri(Registro vect[],int i);
int buscarAlumSec(Registro vect[],int i,int matricula);
int randomDia(int mes, int bisiesto);
int buscarAlumBin(Registro vect[],int i,int matricula);
int esBisiesto(int year);
int calcularEdad(char anio1[],char mes1[],char dia1[]);


int main()
{
    menu();

}

//CUERPO DE LAS FUNCIONES

void letrero()
{
    printf("                     MENU              \n");
    printf("1 - CARGAR (AUTOM 100 REGISTROS)\n");
    printf("2 - ELIMINAR\n");
    printf("3 - BUSCAR \n");
    printf("4 - ORDENAR\n5 - IMPRIMIR\n6 - ARCHIVO DE TEXTO\n0 - SALIR\n ");
}
void menu()
{
    int txtband=1;
    int x = 0;
    int op;
    int i=0;
    int j = 100;
    bool orden=false;
    bool ordenado = true;
    Registro vect[N];
    do
    {
        letrero();
        op = vali_rango("Ingresa la accion a realizar: ",0,6);
        switch (op)
        {
        case 0:
            op = 0;
            break;
        case 1:
            if (j <= 1900) 
            {
                for (i; i < j ; i++) 
                {
                    int num = genMatri(vect,i);
                    vect[i] = gen_rega_alea();
                    vect[i].matri = num;
                }
                printf("Se han agregado 100 datos exitosamente!");
            } 
            else 
            {
                printf("El registro se ha llenado completamente, intente realizar otra opcion, buen dia!\n");
            }
            j = j + 100;
            i = j - 101;
            break;
        case 2:
            int op;
            op= vali_rango("Deseas eliminar el registro?",1,2);
            if(op == 1)
            {
                eliminar_regis(vect, &i);
            }
            else
            {
                printf("Te has salvado");
            }
            break;
        case 3:
            menuBusc(vect,i,orden);
            break;
        case 4:
            if(ordenado)
            {
                ordenar_regis(vect, i);
                ordenado = false;
            }
            else
            {
                printf("Ya se encuentra ordenado");
            }
            break;
        case 5:
            if(i>0)
            {
                imprimir_registros(vect, i);
            }
            else
            {
                printf("\nAun no hay personas registrados\n");
            }            
            break;
        case 6:
                if(i>0)
                {
                    txtband=archivoTxt(vect,i,txtband);
                    printf("Se genero un archivo de texto de los registros\n");
                }
                else
                {
                    printf("\nAun no hay personas registrados\n");
                }
                break;
        default:
            break;
        }
    } while (op != 0);
}

void imprimir_registros(Registro vect[], int n)
{
    char enter[2];
    for (int i = 0; i < n; i++)
    {
        printf("-------------------------------------------------------------------------------------\n");
        printf("|                                                                                    \n");
        printf("| MATRIUCLA: %d                                                                      \n",vect[i].matri);
        printf("| NOMBRE: %s                                                                         \n",vect[i].persona.nombre1);
        printf("| SEGUNDO NOMBRE: %s                                                                 \n",vect[i].persona.nombre2);
        printf("| APELLI PATERNO: %s                                                                 \n",vect[i].persona.appater);
        printf("| APELLI MATERNO: %s                                                                 \n",vect[i].persona.apmater);
        printf("| FECHA DE NACIM: %s-%s-%s                                                           \n",vect[i].nacimiento.dia,vect[i].nacimiento.mes,vect[i].nacimiento.anio);
        printf("| EDAD: %d                                                                           \n",vect[i].edad);
        printf("| SEXO: %s                                                                           \n",vect[i].sexo);
        printf("| LUGAR DE NACIM: %s                                                                 \n",vect[i].estado_compl);
        printf("| CURP GENERADA : %s                                                                 \n",vect[i].curp);
        printf("|                                                                                    \n");
        printf(" ------------------------------------------------------------------------------------\n");
        printf("\n");
        if ((i + 1) % 40 == 0) 
        {
            printf("-------------------------------------------------------------------------------------\n");
            printf("------------------------- Fin del grupo de 40 elementos ------------------------------\n");
            printf("Presione cualquier tecla para continuar.......");
            fflush(stdin);
            gets(enter);
        }
    }
}
Registro gen_rega_alea()
{
    Registro regis;
    char *nHombre[10] = {"Erick", "Juan", "Pedro", "Luis", "Carlos", "Miguel", "Alejandro", "José", "Javier", "Antonio"};
    char *nMujer[10] = {"Maria", "Ana", "Laura", "Sofia", "Paula", "Isabel", "Carmen", "Patricia", "Raquel", "Marta"};
    char *apPater[10] = {"Gonzalez", "Lopez", "Rodriguez", "Martinez", "Perez", "Fernandez", "Gomez", "Sanchez", "Ramirez", "Torres"};
    char *apMater[10] = {"Flores", "Morales", "Vazquez", "Jimenez", "Reyes", "Diaz", "Torres", "Gutierrez", "Ruiz", "Mendoza"};
    char a[5] = "\0";
    char m[3] = "\0";
    char d[3] = "\0";

    regis.status = 1;
    int sexo = rand() % 200;
    int dos_nom = rand() % 200;
    if (sexo%2 == 1)
    {
        if (dos_nom%2 == 1)
        {
            strcpy(regis.persona.nombre1, nHombre[rand() % 10]);
            strcpy(regis.sexo, "HOBRE" );
        }
        else
        {
            strcpy(regis.persona.nombre1, nHombre[rand() % 10]);
            strcpy(regis.persona.nombre2, nHombre[rand() % 10]);
            strcpy(regis.sexo, "HOMBRE" );
        }
    }
    else
    {
        if (dos_nom%2 == 0)
        {
            strcpy(regis.persona.nombre1, nMujer[rand() % 10]);
            strcpy(regis.sexo, "MUJER" );
        }
        else
        {
            strcpy(regis.persona.nombre1, nMujer[rand() % 10]);
            strcpy(regis.persona.nombre2, nMujer[rand() % 10]);
            strcpy(regis.sexo, "MUJER" );
        }
    }
    generarFechaAlea(a,m,d);

    strcpy(regis.persona.appater, apPater[rand() % 10]);
    strcpy(regis.persona.apmater, apMater[rand() % 10]);
    strcpy(regis.nacimiento.anio, a );
    strcpy(regis.nacimiento.mes, m);
    strcpy(regis.nacimiento.dia, d );
    regis.edad = calcularEdad(a,m,d);
    genEst(regis.estado,regis.estado_compl);
    generar_curp(regis.curp,regis.persona.nombre1,regis.persona.nombre2,regis.persona.appater,regis.persona.apmater,regis.nacimiento.dia,regis.nacimiento.mes,regis.nacimiento.anio,regis.sexo,regis.estado);
    return regis;
}

/////
Registro eliminar_regis(Registro vect[], int *n)
{
    int matri = vali_rango("Ingresa la matricula del registro que deseas borrar: ",300000, 399999);
    int k = 0;
    Registro veck[N];

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

int genMatri(Registro vect[],int i)
{
    int num;
    do
    {
        num=(rand()%100000)+300000;
    }while(buscarAlumSec(vect,i,num)!=-1);
    return num;
}

void ordenar_regis(Registro vect[], int n)
{
    int i, j;
    Registro temp;
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



int buscarAlumBin(Registro vect[],int i,int matricula)
{
    int izq,drcha;
    int med;
    izq=0;
    drcha=i-1;
    while(izq<=drcha) 
    {
        med=izq+(drcha-izq)/2;
        if(vect[med].matri==matricula)
        {
            return med;
        }
        
        if(vect[med].matri<matricula)
        {
            izq=med+1;
        } 
        else
        {
            drcha=med-1;
        }
    }
    return -1;
}

int buscarAlumSec(Registro vect[],int i,int matricula)
{
    int j;
    for(j=0;j<i;j++)    
    {
        if(matricula ==vect[j].matri)  
        {
            return j; 
        }
    }
    return -1;  
}

void menuBusc(Registro vect[],int i,bool orden)   
{    
    int pos;
    if(orden)
    {
        pos=buscarAlumBin(vect,i,vali_rango("Ingresa la matricula del alumno que desea buscar: ",300000,399999));
        if(pos!=-1)
        {
            printf("-------------------------------------------------------------------------------------\n");
            printf("|                                                                                    \n");
            printf("| MATRIUCLA: %d                                                                      \n",vect[i].matri);
            printf("| NOMBRE: %s                                                                         \n",vect[i].persona.nombre1);
            printf("| SEGUNDO NOMBRE: %s                                                                 \n",vect[i].persona.nombre2);
            printf("| APELLI PATERNO: %s                                                                 \n",vect[i].persona.appater);
            printf("| APELLI MATERNO: %s                                                                 \n",vect[i].persona.apmater);
            printf("| FECHA DE NACIM: %s-%s-%s                                                           \n",vect[i].nacimiento.dia,vect[i].nacimiento.mes,vect[i].nacimiento.anio);
            printf("| EDAD: %d                                                                           \n",vect[i].edad);
            printf("| SEXO: %s                                                                           \n",vect[i].sexo);
            printf("| LUGAR DE NACIM: %s                                                                 \n",vect[i].estado_compl);
            printf("| CURP GENERADA : %s                                                                 \n",vect[i].curp);
            printf("|                                                                                    \n");
            printf(" ------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\nNo se encontro al alumno\n");
        }
    }
    else
    {
        pos=buscarAlumSec(vect,i,vali_rango("Ingresa la matricula del alumno que desea buscar: ",300000,399999));
        if(pos!=-1)
        {
            printf("-------------------------------------------------------------------------------------\n");
            printf("|                                                                                    \n");
            printf("| MATRIUCLA: %d                                                                      \n",vect[i].matri);
            printf("| NOMBRE: %s                                                                         \n",vect[i].persona.nombre1);
            printf("| SEGUNDO NOMBRE: %s                                                                 \n",vect[i].persona.nombre2);
            printf("| APELLI PATERNO: %s                                                                 \n",vect[i].persona.appater);
            printf("| APELLI MATERNO: %s                                                                 \n",vect[i].persona.apmater);
            printf("| FECHA DE NACIM: %s-%s-%s                                                           \n",vect[i].nacimiento.dia,vect[i].nacimiento.mes,vect[i].nacimiento.anio);
            printf("| EDAD: %d                                                                           \n",vect[i].edad);
            printf("| SEXO: %s                                                                           \n",vect[i].sexo);
            printf("| LUGAR DE NACIM: %s                                                                 \n",vect[i].estado_compl);
            printf("| CURP GENERADA : %s                                                                 \n",vect[i].curp);
            printf("|                                                                                    \n");
            printf(" ------------------------------------------------------------------------------------\n");
        }
        else
        {
            printf("\nNo se encontro al alumno\n");
        }
    }       
}

int archivoTxt(Registro vect[],int i,int band)
{
    int j;
    FILE *pa;
    if(band)
    {
        pa=fopen("registros.txt","a");
        char str[140]={"| No   | Est | Matri  | Apellido Paterno | Apellido Materno | Nombre                           | Ed  | Sex |        CURP        |\n"};
        fprintf(pa,"%s",str);

        for(j=0;j<i;j++)
        {
            if(vect[j].status)
            {
                fprintf(pa,"| %4d ",j);
                fprintf(pa,"| %s  | %d | %-16s | %-17s| %-19s | %-19s | %3d |  %c  |",vect[j].estado,vect[j].matri,vect[j].persona.appater,vect[j].persona.apmater,vect[j].persona.nombre1, vect[j].persona.nombre2,vect[j].edad,vect[j].sexo);
                fprintf(pa," %s |\n",vect[j].curp);
            } 
        }
    }
    else
    {
        pa=fopen("registros.txt","w");
        char str[140]={"| No   | Est | Matri  | Apellido Paterno | Apellido Materno | Nombre                          | Ed  | Sex |        CURP        |\n"};
        fprintf(pa,"%s",str);

        for(j=0;j<i;j++)
        {
            if(vect[j].status)
            {
                fprintf(pa,"| %4d ",j);
                fprintf(pa,"| %s  | %d | %-16s | %-17s| %-19s | %-19s | %3d |  %s  |",vect[j].estado,vect[j].matri,vect[j].persona.appater,vect[j].persona.apmater,vect[j].persona.nombre1, vect[j].persona.nombre2,vect[j].edad,vect[j].sexo);
                fprintf(pa," %s |\n",vect[j].curp);
            } 
        }
    }
        
    fclose(pa);

    return 0;
}
