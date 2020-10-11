#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    ll k;
	int n, r;
	cin >> n >> r >> k;
	vector<ll> a(n);
	for(auto& i : a) cin >> i;
    vector<ll> def(n);
    def[0] = 0;
    for(int i = 0; i <= min(n - 1, r); ++i) {
        def[0] += a[i];
    }
    for(int i = 1; i < n; ++i) {
        def[i] = def[i - 1];
        if(i + r < n) {
            def[i] += a[i + r];
        }
        if(i - r - 1 >= 0) {
            def[i] -= a[i - r - 1];
        }
    }

	ll lo = 0, hi = (ll)(1e9) * (ll)(n) + k + 1ll;
	while( lo < hi ) {
        ll mid = (hi + lo + 1)/2;
        bool ok = true;
        ll soldados = 0, necesito = 0;
        ll e[n] = { };
        for(int i = 0; i < n && necesito <= k; i++) {
            soldados += e[i];
            if(def[i] + soldados < mid) {
                ll agrega = mid - (def[i] + soldados);
                necesito += agrega;
                soldados += agrega;
                if( i + 2*r + 1 < n) {
                    e[i + 2*r + 1] -= agrega;
                }
            }
        }
        if(necesito > k) ok = false;
        if(ok) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
	}
	cout << lo << '\n';
	return 0;
}