#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <string>
#include <cmath>

typedef unsigned long long llu;

using namespace std;

int main()
{
	llu n;
	
	double phi;

	phi = ( 1 + sqrt(5))/2;

	cin >> n;

	if ( n < 2)
	{
		cout << n << '\n';
	}
	else if (n == 2)
	{
		cout << "2" << '\n';
	}
	else if ( n < 93)
	{	
		n++;

		llu res = ( pow(phi,n) - pow(( 1 - phi),n) )/sqrt(5);


		cout << res % 1000000007 << '\n';
	}
	else 
	{
		n++;

		llu divisor = 0;

		if ( n%2==0 )
		{
			for ( llu j = 4; j <= n; j+=2 )
			{
				if ( n % j == 0 )
				{
					divisor = j;
					break;
				}
			}
		}
		else
		{
			for ( llu j = 3; j <= n; j+=2 )
			{
				if ( n % j == 0 )
				{
					divisor = j;
					break;
				}
			}
		}

		//cout << "divisor: " << divisor << '\n';

		llu fibo_seg = ( pow(phi,divisor) - pow(( 1 - phi),divisor) )/sqrt(5);

		//cout << "fibo_seg: " << fibo_seg << '\n';		

		llu res = ( ( n / divisor ) ) * ( fibo_seg);

		cout << res % 1000000007 << '\n';
	}
} 