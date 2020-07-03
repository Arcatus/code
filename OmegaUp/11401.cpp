#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int ans = 0;
    int t1, d1, t2, d2;
    cin >> t1 >> d1;
    for(int i=1; i<n; ++i) {
        cin >> t2 >> d2;
        if ( (d2-d1)/(t2-t1) > ans ){
            ans = (d2-d1)/(t2-t1);
        }
        d1 = d2;
        t1 = t2;
    }
    cout << ans << '\n';
    return 0;
}