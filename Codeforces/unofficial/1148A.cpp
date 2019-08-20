#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long ll;

ll mini(ll a, ll b, ll c) {
	return min(a,min(b,c));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;

	cin >> a >> b >> c;

	ll ans=0;
	while(a!=0 && b!=0 && c!=0 ) {
		ll minimo = mini(a,b,c);
		ans += 4*minimo;
		a -= minimo;
		b -= minimo;
		c -= minimo;
	}

	if ( a == 0 ) {
		ans += 2*c + (b>0);
	}else if ( b == 0) {
		ans += 2*c + (a>0);
	}else if ( c == 0 ) {
		ll v = min(a,b);
		ans += 2*v;
		a-=v;
		b-=v;
		if (b>0) ans +=1;
		if (a>0) ans +=1;
	}

	cout << ans << '\n';
}