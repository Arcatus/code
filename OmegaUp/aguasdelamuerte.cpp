#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, d;
    cin >> n >> k >> d;
    int a[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    int recorrido=0;
    int pos;
    int ans = 0;
    while(recorrido+d < k) {
        pos = upper_bound(a,a+n,recorrido+d) - a;
        recorrido = a[pos-1];
        ans++;
    }
    cout << ans << '\n';
    return 0;
}