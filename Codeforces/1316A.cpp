#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, m;
    while(t--) {
        cin >> n >> m;
        int a[n];
        for(int i=0; i<n; ++i) {
            cin >> a[i];
        }
        int sum = accumulate(a,a+n,0);
        cout << min(m, sum) << '\n';
    }
    return 0;
}