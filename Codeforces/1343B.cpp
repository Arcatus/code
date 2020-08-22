#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n;
    while(t--) {
        cin >> n;
        vector<int> a;
        vector<int> b;
        for(int i = 1; i <= n / 2; ++i ) {
            a.push_back(2*i);
        }
        for(int i = 1; i <= n / 2 - 1; ++i ) {
            b.push_back(2*i - 1);
        }
        if ( b.empty() || a.empty() || b[ b.size() - 1 ] >= (n/2 - 1) + a[a.size() - 1] ) {
            cout << "NO\n";
        } else {
            if ( ((n/2 - 1) + a[a.size() - 1]) % 2 == 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                for(int i = 0; i < a.size(); ++i ) {
                    cout << a[i] << ' ';
                }
                for(int i = 0; i < b.size(); ++i ) {
                    cout << b[i] << ' ';
                }
                cout << (n/2 - 1) + a[a.size() - 1] << '\n';
            }
        }
    }
    return 0;
}