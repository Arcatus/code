#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;   
    double x, y, z;
    double dist[n];
    for(int i=0; i<n; ++i) {
        cin >> x >> y >> z;
        dist[i] = hypot(x,hypot(y,z));
    }
    sort(dist, dist+n);
    cout.precision(8);
    cout << fixed << dist[k-1] << '\n';
    return 0;
}