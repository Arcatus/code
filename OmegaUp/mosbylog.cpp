#include <iostream>
//#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>

#define dataType uint32_t

int main()
{
	dataType contador = 0;
	dataType partA;
	dataType partB;

	dataType n, m;

	std::cin >> n >> m;

	partA = 0;
	partB = 0;

	while( !( n == 1 ) )
	{
		if ( n > m )
		{
			std::swap(n,m);
		}
		else
		{
			partA =  m / n;

			partB = m % n;

			if ( partB == 0)
			{
				std::cout << partA + contador;
				return 0;
			}
			else
			{
				m = partB;
			}

			contador += partA;
		}
	}

	std::cout << contador + m;
}