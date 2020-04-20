#include <bits/stdc++.h>

using namespace std;

struct task {
    int s, e;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    task a[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i].s >> a[i].e;
    }
    sort(a, a+n, [](task a, task b) {
        return a.e < b.e;
    } );
    int ans = 1;
    int p = a[0].e;
    for(int i=1; i<n; ++i) {
        if ( a[i].s >= p ) {
            ans++;
            p = a[i].e;
        }
    }
    cout << ans << '\n';
    return 0;
}