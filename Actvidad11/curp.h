//                             Ensenada, Baja California a 03 de Noviembre del 2023    //
// Nombre:              Miguel Angel Ramirez Monjaraz                                  //
// Matricula:           372205                                                         //
// Programa:            Libreria que genera curp                                       //
// Nombre del programa: MARM_ACT11_01


#include "Gauss.h"
char lugar(char estado[]);


char composicion[81][5] = {"BAKA", "BACA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE",
                    "COGI", "COJA", "COJE", "COJI", "COJO", "COLA", "CULO", "FALO", "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA",
                    "KACO", "KAGA", "KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", "LOCO", "LOKA", "LOKO",
                    "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA", "NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO",
                    "POPO", "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO", "RUIN", "SENO", "TETA", "VACA", "VAGO", "VAGA", "VAKA", "VUEI", "WUEI", "WUEY"};
char nombres_prohibidos[10][8] = {"MARIA", "MA.", "MA", "M.", "M", "JOSE", "J.", "J"};
char letras_feas[6][4] = {"Ü","/","'","-","."};


void generar_curp(char CURP[],char nombr1[],char nombr2[],char apelli1[], char apelli2[], char dia[], char mes[], char anio[], char sex[], char estado[])
{
    
    int i,j,k,op1, op2, op3, sin_nombre = 0, usar_nom2 = 0,num,num2;
    char numc[3],num2c[3];

    char nombr1_vocal[20];
    char nombr2_vocal[20];
    char apelli1_vocal[30];
    char apelli2_vocal[30];

    char nombr1_conso[20];
    char nombr2_conso[20];
    char apelli1_conso[30];
    char apelli2_conso[30];

    eliminarEspacioInicial(nombr1);
    eliminarEspacioInicial(nombr2);
    eliminarEspacioInicial(apelli1);
    eliminarEspacioInicial(apelli2);

    a_mayusculas(nombr1);
    a_mayusculas(nombr2);
    a_mayusculas(apelli1);
    a_mayusculas(apelli2);
    quitar_ene(nombr1);
    quitar_ene(nombr2);
    quitar_ene(apelli1);
    quitar_ene(apelli2);

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(nombr1, nombres_prohibidos[i]) == 0)
        {
            usar_nom2 = 1;
            break;
        }
    }
    // aqui comprobamos si trae mas de una palabra sus nombre y apellidos
    separar_nombre(nombr1);
    separar_nombre(nombr2);
    separar_nombre(apelli1);
    separar_nombre(apelli2);

    //separamos es vocales y consonantes para chambear mejorcito
    vocales_conso(nombr1,nombr1_vocal,nombr1_conso);
    vocales_conso(nombr2,nombr2_vocal,nombr2_conso);
    vocales_conso(apelli1,apelli1_vocal,apelli1_conso);
    vocales_conso(apelli2,apelli2_vocal,apelli2_conso);
    if (tam_carac(nombr2) > 0)
    {
        op1 = 1;
    }
    if (tam_carac(apelli1) > 0)
    {
        op2 = 1;
    }
    if (tam_carac(apelli2)> 0)
    {
        op3 = 1;
    }



    if (op2 == 1)
    {
        // tiene primer apellido
        CURP[0] = apelli1[0];
        if(apelli1[0] == 'A'||apelli1[0] == 'E'|| apelli1[0] == 'I'|| apelli1[0] == 'O'||  apelli1[0] == 'U')
        {
            CURP[1] = apelli1_vocal[1];
        }
        else
        {
            CURP[1] = apelli1_vocal[0];
        }
    }
    else
    {
        // sin primer apellido 
        CURP[0] = 'X';
        CURP[1] = 'X';
        sin_nombre = 1;
    }
    if (op3 == 1)
    {
        CURP[2] = apelli2[0];
    }
    else
    {
        CURP[2] = 'X';
    }

    for (int i = 0; i < 10; i++)
    {
        if (strcmp(nombr1, nombres_prohibidos[i]) == 0)
        {
            usar_nom2 = 1;
            break;
        }
    }
    if (usar_nom2 != 1)
    {
        CURP[3] = nombr1[0];
    }
    else
    {
        CURP[3] = nombr2[0];
    }
    // checamos si las primeras cuatro letras forman la palabra prohibida//
    for (int i = 0; i < 81; i++)
    {
        if (strcmp(CURP, composicion[i]) == 0)
        {
            CURP[1] = 'X';
            break;
        }
    }
    

    CURP[4] = anio[2];
    CURP[5] = anio[3];
    CURP[6] = mes[0];
    CURP[7] = mes[1];
    CURP[8] = dia[0];
    CURP[9] = dia[1];
    CURP[10] = sex[0];
    CURP[11] = estado[0];
    CURP[12] = estado[1];
    if (op2 == 1)
    {
        if(CURP[0] == apelli1_conso[0])
        {
            if(strlen(apelli1_conso) > 2)
            {
                CURP[13] = apelli1_conso[1];
            }
            else
            {
                CURP[13] = 'X';
            }
        }
        else
        {
            CURP[13] = apelli1_conso[0];
        }
    }
    else
    {
        CURP[13] = 'X';
    }


 
    if (op3 == 1)
    {
        if(strlen(apelli2_conso) > 2)
        {
            if(CURP[2] == apelli2_conso[0])
            {
                CURP[14] = apelli2_conso[1];
            }
            else
            {
                CURP[14] = apelli2_conso[0];
            }
        }
        else
        {
            CURP[14] = 'X';
        }
    }
    else
    {
        CURP[14] = 'X';
    }
    for (int i = 0; i < 10; i++)
    {
        if (strcmp(nombr1, nombres_prohibidos[i]) == 0)
        {
            usar_nom2 = 1;
            break;
        }
    }
    if (usar_nom2 != 1)
    {
        if(CURP[3] == nombr1_conso[0])
        {
            if(strlen(nombr1_conso) > 2)
            {
                CURP[15] = nombr1_conso[1];
            }
            else
            {
                CURP[15] = 'X';
            }
        }
        else
        {
            CURP[15] = nombr1_conso[0];
        }
        
    }
    
    else
    {
        if(CURP[3] == nombr2_conso[0])
        {
            if(strlen(nombr2_conso) > 2)
            {
                CURP[15] = nombr2_conso[1];
            }
            else
            {
                CURP[15] = 'X';
            }
        }
        else
        {
            CURP[15] = nombr2_conso[0];
        }
        
    }

    if (anio < "1999")
    {
        num = rand() % 9;
        sprintf(numc, "%d", num);
        CURP[16] = numc[0];
    }




    else
    {
        if (anio <= "2010")
        {
            CURP[16] = 'A';
        }
        else
        {
            if (anio <= "2020")
            {
                CURP[16] = 'B';
            }
            else
            {
                if (anio <= "2030")
                {
                    CURP[16] = 'C';
                }
            }
        }
    }


}
void genEst(char estado[],char estado_comp[])
{
    int E;
    char estList[33][3]={
    "AS","BC","BS","CC","CL","CM","CS", "CH","DF","DG",
    "GT","GR","HG","JC","MC","MN","MS","NT","NL","OC",
    "PL","QT","QR","SP","SL","SR","TC","TS","TL","VZ",
    "YN","ZS","NE"
    };
    char estlist_com[33][20]={
        "AGUASCALIENTES","BAJA CALIFORNIA","BAJA CALIFORNIA SUR", "CAMPECHE","COAHUILA","COLIMA","CHIAPAS",
        "CHIHUAHUA","DISTRITO FEDERAL","DURANGO","GUANAJUATO","GUERRERO","HIDALGO","JALISCO","MEXICO","MICHOACAN",
        "MORELOS","NAYARIT","NUEVO LEON","OAXACA","PUEBLA","QUERETARO","QUINTANA ROO","SAN LUIS POTOSI","SINALOA",
        "SONORA","TABASCO","TAMAULIPAS","TLAXCALA","VERACRUZ","YUCATAN","ZACATECAS","EXTRANJERO"
    };


    E=rand()%33;

    estado[0]=estList[E][0];
    estado[1]=estList[E][1];
    strcpy(estado_comp, estlist_com[E]);
    estado[2]='\0';
}


// Función para determinar si un año es bisiesto
int esBisiesto(int year) 
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) 
    {
        return 1; // Es bisiesto
    } else {
        return 0; // No es bisiesto
    }
}
int randomDia(int mes, int bisiesto) 
{
    int days;
    switch (mes) {
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            if (bisiesto)
                days = 29;
            else
                days = 28;
            break;
        default:
            days = 31;
            break;
    }
    return rand() % days + 1;
}
int calcularEdad(char anio1[],char mes1[],char dia1[])
{
    int anio,mes,dia;
    anio = atoi(anio1);
    mes = atoi(mes1);
    dia = atoi(dia1);

    time_t now = time(0);
    struct tm tm = *localtime(&now);

    int edad = tm.tm_year + 1900 - anio;

    if (tm.tm_mon + 1 < mes || (tm.tm_mon + 1 == mes && tm.tm_mday < dia)) 
    {
        edad--;
    }

    return edad;
}

void generarFechaAlea(char anio[],char mes[],char dia[]) 
{
    int ri=1900,rf=2023,rango=(rf-ri+1);
    int day;
    int year =  rand() % (2023 - 1930 + 1) + 1930;
    int month = rand() % 12 + 1;
    if(esBisiesto(year) == 1)
    {
        day = randomDia(month, 1);
    }
    else
    {
        day = randomDia(month, 1);
    }
    char aux;
    itoa(year,anio,10);
    itoa(month,mes,10);
    itoa(day,dia,10);
    if(strlen(mes) == 1)
    {
        aux = mes[0];
        mes[0] = '0';
        mes[1] = aux;
    }

    if(strlen(dia) == 1)
    {
        aux = dia[0];
        dia[0] = '0';
        dia[1] = aux;
    }
}
