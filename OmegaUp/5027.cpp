#include <bits/stdc++.h>
// g++ file -fsanitize=address remember check bounds before submit

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    char c;
    cin >> n >> c;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= i; ++j) {
            cout << c;
        }
        cout << '\n';
    }
    return 0;
}