//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int n;

	scanf("%d",&n);

	int arr[n*n]{};

	for( int i = 0; i < n*n; ++i)
        scanf("%d",&arr[i]);

    for( int i = 0; i < n; i++)
    {
    	for( int j = (n-1); j >= 0; j--)
    	{
    		printf("%d ",arr[ j*n + i ]);
    	}
    	printf("\n");
    }
}