#include <bits/stdc++.h>

using namespace std;

struct x{
    int t[2], p;
} L[100];

int cmp(x a, x b) {
    return a.t[0] == b.t[0] ? ( a.t[1] < b.t[1] ? 1:0 ):( a.t[0] < b.t[0] ? 1 : 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    int P[(int)log2(n)][n];
    for(int i=0; i<s.size(); ++i) {
        P[0][i] = s[i] - 'a';
    }
    for(int i=1, k=1; k < n; k<<=1 ) {
        for(int j=0; j<n; ++j) {
            L[j].t[0] = P[i-1][j];
            L[j].t[1] = j+k < n ? P[i-1][j+k] : -1;
            L[j].p = j;
        }
        sort(L, L+n, cmp);
        for(int j=0; j<n; ++j) {
            P[i][ L[j].p ] = j > 0 && L[j].t[0] == L[j-1].t[0] && L[j].t[1] == L[j-1].t[1] ? P[i][L[j-1].p]: j;
        }
    }
    for(int i=0; i<(int)log2(n); ++i) {
        for(int j=0; j<n; ++j) { 
            cout << P[i][j] << ' ';
        }cout << '\n';
    }
    return 0;
}

int lcp(int x, int y)
{
    int k, ret = 0; 
    if (x == y) return N - x;
    for (k = stp - 1; k >= 0 && x < N && y < N; k --)
        if (P[k][x] == P[k][y])
            x += 1 << k, y += 1 << k, ret += 1 << k; 
    return ret;
} 