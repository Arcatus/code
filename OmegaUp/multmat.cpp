#include <iostream>
#include <algorithm>
#include <cstdio>

int main()
{
	int n, m, o;

	scanf("%d %d %d",&n,&m,&o);

	int arr[n][m]{};

	int brr[m][o]{};

	for( int i = 0; i < n; ++i)
    for( int j = 0; j < m; ++j)
    	scanf("%d",&arr[i][j]);

    for( int i = 0; i < m; ++i)
    for( int j = 0; j < o; ++j)
    	scanf("%d",&brr[i][j]);

	for( int i = 0; i < n; ++i)
	{
		for( int j = 0; j < o; ++j)
	    {
	    	int val = 0;
	    	for (int l = 0; l < m; ++l)
		    {
		        val += arr[i][l] * brr[l][j];
		    }
		    printf("%d ",val);
	    }
	    printf("\n");
	}
    
}