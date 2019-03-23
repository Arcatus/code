//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>

struct usuario
{
	char id[8 + 1];
	float promedio;
	int edad;
};

bool age_sort(usuario a, usuario b)
{
	return a.edad < b.edad;
}

int main()
{
	int n;

	scanf("%d",&n);	

	usuario arr[n];

	for (int i = 0; i < n; ++i)
	{
		scanf("%s",&arr[i].id);
		scanf("%f",&arr[i].promedio);
		scanf("%d",&arr[i].edad);
	}

	std::sort(arr, arr + n, age_sort);

	int t;

	scanf("%d",&t);

	if ( t < n )
	{
		printf("%s\n",arr[t].id);
		printf("%.2f\n",arr[t].promedio);
		printf("%d\n",arr[t].edad);
	}
	else
	{
		printf("ERROR\n");
	}
}