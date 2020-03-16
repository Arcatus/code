#include <cstdio>
#include <bitset>
#include <climits>

using namespace std;

unsigned int
PJWHash (char *str)
{
    unsigned int BitsInUnignedInt = (unsigned int) (sizeof (unsigned
							    int) * 8);
    unsigned int ThreeQuarters = (unsigned int) ((BitsInUnignedInt * 3) / 4);
    unsigned int OneEighth = (unsigned int) (BitsInUnignedInt / 8);
    unsigned int HighBits = (unsigned int) (0xFFFFFFFF) <<
	(BitsInUnignedInt - OneEighth);
    unsigned int hash = 0;
    unsigned int test = 0;
    while (*str)
      {
	  hash = (hash << OneEighth) + (*str++);
	  if ((test = hash & HighBits) != 0)
	    {
		hash = ((hash ^ (test >> ThreeQuarters)) & (~HighBits));
	    }
      }
    return (hash & 0x7FFFFFFF);
}

bitset< UINT_MAX > s;

int main( )
{
   int n;
   scanf("%d",&n);

   char palabra[16];
   
   for(int i=0; i<n; ++i) {
      scanf("%s",palabra);
      s[PJWHash(palabra)] = 1;
   }
   
   int m;
   scanf("%d",&m);
   
   for(int i=0; i<m; ++i) {
      scanf("%s",palabra);
      if ( s[PJWHash(palabra)] )
      {
         printf("1\n");
      } else {
         printf("0\n");
      }
   }
}