#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	
	ll contador = 0;
	ll positivos = 0;
	ll negativos = 0;
	ll ceros = 0;

	ll x;
	for(int i=0; i<n; ++i) {
		cin >> x;
		if ( x == 0 ) {
			ceros += 1;
		} else if( x <= -1 ){ 
			negativos += 1;
			contador += -1 - x;
		} else if ( x >= 1 ) {
			positivos += 1;
			contador += x - 1;
		}
	}
	if ( negativos % 2 == 0 ) {
		cout << contador + ceros << '\n';
	} else {
		if ( ceros == 0 ) {
			cout << contador + 2  << '\n';
		} else {
			cout << contador - 1 + ceros + 1 << '\n';
		}
	}	
}