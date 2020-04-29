#include <cstdio>
#include <bitset>
#include <cstring>
using namespace std;

#define p 255
#define mod 10000007

bitset< mod > s;
unsigned int fexp(unsigned int a, unsigned int b) {
	if (b <= 1) {
		return b == 1 ? a: 1;
	}
	unsigned int tmp = fexp(a, b/2);
	tmp *= tmp;
	return tmp * (b & 1 ? a : 1);
}

unsigned int polyRolling (char *key)
{
	unsigned int ans = key[0];
	for(int i=1; i<= strlen(key); ++i ) {
		ans += key[i] * fexp(p,i);
	}
	return ans % mod;
}

int main( )
{
   int n;
   scanf("%d",&n);
   char palabra[16];
   for(int i=0; i<n; ++i) {
      scanf("%s",palabra);
      s[ polyRolling(palabra) ] = 1;
   }
   int m;
   scanf("%d",&m);
   for(int i=0; i<m; ++i) {
      scanf("%s",palabra);
      if ( s[ polyRolling(palabra) ] )
      {
         printf("1\n");
      } else {
         printf("0\n");
      }
   }
   return 0;
}