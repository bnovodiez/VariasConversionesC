/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SalarioXBilletes.c
 * Author: Programación
 *
 * Created on 22 de julio de 2016, 11:17
 */

#include <stdio.h>
#include <stdlib.h>
#include<ctype.h> 
#include<string.h>
#include <math.h>

double f_round();
/*
 * 
 */
int main() 
{
int num,n,pb,bv,J,C,vop;
int nubilletes, numonedas, numcentimos, Salariocentimos, valorcentimos;
double Salarioentero;
int billete;
char stringNum [4], salario[8], opcion [2];
/* Variables Billetes, Monedas de euros y centimos. */
const int billetes[]={500,200,100,50,20,10,5};
const int monedas[]={2,1};
const int centimos[]={50,20,10,5,2,1};
/* Variables totales de billetes, monedas y salarios sumados */
int cb500 = 0, cb200= 0, cb100 = 0, cb50 = 0, cb20 = 0, cb10 = 0, cb5 = 0;
int cm2 = 0, cm1 = 0;
int cc50 = 0, cc20 = 0, cc10 = 0, cc5 = 0, cc2 = 0, cc1 = 0;
double ts = 0;

do
    {
        printf( "\n   1. Introducir Salario.");
        printf( "\n   2. Calcular Total a Solicitar al Banco (Para Varios salarios anteriormente introducidos.");
        printf( "\n   3. Salir.");
                
        do
        { 
            printf( "\n   Introduzca opción (1-3): ");
            fflush(stdin); /* Se tiene que tener especial cuidado si utilizamos scanf para leer caracteres.Para resolver este problema, antes de leer un carácter con scanf, hay que vaciar (limpiar) el buffer del teclado. Para ello, se utiliza la función fflush.Puedes ampliar informacion en http://www.carlospes.com/curso_de_lenguaje_c/01_11_la_funcion_fflush.php */
            scanf("%s",&opcion );
            vop = atoi(opcion);
        } while ( vop < 1 || vop > 3 );
        
        switch (vop)
        {
            /*case'1':*/
            case 1:

/* Solicitamos y validamos el valor a descomponer en billetes y monedas. */
do{
    printf("\n Entre el salario entero a convertir en billetes y monedas. ");
    fflush(stdin);
    scanf("%s",&salario);
    Salarioentero = strtof (salario, NULL);
} while(Salarioentero<0 || Salarioentero>9999 || validarEntrada(salario)!=0);

/* Solicitamos y validamos el valor de billete más alto a utilizar para descomponer. */
    do{
        
        printf("\n Entre el billete más alto a utilizar, 500, 200, 100, 50, 20, 10, 5. ");
        fflush(stdin);
        scanf("%s",&stringNum);
        billete=atoi(stringNum); /* atoi convierte el numero ingresado como cadena en entero
        en caso de ser posible, de lo contrario retorna 0*/
        if (billete!=0)
        {
            for (num=0; num<7; num++) /* recorremos el array de billetes para validar billete */
            {
                if (billete == billetes[num])
                {
                    bv = 1;
                    pb = num;/* Posición dentro del array */
                    break;
                }
                else {
                    bv = 0;
                    }
            }
        }    
            else {
                printf("\n Billete más alto %d incorrecto",billete);
                bv = 0;
                }
    } while (bv==0);    

/* Convertimos el valor entrado a descomponer en un valor con precision de dos decimales,
 * para ello utilizamos la funcion f_round que se encuentra en otra archivo con su mismo nombre. */    
Salarioentero= f_round(Salarioentero,2);
ts = f_round(ts,2) + Salarioentero; /* Total de cantidad a solicitar al banco para varios salarios. */
/* Calculo de los centimos para descomponer. */
valorcentimos= (Salarioentero - (int)Salarioentero)*100.00;
printf("\n Los centimos son %2.0d : \n", valorcentimos);
Salariocentimos=valorcentimos;
printf ("\n El desglose optimo para el salario %.2f es: \n", Salarioentero);

/* En la variable pb tenemos la posicion dentro del array del billete más alto a utilizar,
 recorremos el array de billetes y calculamos la cantidad de cada billete se necesitan.*/
for (pb ;pb<7; pb++)
{
    nubilletes=Salarioentero/billetes[pb];
    if (nubilletes != 0){
        printf ("\n Se necesitan %d Billetes de %d Euros.\n", nubilletes, billetes[pb]); 
    }
    if (billetes[pb] == 500) {
                cb500 = cb500 + nubilletes;
            } else if (billetes[pb] == 200) {
                cb200 = cb200 + nubilletes;
            } else if (billetes[pb] == 100) {
                cb100 = cb100 + nubilletes;
            } else if (billetes[pb] == 50) {
                cb50 = cb50 + nubilletes;
            } else if (billetes[pb] == 20) {
                cb20 = cb20 + nubilletes;
            } else if (billetes[pb] == 10) {
                cb10 = cb10 + nubilletes;
            } else if (billetes[pb]== 5) {
                cb5 = cb5 + nubilletes;
            }
            
    Salarioentero= (int)Salarioentero%billetes[pb];
    /*printf ("\n %5.2f.\n", Salarioentero);*/
}
/* Se recorre el array de monedas de euros y se calcula la cantidad que se necesita al descomponer.*/
for (J=0; J<2; J++)
{
    numonedas=Salarioentero/monedas[J];
    if (numonedas !=0){
        printf ("\n Se necesitan %d monedas de %d Euros. \n", numonedas, monedas[J]);
    }
    if (monedas[J] == 2) {
                cm2 = cm2 + numonedas;
            } else if (monedas[J] == 1) {
                cm1 = cm1 + numonedas;
            }
    Salarioentero= (int)Salarioentero%monedas[J];
}
/* Se recorre el array de monedas de centimos y se calcula la cantidad que se necesita al descomponer.*/
for (C=0; C<6; C++)
{
    /*printf("\n Los centimos inicial %d \n",Salariocentimos);*/
    numcentimos=Salariocentimos/centimos[C];
    if (numcentimos !=0) {
        printf ("\n Se necesitan %d monedas de %d Centimos. \n", numcentimos, centimos[C]);
    }
    if (centimos[C] == 50) {
                cc50 = cc50 + numcentimos;
            } else if (centimos[C] == 20) {
                cc20 = cc20 + numcentimos;
            } else if (centimos[C] == 10) {
                cc10 = cc10 + numcentimos;
            } else if (centimos[C] == 5) {
                cc5 = cc5 + numcentimos;
            } else if (centimos[C] == 2) {
                cc2 = cc2 + numcentimos;
            } else if (centimos[C] == 1) {
                cc1 = cc1 + numcentimos;
            }
    Salariocentimos= Salariocentimos%centimos[C];
    /*printf("\n Los centimos %d \n",Salariocentimos);*/
}  
        
        
        break; /* Break del CASE1 */
        case 2:
            printf("\n La cantidad total a solicitar al banco es de %.2f", ts);
            printf("\n El desglose a solicitar al banco es el siguiente: \n");
            printf ("\n Se necesitan %d billetes de 500 Euros", cb500);
            printf ("\n Se necesitan %d billetes de 200 Euros", cb200);
            printf ("\n Se necesitan %d billetes de 100 Euros", cb100);
            printf ("\n Se necesitan %d billetes de 50 Euros", cb50);
            printf ("\n Se necesitan %d billetes de 20 Euros", cb20);
            printf ("\n Se necesitan %d billetes de 10 Euros", cb10);
            printf ("\n Se necesitan %d billetes de 5 Euros", cb5);
            printf ("\n Se necesitan %d Monedas de 2 Euros", cm2);
            printf ("\n Se necesitan %d Monedas de 1 Euros", cm1);
            printf ("\n Se necesitan %d Monedas de 50 Centimos", cc50);
            printf ("\n Se necesitan %d Monedas de 20 Centimos", cc20);
            printf ("\n Se necesitan %d Monedas de 10 Centimos", cc10);
            printf ("\n Se necesitan %d Monedas de 5 Centimos", cc5);
            printf ("\n Se necesitan %d Monedas de 2 Centimos", cc2);
            printf ("\n Se necesitan %d Monedas de 1 Centimos", cc1);
            ts = 0.00; /* Se vacia para proximo uso del algoritmo de menú. */
            cb500 = 0, cb200= 0, cb100 = 0, cb50 = 0, cb20 = 0, cb10 = 0, cb5 = 0;
            cm2 = 0, cm1 = 0;
            cc50 = 0, cc20 = 0, cc10 = 0, cc5 = 0, cc2 = 0, cc1 = 0;
            
            break;
        }   
}    while (vop != 3) ;
return (0);
}


/* Función para validar la entrada sea un numero incluido decimal con un punto,
 *  no es valido para coma y no tiene en cuanta si se introducen dos veces un punto, por ej 5.6.7 daría valido.
 La función recibe la variable nom y devuelve la variable valido en uno si es un numero decimal de lo contrario devuelve valido en cero.*/
int validarEntrada(char nom[]) 
{ 
int i = 0; 
int valido = 0;// incializo la variable...es necesario.
int numCarac = strlen(nom); 

for( i = 0; i < numCarac; i++) 
{ 
    if((!isdigit(nom[i]))&& (nom[i]!=46)) 
    {  
        valido = 1;
        break;
    } 
} 

return valido; 
} 