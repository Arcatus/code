#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for(int i = 0; i < n; ++i) {
        cout << min(a[i], b[i]) << ' ';
    }   
    cout << '\n';
    for(int i = 0; i < n; ++i) {
        cout << max(a[i], b[i]) << ' ';
    }
    cout << '\n';
    return 0;
}