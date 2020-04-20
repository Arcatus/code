#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for(int i=0; i<n; ++i) {
            cin >> a[i];
        }
        int in=0, ip=0;
        int im[2], ir[1];
        for(int i=0; i<n && in < 2 && ip < 1; ++i) {
            if (a[i]%2==0) {
                ir[ip++] = i+1;
            } else {
                im[in++] = i+1;
            }
        }
        if ( ip==1 ) {
            cout << 1 << '\n';
            cout << ir[0] << '\n';
        } else if( in==2 ) {
            cout << 2 << '\n';
            cout << im[0] << " " << im[1] << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
