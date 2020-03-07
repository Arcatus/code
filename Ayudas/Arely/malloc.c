#include <stdio.h>
#include <stdlib.h>

int func(int *a)
{
	a = (int*) malloc( sizeof (int) );
	*a = 5;
}

int main()
{
	int *a;

	func(a);

	if ( a == NULL ) printf("No hay nada\n");
 	else printf("%d\n",*a);
}