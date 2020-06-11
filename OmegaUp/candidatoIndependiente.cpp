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
    bool tomado[101] = { };
    for(int i=0; i<n; ++i) {
        cin >> a[i].s >> a[i].e;
    }    
    sort(a, a+n, [](task a, task b) {
        return a.e == b.e ? ( a.s < b.s ) : ( a.e < b.e );
    } );
    int eventos[26][26];
    for(int i=8; i<24; ++i) {
        eventos[i][i+1] = 2;
    }
    int ans = 0;
    for(int i=0; i<n; ++i) {
        for(int j = a[i].s; j<a[i].e; ++j) {
            if (eventos[ j ][ j + 1 ] > 0) {
                ans++;
                eventos[ j ][ j + 1 ]--;
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}