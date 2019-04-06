#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

using namespace std;

int main()
{
	unsigned long long n;
	unsigned long long m;

	cin >> n >> m;

	long long i = 1, residuo = 1, contador = 0;
	while( residuo != 0)
	{
		residuo = n / (1<<i);
		contador += residuo;
		i++;
	}
	cout << contador/m << '\n';
}