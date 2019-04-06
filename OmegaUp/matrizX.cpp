//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int arr[100 + 1][100 + 1];

int main()
{
	int n, m;
	scanf("%d %d",&m,&n);

	for (int i = 0; i < m; ++i )
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	for (int i = m-1; i >= 0; i-- )
	{
		for (int j = 0; j < n; j++)
		{
			if(i%2==0 && j%2==0)
			{
				printf("%d ",arr[i][j]);
			}
		}
	}printf("\n");
}