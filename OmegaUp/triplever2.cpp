//#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <set>
//#include <string>

using std::sort;
using std::to_string;

bool compare(int a, int b, int c)
{
	if ( (a + b) > c)
	{
		if( (b + c) > a )
		{
			if( ( c + a ) > b )
			{
				return true;
			}
		}
	}	
	return false;
}

int main()
{
	int m, n;

	int par = 0;
	int impar = 0;
	scanf("%d %d",&m,&n);

	std::string key;

	std::set<std::string> dp;

	int a[3]{};

	for( int i = m ; i <= n; i++)
	{
		for (int j = m; j <= n; j++)
		{
			
			for(int k = m; k <= n; k++)
			{

				if( i%2==0 && j%2==0 && k%2==0 )
				{
					a[0]=i; a[1]=j;a[2]=k;
					std::sort(a,a+3);

					key = to_string(a[0]) + to_string(a[1]) + to_string(a[2]);

					if( dp.count(key) > 0 )
					{
						continue;
					}

					if ( compare(i,j,k) )
					{
						//printf("%d %d %d \n",i,j,k);
						par++;
						dp.emplace(key);
					}
				}
				else if ( i%2==1 && j%2==1 && k%2==1 )
				{
					a[0]=i; a[1]=j;a[2]=k;
					std::sort(a,a+3);
					key = to_string(a[0]) + to_string(a[1]) + to_string(a[2]);
					if( dp.count(key) > 0 )
					{
						continue;
					}
					if ( compare(i,j,k) )
					{
						//printf("%d %d %d \n",i,j,k);
						impar++;
						dp.emplace(key);
					}
				}
			}
		}
	}
	printf("%d %d\n",impar,par);
}