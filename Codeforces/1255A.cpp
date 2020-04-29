#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int a, b;
    while(t--){
        cin >> a >> b;
        int ans = 0;
        if ( a > b )  {
            swap(a,b);
        }
        b = b -  a;
        while( b ) {
            if ( b >= 5 ) {
                ans += b/5;
                b = b%5;
            } else if ( b >= 2 ) {
                ans += b/2;
                b = b%2;
            } else {
                ans += b;
                b = 0;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}