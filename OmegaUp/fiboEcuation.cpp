#include <cmath>
#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
	ll n;
	
	double phi;

	phi = ( 1 + sqrt(5))/2;

	cin >> n;

	ll res = ( pow(phi,n) - pow(( 1 - phi),n) )/sqrt(5);
	cout << res << '\n';
}