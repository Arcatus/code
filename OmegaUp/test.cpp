
#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<int> v;
long long solve(long long x, long long y) {
    if (y == k) {
        long long ans = 1LL << 62, acc = 0;
        for(int i: v) cout << i << ' '; cout << '\n';
        for(long long i=1, d = 1; i<v.size(); ++i, d++ ) {
            acc += (d*(k - d))*abs( v[i] - v[i-1] );
        }    
        return ans;
    } else if (x == n) return 0;

    v.push_back(a[x]);
    long long a = solve(x+1,y+1);
    v.pop_back();
    long long b = solve(x+1,y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i=0; i<n; ++i) cin >> a[i];
    long long ans = solve(0,0);
    return 0;
}