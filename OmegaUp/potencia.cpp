#include <cstdio>

long potencia(int a, int b)
{
   if (b == 0) {
      return 1;
   } else if (b == 1) {
      return a;
   } else {
      long temp = potencia(a, b / 2);
      long res = temp * temp;
      if (b % 2 == 1) {
         res *= a;
      }
      return res;
   }
}
long potencia_simplificado(int a,int b)
{
   if (b <= 1) {
      return (b == 0 ? 1 : a);
   }
   long temp = potencia(a, b / 2);
   long res = temp * temp;
   return res * (b % 2 == 0 ? 1 : a);
}


int main()
{
	int k, n, r;
	scanf("%d%d%d",&k,&n,&r);
	printf("%ld\n",(potencia_simplificado(k,n)*r));
	return 0;
}