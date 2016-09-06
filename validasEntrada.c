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