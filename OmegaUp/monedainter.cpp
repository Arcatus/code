#include <bits/stdc++.h>

using namespace std;

struct inter {
    int s, e;
} a[1000000+1];

int n;
int overlap () {
    sort(a, a+n, [](inter a, inter b) {
    return a.s < b.s;
    });
    int index=0;
    for(int i=1; i<n; ++i) {
        if ( a[index].e >= a[i].s ) {
            a[index].e = min(a[index].e, a[i].e);
        } else {
            a[++index] = a[i];
        }
    }
    return index+1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    if (n == 0 ) {
        cout << 0 << '\n';
    } else {
        for(int i=0; i<n; ++i) {
            cin >> a[i].s >> a[i].e;
        }
        int ans = overlap();
        cout << ans << '\n';
    }
    return 0;
}