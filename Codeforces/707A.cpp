#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    char color;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> color;
            if(color == 'C' || color == 'M' || color == 'Y') {
                cout << "#Color\n";
                return 0;
            }
        }
    }
    cout << "#Black&White\n";
    return 0;
}