#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> primes;

ll gcd(ll a, ll b)
{
	return b == 0 ? a : gcd( b, a % b );
}

ll lcm(ll a, ll b) {
	return (a*b) / gcd(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, a, b;

	cin >> n >> a >> b;
	
	ll c = lcm(a,b);

	ll divA = n/a;

	if ( n%a == 0 ) {
		divA -=1;
	}

	ll divB = n/b;

	if ( n%b == 0 ) {
		divB -=1;
	}

	ll divC = n/c;

	if ( n%c == 0 ) {
		divC -=1;
	}

	ll ultimoA = a + a * ( divA-1);
	ll ultimoB = b + b * ( divB-1);
	ll ultimoC = c + c * ( divC-1);

	ll conjuntoA = ( divA* ( a + ultimoA ) ) / 2;
	ll conjuntoB = ( divB* ( b + ultimoB ) ) / 2;
	ll conjuntoC = ( divC* ( c + ultimoC ) ) / 2;

	cout << conjuntoA + conjuntoB - conjuntoC << '\n';
}