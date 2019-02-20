#include <cstdio>

int main()
{
  int a, b, c;

  scanf("%d%d%d",&a,&b,&c);

  if( a <= b && b <= c )
  {
  	printf("0\n");
  }
  else if ( a < c && a < b &&  b > c) 
  {
  	printf("1\n");
  }
  else if ( b < a && b < c && a < c )
  {
  	printf("1\n");
  }
  else if ( b < c && c < a )
  {
  	printf("2\n");
  }
  else if ( c < a && a < b )
  {
  	printf("2\n");
  }
  else if ( c < b && b < a )
  {
  	printf("1\n");
  }
  else if( a == b && a > c )
  {
  	printf("1\n");
  }
  else if( a == c && a > b )
  {
  	printf("1\n");
  }
  else if( a == c && a < b )
  {
  	printf("1\n");
  }

  return 0;
}