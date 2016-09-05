/* 
 * Menú principal para seleccionar las conversiones disponibles.
 */

/* 
 * File:   main.c
 * Author: Bernardo
 *
 * Created on 26 de julio de 2016, 13:21
 */

#include <stdio.h>
#include <stdlib.h>


/*
 * 
 */
int main()
{
    char opcion [2];
    int vop;

    do
    {
        printf( "\n   1. Calcular el IMC.");
        printf( "\n   2. Convertir un número entero entre 1 y 3500 a número Romano.");
        printf( "\n   3. Introducir uno o varios salarios, establecer cuál es el billete más grande a utilizar \n y que nos diga los billetes y monedas en que se descompone.");
        printf( "\n   4. Salir." );
        
        do
        {
            
            printf( "\n   Introduzca opción (1-4): ");
            fflush( stdin ); /* Se tiene que tener especial cuidado si utilizamos scanf para leer caracteres.Para resolver este problema, antes de leer un carácter con scanf, hay que vaciar (limpiar) el buffer del teclado. Para ello, se utiliza la función fflush.Puedes ampliar informacion en http://www.carlospes.com/curso_de_lenguaje_c/01_11_la_funcion_fflush.php */
            scanf("%s", &opcion);
            vop = atoi(opcion);
        } while (vop < 1 || vop > 4);

        switch ( vop )
        {
            case 1: printf( "\n   Calcular el IMC.");
                      /* Llamar al fichero IMC. */
                      CalculoIMC();
                      printf( "\n   Hemos concluido el calculo del IMC. \n");
                      break;

            case 2: printf( "\n   Convertir un número entero entre 1 y 3500 a número Romano.");
                      /* LLamar al fichero para ejecutar la conversión. */
                      Decimal_Romano_3500();
                      printf( "\n   Hemos concluido la conversión a número Romano. \n");
                      break;

            case 3: printf( "\n   Introducir uno o varios sueldos, establecer cuál es el billete más grande a utilizar y que nos diga en cuantos billetes y monedas se descompone.\n");
                      /* Llamar al fichero principal que procesa los resultados del desgloce de billetes y monedas.*/
                      SalarioXBilletes();  
                      printf( "\n   Hemos concluido el desgloce de Billetes y monedas. \n" );
         }

    } while (vop != 4) ;

    return 0;
}