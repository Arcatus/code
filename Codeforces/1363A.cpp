#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, x;
    while(t--) {
        cin >> n >> x;
        int pa=0, im=0;
        int v;
        for(int i=0; i<n; ++i) {
            cin >> v;
            if(v&1)im++;
            else pa++;
        }
        if (im==0) {
            cout << "No\n";
        } else {
            int tope = min(x, im);
            if(tope%2==0) tope--;
            if ( x - tope <= pa ) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
    return 0;
}