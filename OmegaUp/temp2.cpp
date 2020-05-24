#include <bits/stdc++.h>

using namespace std;
using celda = std::pair<int, int>;

string s;
bool a[2000];
celda memoria[2000][2000];

celda solve(int i, int j) {
    if ( memoria[i][j].first != -1 ) {
        return memoria[i][j];
    } else if ( i > j ) {
        return memoria[i][j] = { 0, 0 };
    } else if ( i == j ) {
        return memoria[i][j] = { a[i], 1 };
    } else {
        auto r = std::max(solve(i+1,j), solve(i,j-1));
        if (s[i] == s[j]) {
           auto t = solve(i+1, j-1);
           r = std::max(r, { a[i] + a[j] + t.first, 2 + t.second });
        }
        return memoria[i][j] = r;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> s) {
        for(int i=0; i<s.size(); ++i) {
            for(int j=0; j<s.size(); ++j) {
                memoria[i][j] = {-1,-1};
            }
        }
        int n;
        cin >> n;
        std::fill(a, a+s.size(), false);
        for(int i=0; i<n; ++i) {
            int x;
            cin >> x;
            a[x-1] = true;
        }
        cout << solve(0,s.size()-1).second << '\n';
    }
    return 0;
}
