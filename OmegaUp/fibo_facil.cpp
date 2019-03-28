#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>
#include <cmath>

typedef long long ll;

using namespace std;

int main()
{
	ll n;
	
	double phi;

	phi = ( 1 + sqrt(5))/2;

	cin >> n;

	n++;

	ll res = ( pow(phi,n) - pow(( 1 - phi),n) )/sqrt(5);
	cout << res << '\n';

}