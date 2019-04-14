#include <cstdio>

int main( )
{
   int hora, minuto, segundo;

   scanf("%d:%d:%d",&hora,&minuto,&segundo);

   segundo++;
   
   if (segundo > 59){  
      minuto++;
      segundo = 0;
   }
   if ( minuto > 59){
      hora++;
      minuto = 0;
   }

   if ( hora > 23 ){
      hora = 0;
   }
   if (hora < 10)
      printf("0%d",hora);
   else
      printf("%d",hora);
   if (minuto < 10)
      printf(":0%d",minuto);
   else
      printf(":%d",minuto);
   if (segundo < 10)
      printf(":0%d\n",segundo);
   else
      printf(":%d\n",segundo);
}