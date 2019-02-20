//#include <iostream>
#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>

bool compare(int a, int b, int c);

int main()
{
	int m;

	int n;

	scanf("%d %d", &m, &n);

	int par = 0;
	int impar = 0;

	int arr[500+1];int arr1[500+1];int arr2[500+1];

	int brr[500+1];int brr1[500+1];int brr2[500+1];

	for ( int i = m; i <= n; ++i)	
	{
		if( i%2==0 )
		{
			arr[par] = i;
			par++;
		}
		else
		{
			brr[impar] = i;
			impar++;
		}
	}

	std::copy(&arr[0],&arr[par],&arr1[0]);
	std::copy(&arr[0],&arr[par],&arr2[0]);

	std::copy(&brr[0],&brr[impar],&brr1[0]);
	std::copy(&brr[0],&brr[impar],&brr2[0]);

	
	int idx=0, idy=0, idz=0; int res_par = 0;

	printf("Pares: %d\n",par);
	
	while( idx < par )
	{
		printf("arr:%d arr1:%d arr1:%d \n",arr[idx],arr1[idy],arr2[idz]);
		printf("idx:%d idy:%d idz:%d \n",idx,idy,idz);

		if ( compare(arr[idx],arr1[idy],arr2[idz]) )
		{
			res_par++;
			if ( idx <= idy && idx <= idz )
			{
				idx++;
			}
			else if( idy <= idx && idy <= idz  )
			{
				idy++;
			}
			else if( idz <= idx && idz <= idy  )
			{
				idz++;
			}
		}
		else
		{
			if ( idx <= idy && idx <= idz )
			{
				idx++;
			}
			else if( idy <= idx && idy <= idz  )
			{
				idy++;
			}
			else if( idz <= idx && idz <= idy  )
			{
				idz++;
			}
		}
	}

	idx=0; idy=0; idz=0; int res_impar = 0;

	printf("Impares: %d\n",impar);
	while( idx < impar )
	{
		printf("brr:%d brr1:%d brr1:%d \n",brr[idx],brr1[idy],brr2[idz]);
		printf("idx:%d idy:%d idz:%d \n",idx,idy,idz);

		if ( compare(brr[idx],brr1[idy],brr2[idz]) )
		{
			res_impar++;
			if ( idx <= idy && idx <= idz )
			{
				idx++;
			}
			else if( idy <= idx && idy <= idz  )
			{
				idy++;
			}
			else if( idz <= idx && idz <= idy  )
			{
				idz++;
			}
		}
		else
		{
			if ( idx <= idy && idx <= idz )
			{
				idx++;
			}
			else if( idy <= idx && idy <= idz  )
			{
				idy++;
			}
			else if( idz <= idx && idz <= idy  )
			{
				idz++;
			}	
		}
	}
		
	printf("%d %d\n",res_impar,res_par);

}

bool compare(int a, int b, int c)
{
	if ( (a + b) > c)
	{
		if( (b + c) > a )
		{
			if( ( c + a ) > b )
			{
				printf("VALIDO!!\n");
				return true;
			}
		}
	}	
	printf("NO VALIDO!!\n");
	return false;
}