#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll INF = 1<<30;

ll minimo(const ll& a, const ll& b, const ll& c)
{
	return min(min(a,b),c);
}

ll diviteit(ll n, ll k)
{
	if (n == 1) {
		return k;
	}
	else 
	{
		ll r1 = INF, r2 = INF, r3 = INF;

		if ( n % 2 == 0) {
			r1 = diviteit( n/2, k+1);
		}
		else if ( n % 3 == 0)
		{
			r2 = diviteit( (2*n)/3, k+1);
		}
		else if (n % 5 == 0){
			r3 = diviteit( (4*n)/5, k+1);
		}
		else 
		{
			r1 = -1;
		}
		return minimo(r1,r2,r3);
	}	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll q, n;
	cin >> q;

	for (ll i=0;i<q;++i)
	{
		cin >> n;
		cout << diviteit( n, 0 ) << '\n';
	}

	return 0;
}