#include <iostream>
//#include <cstdio>
#include <cstdlib>
//#include <string>
//#include <algorithm>
//#include <string>

struct lista
{
	int val;
	lista *adelante;
};

struct handle
{
	lista *inicio;
	lista *final;
};

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, I, J;

	std::cin >> n >> m;


	lista *arr[n + 1];

	handle torre[n + 1];

	for ( int i = 1; i <= n; ++i)
	{
		arr[i] = new lista();

		arr[i]->val = i;

		torre[i].inicio = arr[i];
		torre[i].final = arr[i];
	}
	
	for ( int i = 0; i < m; ++i)
	{
		std::cin >> I >> J;

		if ( torre[I].inicio != NULL && torre[J].inicio != NULL )
		{
			(torre[I].final)->adelante = torre[J].inicio;

			torre[I].final = torre[J].final;

			torre[J].inicio = NULL;
		}
		else if ( torre[I].inicio == NULL && torre[J].inicio != NULL )
		{
			torre[I] = torre[J];
			torre[J].inicio = NULL;
		}
	}

	for ( int i = 1; i <= n; ++i)
	{
		if ( torre[i].inicio == NULL )
		{
			std::cout << '\n';
		}
		else
		{
			while ( torre[i].inicio != NULL)
			{
				std::cout << torre[i].inicio->val << ' ';
				torre[i].inicio = (torre[i].inicio)->adelante;
			}
			std::cout << '\n';
		}
	}
}