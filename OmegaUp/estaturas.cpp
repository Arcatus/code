//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int n;
	scanf("%d",&n);

	float tmp;
	int contador = 0;

	for(int i = 0; i < n; ++i)
	{
		scanf("%f",&tmp);
		if ( tmp > 1.70f)
		{
			contador++;
		}
	}
	printf("%d\n",contador);
}