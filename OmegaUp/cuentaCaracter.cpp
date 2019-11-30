#include <iostream>
#include <string>

using namespace std;

int abc[128];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int a, b;
	cin >> a >> b;

	string palabra;

	getline(cin,palabra);
	getline(cin,palabra);

	for (int i=a; i<=b; ++i)
	{
		abc[palabra[i]]++;
	}

	for (int i=97; i<=122; ++i )
	{
		cout << char(i)<<"="<<abc[i] << '\n';
	}

	return 0;
}