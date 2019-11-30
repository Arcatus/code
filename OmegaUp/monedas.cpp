//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

const char *dineros[] =
{
	"500",
	"200",
	"100",
	"50",
	"25",
	"10",
	"5",
	"1"
};

int arr[10];

int main()
{
	int n;
	scanf("%d",&n);

	int cambio = 0;

	arr[0] = n / 500;

	cambio = n % 500;

	arr[1] = cambio/200;

	cambio %= 200;

	 arr[2] = cambio/100;	

	cambio %= 100;

	 arr[3] = cambio/50;	

	cambio %= 50;

	 arr[4] = cambio/25;

	cambio %= 25;

	 arr[5] = cambio/10;	

	cambio %= 10;

	 arr[6] = cambio/5;	

	cambio %= 5;

	arr[7] = cambio/1;

	 for (int i = 0; i < 8; ++i)
	 {
	 	printf("De %s\thay %d\n",dineros[i],arr[i]);
	 }
}