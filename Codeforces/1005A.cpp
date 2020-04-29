#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    int x;
    int cnt = 0;
    vector<int> a;
    int i;
    for(i=1; i<=n; ++i) {
        cin >> x;
        if ( x==1 ) {
            ans++;
            a.push_back( i - cnt );
            cnt = i;
        }
    }
    a.push_back( i - cnt );
    cout << ans <<'\n';
    for(int k=1; k<a.size(); ++k) cout << a[k] << ' '; cout << '\n';
    return 0;
}