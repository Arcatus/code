#include <bits/stdc++.h>

using namespace std;

struct punto {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    punto a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    long long n;
    cin >> n;
    long long arr[n];
    for(long long i=0; i<n; ++i) cin >> arr[i];
    long long dist = (long long) hypot( a.x - b.x, a.y - b.y );
    long long ans = 0;
    for(long long i=0; i<n; ++i) {
        if ( arr[i] == dist ) {
            ans = i+1;
            break;
        }
    }
    if ( ans ) {
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}