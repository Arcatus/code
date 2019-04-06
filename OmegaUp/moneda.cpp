//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

const char *dineros[] =
{
	" billete(s) de 1000",
	" billete(s) de 500",
	" billete(s) de 200",
	" billete(s) de 100",
	" billete(s) de 50",
	" billete(s) de 20",
	" moneda(s) de 10",
	" moneda(s) de 5",
	" moneda(s) de 2",
	" moneda(s) de 1"
};

int arr[10];

int main()
{
	int n;
	scanf("%d",&n);

	int cambio = 0;

	 arr[0] = n / 1000;

	cambio = n % 1000;

	 arr[1] = cambio/500;

	cambio %= 500;

	 arr[2] = cambio/200;	

	cambio %= 200;

	 arr[3] = cambio/100;	

	cambio %= 100;

	 arr[4] = cambio/50;

	cambio %= 50;

	 arr[5] = cambio/20;	

	cambio %= 20;

	 arr[6] = cambio/10;	

	cambio %= 10;

	 arr[7] = cambio/5;

	cambio %= 5;

	 arr[8] = cambio/2;

	cambio %= 2;

	 arr[9] = cambio/1;

	 for (int i = 0; i <10; ++i)
	 {
	 	if (arr[i] != 0)
	 	{
	 		printf("%d%s\n",arr[i],dineros[i]);
	 	}
	 }
}