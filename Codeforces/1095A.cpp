#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    int n;
    cin >> n >> s;
    for(int i=1; i<=10; i++) {
        if ( i*(i+1) / 2 == n ) {
            int offset=0;
            for(int j=0; j<i; offset=(j+1)*(j+2)/2, j++ ) {
                cout << s[offset];
            }
            break;
        }
    }
    return 0;
}