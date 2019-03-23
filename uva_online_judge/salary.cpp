//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>

int main()
{
	int n;
	scanf("%d",&n);

	int a[3];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d",&a[j]);
		}
		std::sort(a,a+3);
		printf("Case %d: %d\n",i+1,a[1]);
	}
}