#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long m, t, u, f, d;

	cin >> m >> t >> u >> f >> d;

	long long tiempo = 0;

	char a;
	long cuenta_pasos = 0;

	while( tiempo < m && cuenta_pasos <= t)
	{
		cin >> a;
		if (a == 'F') {
			tiempo+= f + f;
		} else {
			tiempo+= u + d;
		}

		if ( tiempo >= m )
		{
			if (tiempo==m)
				cuenta_pasos++;
			break;
		}
		cuenta_pasos++;		
	}

	cout << cuenta_pasos << '\n';

	return 0;
}