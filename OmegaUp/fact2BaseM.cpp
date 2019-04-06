#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

using namespace std;

int main()
{
	int casos;
	unsigned long long n;
	unsigned long long m;

	cin >> casos;

	for (int i = 0; i < casos; ++i)
	{
		cin >> n >> m;

		long long exp = 1, residuo = 1, contador = 0;
		while( residuo != 0)
		{
			residuo = n / (1<<exp);
			contador += residuo;
			exp++;
		}
		cout << contador/m << '\n';
	}
}