//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int n;

	int posicion = 0;

	scanf("%d",&n);

	int arr[n];

	for(int i = 0; i < n; ++i)
	{
		scanf("%d",&arr[i]);
	}
	int saltos = 0;
	while( ! (  posicion == n-1  ) ) 
	{
		posicion += arr[posicion];
		saltos++;
	}	

	printf("%d\n",saltos);
}