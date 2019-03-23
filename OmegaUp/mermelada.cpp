//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int n;
	scanf("%d",&n);

	int a, b; int suma = 0;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d",&a,&b);

		suma += (a<b)?b:a;
	}
	printf("%d\n",suma);
}