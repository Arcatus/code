#include <iostream>
//#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>

using namespace std;

struct vestido
{
	int numero_vestido;
	int bonito;
	int costo;
};

bool bonito_sort(vestido a, vestido b)
{
	if ( a.bonito == b.bonito )
	{
		return a.costo > b.costo;
	}
	return a.bonito < b.bonito;
}

int main()
{
	int n, dinero;
	cin >> n >> dinero;

	vestido arr[100];

	for (int i = 0; i < n; ++i)
	{
		arr[i].numero_vestido = i+1; 
		cin >> arr[i].bonito;
		cin >> arr[i].costo;
	}

	std::sort(arr,arr+n,bonito_sort);

	for (int i=n-1; i >= 0; i--)
	{
		if ( arr[i].costo <= dinero )
		{
			printf("%d\n",arr[i].numero_vestido);
			return 0;
		}
	}
}