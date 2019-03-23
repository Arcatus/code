//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int n;
int magic_value = 0;

void debug(const int* arr)
{
	for(int i=0; i < n*n ; ++i)
	{
		printf("arr[%d]:%d ",i,arr[i]);
		if ((i+1)%n==0)
			printf("\n");
	}
}

bool verif_diagonals(const int* arr)
{
	int diag1 = 0, diag2 = 0;

	//debug(arr);

	for(int i = 0; i < n; ++i)
	{
		diag1 += arr[i*n + i];
		//printf("pre_diag1:%d\n",diag1);

		diag2 += arr[i*n + (n-1-i)];
		//printf("pre_diag2:%d\n",diag2);
	}

	//printf("d1:%d d2:%d\n",diag1,diag2);

	return (diag1==magic_value)&&(diag1==diag2);
}

bool verif_columns(const int* arr)
{
	int t;
	int columns[ n ]{};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			columns[j] += arr[i*n + j];
		}
	}
/*
	for(int i = 0; i < n; ++i )
	{
		printf("col[%d]:%d\n",i,columns[i]);
	}
*/
	if ( magic_value == columns[0] )
	{
		for(int i = 0; i < (n - 1); ++i)
		{
			if ( ! ( columns[i] == columns[i+1]  ) )
			{
				return false;
			}
		}
	}	
	else
	{
		return false;
	}

	return true;
}

bool verif_filas(const int* arr)
{
	int t;
	int filas[ n ]{};

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			filas[i] += arr[ i*n + j ];
		}
	}
	if ( magic_value == filas[0] )
	{
		for(int i = 0; i < (n - 1); ++i)
		{
			if ( ! ( filas[i] == filas[i+1]  ) )
			{
				return false;
			}
		}
	}
	else
	{
		return false;
	}

	return true;
}

int main()
{
	scanf("%d",&n);

	int arr[n*n];

	for (int i = 0; i < n ; ++i)
	{
		for(int j = 0; j < n; ++j)
		{
			scanf("%d",&arr[i*n + j]);
		}	
	}

	for(int i = 0; i < n; ++i)	
	{
		magic_value += arr[i];
	}

	if ( verif_diagonals( arr ) )
	{
		if ( verif_columns( arr ) ) 
		{
			if ( verif_filas( arr ) )
			{
				printf("1\n");
			}
			else printf("0\n");
		}
		else printf("0\n");
	}
	else printf("0\n");

	//printf("magic_value:%d\n",magic_value );
}