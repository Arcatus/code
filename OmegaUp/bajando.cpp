#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

long long memoria[30 + 1][ 30 ];

long long recorre(int h, int d )
{
	if ( memoria[h][d] ) {
		return memoria[h][d];
	}
	else if ( h == 1LL ) {
		return 1LL;
	}

	memoria[h][d] = recorre( h-1, d ) + 1;

	if ( d > 0 )  {
		memoria[h][d] += recorre( h-1, d-1 );
	}

	return memoria[h][d];
}

int main()
{
	int d;

	long long n;

	cin >> n >> d;

	int h = (int) floor( log2( n ) ) + 1;

	if ( n <= 1 ) {
		cout << n << '\n';
		return 0;
	}

	memoria[h][d] += recorre( h-1, d ) + 1;

	if ( d > 0 )  {
		memoria[h][d] += recorre( h-1, d-1 );
	}

	cout << memoria[h][d] << '\n';
}