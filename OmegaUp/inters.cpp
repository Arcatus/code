//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>

int arr[100 + 1];
int brr[100 + 1];
int crr[100 + 1];
int res[100 + 1];

int main()
{
	int n;
	scanf("%d",&n);
	int indexer = 0;

	for (int i = 0; i < 100 + 1; ++i)
	{
		arr[i] = -1;
		brr[i] = -1;
		crr[i] = -1;
		res[i] = -1;
	}

	for (int i = 0; i < n; ++i)	
	{
		scanf("%d ",&arr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d ",&brr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		scanf("%d ",&crr[i]);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ( arr[i] == brr[j])
			{
				for (int k = 0; k < n; ++k)
				{	
					if ( arr[i] == crr[k])
					{
						res[indexer] = arr[i];
						brr[j] = -1;
						arr[i] = -1;
						crr[k] = -1;
						indexer++;
					} 
				}
			}
		}
	}

	std::sort( res, res + 101 );

	for(int i = 0; i < 100; ++i)
	{
		if ( res[i] >= 0 )
		{
			printf("%d ",res[i]);
		}
	}
	printf("\n");
}