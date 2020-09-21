#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a[5] = { };
    int b[5] = { };
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] ) {
        cin >> b[0] >> b[1] >> b[2] >> b[3] >> b[4];
        bool ok = true;
        for(int i=0; i < 5; ++i) {
            if ( a[i] == b[i] ) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << "Y\n";
        } else {
            cout << "N\n";
        }
    }
    return 0;
}