#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll multmod(ll a, ll b, ll mod) {
	ll res = 0LL;
	//a = a % mod;
	while(b) {
		if ( b & 1LL ) {
			res = (res + a) % mod;
		}
		a = (a<<1) % mod;
		b >>= 1LL;
	}
	return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll n;
	int omega, k;
    cin >> n >> omega >> k;
    vector<ll> omegas;
	ll l, r, x, y, s, z;
	int cnt = 0;
    for(int i=0; i<omega; ++i) {
        cin >> l >> r;
		if (r&1) {
			s = multmod(r,(r+1LL)/2,1000000000000000009);
		} else {
			s = multmod(r/2,r+1LL,1000000000000000009);
		}
		l--;
		if (l&1) {
			z = multmod(l,(l+1)/2,1000000000000000009);
		} else {
			z = multmod(l/2,l+1,1000000000000000009);
		}
		s = (s - z);
		if (s < 0) s += 1000000000000000009LL;
        omegas.push_back(s);
    }
    ll v, chavos=0, empate=0, reyes=0;
    sort(omegas.begin(), omegas.end());
    for(ll i=0; i<k; ++i) {
        cin >> v;
        int zz = lower_bound(omegas.begin(), omegas.end(), v) - omegas.begin();
        int ww = upper_bound(omegas.begin(), omegas.end(), v) - omegas.begin();
        empate += ww-zz;
        chavos += omegas.size() - ww;
        reyes += zz;
    }
    cout << "Chavos :) x " << chavos << '\n';
    cout << "Tablas :| x " << empate << '\n';
    cout << "Reyes :( x " << reyes << '\n';
    return 0;   
}