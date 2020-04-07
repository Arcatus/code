#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int x;
        for(int i=0; i<n; ++i) {
            cin >> x;
            if ( x % 2 == 0 ) {
                p++;
            } else {
                imp++;
            }
        }
        int p=0, imp=0;

    }
    return 0;
}