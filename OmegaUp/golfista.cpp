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
<<<<<<< HEAD
    long long ans = 0, topeA = -1, topeB = -1;
    for(long long i=0; i<n; ++i) {
        if ( topeA <= dist && dist <= topeB ) {
=======
    long long ans = 0;
    for(long long i=0; i<n; ++i) {
        if ( arr[i] == dist ) {
>>>>>>> 91348413c0cc0ca2c9e5c245fd09ffa3f89ba80d
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