#include <iostream>

using namespace std;

bool esPrimo(int n)
{
	if ( n <= 1 ) {
		return false;
	} else {
		if ( n%2 == 0 ) {
			return n == 2 ? true:false;
		}
		for (int i = 3; i*i <= n ; i+=2) {
			if ( n % i == 0 ) {
				return false;
			}
		}
		return true;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	for (int i=0; i<200; ++i) {
		if ( esPrimo(i) ) {
			cout << i << " ";
		}
	}
}