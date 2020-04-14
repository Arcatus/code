#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, m, a;

	cin >> n >> m >> a;

	long long sideA, sideB;

	if ( m % a == 0 ) {
		sideA = m / a;
	} else {
		sideA = m / a + 1;
	}

	if ( n % a == 0 ) {
		sideB = n / a;
	} else {
		sideB = n / a + 1;
	}

	cout << sideA * sideB << '\n';
}