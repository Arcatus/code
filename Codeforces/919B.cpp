#include <iostream>

using namespace std;

int sumDigits(int a) {
	return a == 0 ? 0 : a%10 + sumDigits(a/10);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int k;

	cin >> k;

	int t = 19;

	int contador = 0;

	while( true ) {
		if ( sumDigits(t) == 10 ) {
			contador += 1;
			if ( contador == k ) {
				cout << t << '\n';
				return 0;
			}
		}
		t += 9;
	}
}