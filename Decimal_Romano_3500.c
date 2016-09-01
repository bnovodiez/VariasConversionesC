#include <stdio.h>
#include <stdlib.h>
#include<ctype.h> 
#include<string.h>


int Decimal_Romano_3500()
{
int numeroentero,r,digito;
char num[5];
do{
    
printf("\n Escriba el numero entero a convertir a Romano ");
scanf("%s",&num);

}while((numeroentero=atoi(num))<=0 || (numeroentero=atoi(num))>3500 || validaEntrada(num)!=0);

printf("\n El numero %d en ROMANOS es ",numeroentero);
r=numeroentero;
digito=r/1000;
r=r%1000;
cambiarRom(digito,'M',' ',' ');
digito=r/100;
r=r%100;
cambiarRom(digito,'C','D','M');
digito=r/10;
r=r%10;
cambiarRom(digito,'X','L','C');
digito=r;
cambiarRom(digito,'I','V','X');

printf("\n\n");
       
return (0);
}

void cambiarRom(int digito, char v1,char v2,char v3)
{
int j;

if(digito==9){
printf("%c%c",v1,v3);
}
else{
if(digito>4){
printf("%c",v2);
for(j=1;j<=digito-5;j++){
printf("%c",v1);
}
}
else{
if(digito==4){
printf("%c%c",v1,v2);
}
else{
for(j=1;j<=digito;j++){
printf("%c",v1);
}
}
}
}
}

int validaEntrada(char nom[]) 
{ 
int i = 0; 
int valido = 0;// incializo la variable...es necesario. 
int numCarac = strlen(nom); 

for( i = 0; i < numCarac; i++) 
{ 
if(isdigit(nom[i])) 
{ 
continue; 
valido = 0; 
} 
else 
{ 
valido = 1;
} 
break;
} 

return valido; 
} 
