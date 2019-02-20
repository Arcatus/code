#include <stdio.h>

int memoria[10000] = { };

int funcion_loca(int x, int a)
{
	if ( a == 0 )
		return (x+1)/2;
	else if ( x == 0 )
		return 2*a;
	else if ( *(( memoria + x ) + a) )
		return memoria[x][a];

	memoria[x][a] = funcion_loca(x,a/2) + funcion_loca(x/2,a);

	return memoria[x][a];
}

int main()
{
	int x, a;
	scanf("%d %d",&x,&a);
	printf("%d",funcion_loca(x,a));
	return 0;
}