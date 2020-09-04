#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
    ull k;
	int n, r;
	cin >> n >> r >> k;
	vector<int> a(n);
	for(auto& i : a) cin >> i;
    vector<ull> def(n);
    def[0] = 0;
    for(int i = 0; i <= min(n - 1, r); ++i) {
        def[0] += (ull) a[i];
    }
    for(int i = 1; i < n; ++i) {
        def[i] = def[i - 1];
        if(i + r < n) {
            def[i] += (ull) a[i + r];
        }
        if(i - r - 1 >= 0) {
            def[i] -= (ull) a[i - r - 1];
        }
    }
    //for(ull i: def) { cout << i << ' '; } cout << '\n';
    ull min_global = *min_element(def.begin(), def.end());
    ull max_global = *max_element(def.begin(), def.end());
	ull lo = min_global, hi = max_global + k;
	while( lo < hi ) {
        ull mid = lo + (hi - lo)/2 + 1;
        ull kt = k;
        bool ok = true;
        if(2*r + 1 >= n) {
            if(min_global + kt < mid) {
                ok = false;
            }
        } else {
            vector<ull> b = def;
            for(int i = 0; i < n; i++) {
                if(b[i] < mid) {
                    ll diff = mid - b[i];
                    if(kt >= diff) {
                        kt -= diff;
                        for(int j = i; j <= min(n - 1, i + 2*r); ++j) {
                            b[j] += diff;
                        }
                    } else {
                        ok = false; break;
                    }
                }
            }
        }
        if(ok) {
            lo = mid;
        } else {
            hi = mid - 1ULL;
        }
	}
	cout << lo << '\n';
	return 0;
}