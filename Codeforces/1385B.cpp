#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(2 * n);
        for(int& i: a) cin >> i;
        bool ck[n + 1] =  { };
        for(int i = 0; i < 2*n; ++i) {
            if(!ck[a[i]]) {
                cout << a[i] << ' ';
                ck[a[i]] = true;
            }
        }
        cout << '\n';
    }
    return 0;
}