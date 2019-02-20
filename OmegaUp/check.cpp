//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int temp = 0;

	int n;

	scanf("%d",&n);

	for(int i = 8 ; i <= n; ++i)
	{
		temp+=i;
	}					

	printf("%d\n",temp);
}