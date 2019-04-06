#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>

using namespace std;

int n, contador;
int8_t ac;

char combinaciones[7 + 1];

void camion(const int8_t& m)
{
	if ( m == 0 ) {
		if ( ac == 21 )
			contador++;
		return;
	}

	for (int8_t i = 0; i <= 9; ++i) {
		combinaciones[m-1] = i + '0';
		ac += i;
		camion(m-1);
		ac -= i;
	}
}

int main()
{
	cin >> n;

	camion(n);

	cout << contador << '\n';
}