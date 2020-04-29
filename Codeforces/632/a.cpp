#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int n, m;
    while (t--)
    {
        cin >> n >> m;
        for(int i=1; i<=n; ++i) {
            for(int j=1; j<=m; ++j) {
                if (i==1 && j==1) {
                    cout << "W";
                } else {
                    cout << "B";
                }
            }
            cout << '\n';
        }
    }
    return 0;
}