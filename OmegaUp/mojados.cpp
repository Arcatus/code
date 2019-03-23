#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	int n, t, contador = 0;

	std::cin >> n;

	bool arr[100000 + 1]{false};

	for (int i = 0; i < n; ++i)
	{
		std::cin >> t;

		arr[t] = true;
	}

	for ( int i = 1 ; i <= 100000; ++i)
	{
		if ( arr[i] == true )
			contador++;
	}

	std::cout << contador << '\n';
}