#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> r(7);
    int x;
    for(int i=0; i<7; ++i) {
        cin >> x;
        r[i] = x;
    }
    int k = 0;
    while( n > 0 ) {
        n -= r[k%7];
        if (n > 0) {
            k++;
        }
    }
    cout << (k % 7)+1 << '\n';
    return 0;
}