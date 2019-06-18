#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned int ll;

unsigned int memoria[1950+1][1950+1];

ll loca(ll x, ll a)
{
	if ( x != 0 && a <= 1)
	{
		return (x<<1)/3;
	}
	else if (x <= 1 && a != 0)
	{
		return (a*a)>>1;
	}
	else
	{
		if ( memoria[x][a] == 0 )
		{
			memoria[x][a] = loca(x+1,a-2) + loca(x-2,a+1);			
		}	
		return memoria[x][a];
	}
}

int main()
{
	int x, a;
	cin >> x >> a;

	ll ans = loca(x,a);

	cout << ans << '\n';

	return 0;
}