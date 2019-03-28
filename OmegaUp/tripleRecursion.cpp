#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	short n,xx,k, i, j;

	std::cin >> n >> xx >> k;

	short m[n+1][n+1];

	m[0][0] = xx - k;

	for (i = 1; i <= n; ++i)
	{	
		for (j = 1; j <= n; ++j)
		{
			if (i == j)
			{
				m[i][j] = m[i - 1][j - 1] + k;
			}
			else if ( i > j )
			{	
				m[i][j] = m[i - 1][j] - 1;
			}
			else 
			{
				m[i][j] = m[i][j - 1] - 1;
			}
		}
	}

	for (int i = 1; i <= n; ++i)
	{	
		for (int j = 1; j <= n; ++j)
		{
			std::cout << m[i][j] << ' ';
		}
		std::cout << '\n';
	}
}