#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        int a[k1];
        int b[k2];
        for(int i=0; i<k1; i++ ) cin >>a[i];
        for(int i=0; i<k2; i++ ) cin >>b[i];
        int x = *max_element(a,a+k1);
        int y = *max_element(b,b+k2);
        if ( x > y ) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}