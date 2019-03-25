#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <unordered_map>

typedef long long ll;

int n;

using std::string;
using std::unordered_map;

std::unordered_map<string, ll> dp;

string generateMask( const bool *m );

ll fichas(const bool *mat ) // asuncion 0 <= n <= 7
{
	string bitmask_padre = generateMask(mat);

	int res = 1;

	for (int i = 0; i < n; ++i)
	for (int j = 0; j < n - 1; ++j)
	{
		if ( mat[i*n + j] == true && mat[i*n + j +1] == true )
		{
			bool m[n][n];
			memcpy(m,mat,n*n*sizeof(bool));

			m[i][j]   = false;
			m[i][j+1] = false;

			string is_inMask = generateMask( *m );

			if ( dp.count( is_inMask ) == 0 )
			{
				long long tmp = fichas( *m );
				
				dp[ is_inMask ] = tmp;
				
				res += dp[ is_inMask ];
			}
			else
			{
				return dp[ is_inMask ];
			}
		}
	}

	dp[bitmask_padre] = res;

	return dp[bitmask_padre];
}

string generateMask( const bool *m )
{
	string bitmask = "";
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < n; ++y)
		{
			bitmask += (m[x*n + y]==true)?'1':'0';
		}
	}
	return bitmask;
}

int main()
{
	scanf("%d",&n);

	bool m[n][n];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			m[i][j] = true;
		}	
	}

	printf ("%lld \n", fichas(*m) );
}