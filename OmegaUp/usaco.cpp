#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>

using namespace std;

typedef unsigned long long llu;

int main()
{
	string cometa, grupo;

	cin >> cometa >> grupo;

	llu a=1, b=1;

	for(int i = 0; i < cometa.length(); ++i)
	{
		a *= (cometa[i] - 'A' + 1);
		a = a%47;
	}

	for(int i = 0; i < grupo.length(); ++i)
	{
		b *= (grupo[i] - 'A' + 1);
		b = b%47;
	}

	if ( a == b)
	{
		cout << "GO" << '\n';
	}
	else
	{
		cout << "STAY" << '\n';	
	}
}
