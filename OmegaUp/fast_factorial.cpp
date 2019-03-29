#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

/*
	Nota: si el factorial de n es mayor al modulo m siempre dara 0
*/

using namespace std;

int main()
{
	int n, m;

	cin >> n >> m;

	unsigned long long res = 1;

	if (n > m)
	{
		printf("0\n");
	}
	else
	{
		for (int i = 2; i <= n; ++i)
		{	
			res = ( res%m * i%m  );
		}
		cout << res << '\n';
	}
}