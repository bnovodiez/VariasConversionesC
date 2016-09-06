#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Validar el sueldo introducido y elegir 
 * el tipo de billete máximo a utilizar (500,200,100 ó 50).
 */

int main() {

    int cEntera, cDecimal;
    int billete;
    int billeteV;
    char stringNum[5];
    float num;
    int b1, b2, b5, b10, b20, b50, b100, b200, b500;
    
    do{
        printf("Ingrese una cantidad\n");
        scanf("%s",&stringNum);
        printf("\n");
        num=atof(stringNum);
        printf("Billete a empezar \n");
        scanf("%d", &billete);
        printf("\n");
        
            if (billete == 500) {
                billeteV = 1;
            } else if (billete == 200) {
                billeteV = 1;
            } else if (billete == 100) {
                billeteV = 1;
            } else if (billete == 50) {
                billeteV = 1;
            } else {
                printf("Billete no válido.\n");
                billeteV = 0;
            }
    } while (num<1 || billeteV != 1 || validarEntrada(stringNum)!=0);
    
    if(num!=0){
            /*printf("El cEntera es: %f\n",num);*/
            printf("el número introducido es %5.2f y el billete es %i\n\n", num, billete);
            cEntera= (int)num;
            /*printf("entera %i\n", cEntera);*/
            cDecimal=(num-cEntera)*100;
            /*printf("decimal %i\n", cDecimal);*/
        }
    
    if (billete==500) {
    
   	b500=cEntera/500;
        b200=cEntera%500/200;
        b100=cEntera%500%200/100;
	b50=cEntera%500%200%100/50;
	b20=cEntera%500%200%100%50/20;
	b10=cEntera%500%200%100%50%20/10;
	b5=cEntera%500%200%100%50%20%10/5;
        b2=cEntera%500%200%100%50%20%10%5/2;
	b1=cEntera%500%200%100%50%20%10%5%2;
    }
    else if (billete==200) {
        
        b500=0;
        b200=cEntera/200;
        b100=cEntera%200/100;
        b50=cEntera%200%100/50;
        b20=cEntera%200%100%50/20;
        b10=cEntera%200%100%50%20/10;
        b5=cEntera%200%100%50%20%10/5;
        b2=cEntera%200%100%50%20%10%5/2;
        b1=cEntera%200%100%50%20%10%5%2;
    }
    else if (billete==100){
        
        b500=0;
        b200=0;
        b100=cEntera/100;
	b50=cEntera%100/50;
	b20=cEntera%100%50/20;
	b10=cEntera%100%50%20/10;
	b5=cEntera%100%50%20%10/5;
        b2=cEntera%100%50%20%10%5/2;
	b1=cEntera%100%50%20%10%5%2;
    }
    else if (billete==50){
            
        b500=0;
        b200=0;
        b100=0;
        b50=cEntera/50;
	b20=cEntera%50/20;
	b10=cEntera%50%20/10;
	b5=cEntera%50%20%10/5;
        b2=cEntera%50%20%10%5/2;
        b1=cEntera%50%20%10%5%2;
    }
	printf("La combinacion de billetes es: \n");

        printf("de 500: %d\n", b500);
        printf("de 200: %d\n", b200);
        printf("de 100: %d\n", b100);
        printf("de 50: %d\n", b50);
        printf("de 20: %d\n", b20);
        printf("de 10: %d\n", b10);
        printf("de 5: %d\n", b5);
        printf("de 2: %d\n", b2);
        printf("de 1 %d\n", b1);
   
        return num, billete, cEntera, cDecimal;
}


int validarEntrada(char nom[]) 
{ 
    int i = 0; 
    int valido = 0;
    int numCarac = strlen(nom); 

    for( i = 0; i < numCarac; i++) 
    { 
        if (!isdigit(nom[i]) && (nom[i])!=46) {
            valido = 1;
            break;
        }
    }
    return valido; 
}
