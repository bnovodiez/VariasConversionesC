/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: alberto
 *
 * Created on 22 de julio de 2016, 1 */


#include <stdio.h>
#include <stdlib.h>

int main()
{

int num;
int a,b,c,d,e,f,g;
char stringNum[9];

printf("Ingrese el sueldo: \n");
scanf("%s",&stringNum);

num=atoi(stringNum);

a=(num/100);
printf("billetes 100 vale: %d\n", a);

num=(num-(a*100));
b=(num/50);
printf("billetes 50 vale: %d\n", b);

num=(num-(b*50));
c=(num/20);
printf("billetes 20 vale:%d\n", c);
num=(num-(c*20));
d=(num/10);
printf("d vale:%d\n", d);        
num=(num-(d*10));
e=(num/5);
printf("e vale:%d\n", e);        
num=(num-(e*5));
f=(num/2);
printf("f vale:%d\n", f);        
num=(num-(f*2));
g=(num/1);
printf("g vale:%d\n", g);

return 0;

}
        
        
        
        
        





      
    
 
    
    






  
    
    





 

 
 
        


        
        
        
             






 

 









        


   


