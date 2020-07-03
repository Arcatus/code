#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--) {
        cin >> n;
        if (n==1) {
            cout << 0 << '\n';
        } else {
            vector<int> p;
            bool ok = true;
            int cnt2=0, cnt3=0;
            while(n!=1) {
                if ( n%2==0 ) {
                    cnt2++;
                    n /= 2;
                } else if( n%3==0 ) {
                    cnt3++;
                    n /= 3;
                } else {
                    ok = false; break;
                }
            }
            if(ok) {
                if (cnt3>=cnt2) {
                    cout << cnt3+(cnt3-cnt2) << '\n';
                } else {
                    cout << -1 << '\n';
                }
            } else {
                cout << -1 << '\n';
            }
        }
    }
    return 0;
}