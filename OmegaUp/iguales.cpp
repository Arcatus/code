//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>

int main()
{
	int arr[5];

	for(int i = 0; i < 5; ++i)
	{
		scanf("%d",&arr[i]);
	}

		std::sort(arr,arr+5);

		int n[100 + 1]{};

		for(int i = 0; i < 5; ++i)
		{
			n[arr[i]]++;
		}

		std::sort(n,n+101);

		if ( n[100] == 1)
		{
			printf("Muy diferentes\n");
		}
		else if ( n[100] == 2)
		{
			printf("Diferentes\n");
		}
		else if( n[100] == 3)
		{
			printf("Iguales\n");	
		}
		else if( n[100] == 4)
		{
			printf("Muy iguales\n");
		}
		else if( n[100] == 5)
		{
			printf("Identicamente iguales\n");
		}
}