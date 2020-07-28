#include <bits/stdc++.h>

using namespace std;

struct punto {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    punto a, b;
    cin >> a.x >> a.y >> b.x >> b.y;
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; ++i) cin >> arr[i];
    double dist = (double) hypot( a.x - b.x, a.y - b.y );
    //cerr << dist << '\n';
    int ans = 0;
    double acc = arr[0];
    if ( dist < acc ) {
        cout << -1 << '\n';
        return 0;
    }
    for(int i=1; i<n; ++i) {
        //cerr << "cmp: " << acc << " " << dist << '\n';
        if ( acc >= dist ) {
            ans = i;
            break;
        }
        acc += (double) arr[i];
    }
    if ( ans == 0 && acc >= dist ) {
        ans = n;
    }
    if ( ans ) {
        cout << ans << '\n';
    } else {
        cout << -1 << '\n';
    }
    return 0;
}