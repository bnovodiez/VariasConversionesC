
   
#include <stdio.h>
int main() 
{

int centimos;

printf("Introduce el numero de centimos:\n");
scanf("%d",&centimos);

    printf("Monedas de 50 céntimos: %d\n", centimos/50);
    centimos %= 50;
    printf("Monedas de 20 céntimos: %d\n", centimos/20);
    centimos %= 20;
    printf("Monedas de 10 céntimos: %d\n", centimos/10);
    centimos %= 10;
    printf("Monedas de 5 céntimos: %d\n", centimos/5);
    centimos %= 5;
    printf("Monedas de 2 céntimos: %d\n", centimos/2);
    centimos %= 2;
    printf("Monedas de 1 céntimo: %d\n", centimos);
    
    return 0;
} 