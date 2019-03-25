#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>
#include <cmath>

typedef long long ll;

using std::cout;
using std::cin;
using std::string;
using std::to_string;

int main()
{
	ll n;
	cin >> n;

	double phi;

	phi = ( 1 + sqrt(5))/2;

	string phi_string( to_string(phi) );

	cout << phi_string << '\n';

	if ( n < 2)
	{
		cout << n << '\n';
	}
	else
	{
		cout << ( pow(phi,n) - pow(( 1 - phi),n) )/sqrt(5);
	}
}