/* Función para convertir un numero double decimal en un valor con presición para utilizar en operaciones matemáticas. */
/* Donde entramos la variable dval valor decimal y n cantidad de números despues de la coma, presición decimal deseada.*/
/* Salida en la variable double dval */
#include<math.h>
double f_round(double dval, int n)

{
    
    /*printf("entrada de dval: %f", dval);*/
    double m=pow(10,n);
    dval=round((dval*m))/m;
    /*printf("salida en decimal dval: %5.4f", dval);*/
    return ((double)dval);

}