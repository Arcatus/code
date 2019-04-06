#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

char msj[1001];

int main()
{
	string abecedario = "abcdefghijklmnopqrstuvwxyz 0123456789";

	int clave;

	scanf("%[^\n]",msj);

	cin >> clave;

	size_t size = abecedario.length();
	size_t found;

	for (int i = 0; i < strlen(msj); ++i)
	{
		found = abecedario.find_first_of(msj[i]);

		if ( found < clave )
		{
			found = found + size;
		}
		cout << abecedario[found - clave];
	}
	cout <<'\n';
}