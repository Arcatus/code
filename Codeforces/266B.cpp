#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    char q[55];
    int a, b;
    cin >> a >> b;
    cin >> q;
    for(int i=0; i<b; ++i) {
        for(int j=0; j<a-1; j++) {
            if ( q[j] == 'B' && q[j+1] == 'G' ) {
                swap(q[j], q[j+1]);
                j++;
            }
        }
    }
    cout << q << '\n';
    return 0;
}