#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[100+1]={};
    int x;
    for(int i=0; i<n; ++i) {
        cin >> x;
        a[x]++;
    }
    int ans = 0;
    for(int i=1; i<=100; ++i) {
        ans = max(ans,a[i]);
    }
    cout << ans << '\n';
    return 0;
}