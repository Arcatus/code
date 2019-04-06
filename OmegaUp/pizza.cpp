//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>
#include <cmath>

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);

	float pizzaK = k;

	float sobranteK = 0.25f * k;

	float pizzaM = m / 2.0f;

	float sobranteM = ceil( pizzaM ) - pizzaM;	

	float paraN = sobranteK + sobranteM;

	float pizzaN = n / 4.0f;

	if ( paraN >= pizzaN )
	{
		pizzaN = 0;
	}
	else
	{
		pizzaN = pizzaN - paraN;
	}

	int res = ceil( pizzaK ) + ceil( pizzaM ) + ceil( pizzaN);

	printf("%d\n",res);
}