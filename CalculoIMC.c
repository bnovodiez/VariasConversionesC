/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int CalculoIMC()
{
char peso[4], altura[4], sexo[2];
double numaltura, numpeso, imc, altura_metro;

do
{
    printf("\n Escribe tu altura en cm: ");
    scanf("%s", &altura);
    printf("\n Escribe tu peso en Kg: ");
    scanf("%s", &peso);
    printf("\n Sexo, Hombre (H) o Mujer (M): ");
    scanf("%s",&sexo);

}while ( (numaltura=atoi(altura))<=0 || (numpeso=atoi(peso))<=0 || validasEntrada(altura)!=0 || validasEntrada(peso)!=0 || validaSexo(sexo)==0);

/*Convertimos el dato de altura introducido en cm a metros, 
 * para poder utilizar el dato en la formula del IMC y Calculamos el valor de IMC */
    
    altura_metro=(numaltura/100);
    imc = (numpeso/(altura_metro * altura_metro));
 /*En relación a si es Hombre o Mujer brindamos la salida con el resultado del IMC*/   
    
    if ((sexo[0]=='H') || (sexo[0]=='h')) {
        /* Sexo Hombre.*/printf("\n Sexo Hombre");
            if (imc < 18.5) {    
                printf("\n Delgadez, Su IMC es: %.2f",imc);
            }else if (imc > 18.5 & imc < 25) {
                printf("\n Peso Normal, Su IMC es: %.2f",imc);
            }else if (imc > 25 & imc < 30) {
                printf("\n SobrePeso, Su IMC es: %.2f",imc);
            }else if (imc > 30 & imc < 40) {
                printf("\n Obesidad, Su IMC es: %.2f",imc);
            }else if (imc > 40) {
                printf("\n Fuerte Obesidad, Su IMC es: %.2f",imc);
            }else
    printf("Valor no valido");
    }
    if ((sexo[0]=='M') || (sexo[0] == 'm')) {
        /* Sexo Mujer.*/ printf("\n Sexo Mujer");
        if (imc < 17.5) {
                printf("\n Delgadez, Su IMC es: %.2f",imc);
        }else if (imc > 17.5 & imc < 24) {
                printf("\n Peso Normal, Su IMC es: %.2f",imc);
        }else if (imc > 24 & imc < 30) {
                printf("\n SobrePeso, Su IMC es: %.2f",imc);
        }else if (imc > 30 & imc < 40) {
                printf("\n Obesidad, Su IMC es: %.2f",imc);
        }else if (imc > 40) {
                printf("\n Fuerte Obesidad, Su IMC es: %.2f",imc);
        }else
    printf("\n Valor no valido");
    }

return (0);
}
        
/* Función para validar la entrada sea un numero incluido decimal con un punto,
 *  no es valido para coma y no tiene en cuanta si se introducen dos veces un punto, por ej 5.6.7 daría valido.
 La función recibe la variable nom y devuelve la variable valido en uno si es un numero decimal de lo contrario devuelve valido en cero.*/
int validasEntrada(char nom[]) 
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
/*Función para validar la entrada del sexo, Hombre corresponde a la H/h y Mujer M/m, 
 * si es correcto vsex = 1*/
int validaSexo(char sex[]) 
{ 
int i = 0; 
int vsex = 0;// incializo la variable...es necesario.
int numCarac = strlen(sex); 

for( i = 0; i < numCarac; i++) 
{
    if (numCarac != 1) {
        vsex=0;
        break;
    }
    if((sex[i]=='H') || (sex[i]=='h')|| (sex[i]=='M') || (sex[i]=='m')) 
    {  
        vsex = 1;
        break;
    } 
} 
return vsex; 
} 