#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int t, l;
    while(n--) {
        cin >> t >> l;
        if (t == 0 || l == 0) {
            cout << "R\n";
        } else if ( t > l ) {
            cout << "I\n";
        } else {
            if ( l % t == 0 ) {
                cout << "R\n";
            } else {
                cout << "I\n";
            }
        }
    }
    return 0;
}