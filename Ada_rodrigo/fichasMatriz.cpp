#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
#include <set>

int n;

using std::string;
using std::set;

std::string bitmask;

std::set<string> permutations;

void fichas( bool *mat )
{
	bitmask = "";

	bool m[n][n];

	memcpy(m,mat,n*n*sizeof(bool));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			bitmask += (m[i][j]==true)?'1':'0';
		}
		bitmask+='|';
	}
	
	if ( permutations.count(bitmask) == 1)
	{
		return;
	}

	int res = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if ( m[i][j] == true && m[i][j+1] == true )
			{
				m[i][j] = false;
				m[i][j+1] = false;
				fichas(*m);
				m[i][j] = true;
				m[i][j+1] = true;
			}
		}
	}

	bitmask = "";

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			bitmask += (m[i][j]==true)?'1':'0';
		}
		bitmask+='|';
	}

	std::cout << bitmask << '\n';

	permutations.emplace(bitmask);
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

	fichas(*m);
	printf("%d\n",(int) permutations.size() );
}