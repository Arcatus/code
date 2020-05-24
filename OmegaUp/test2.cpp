#include <bits/stdc++.h>
#include <bits/stdc++.h>

using namespace std;

struct celda {
    int first, second;
};

string s;
int a[2001];
celda memoria[2001][2001];
celda solve(int i, int j) {
    if ( memoria[i][j].first != -1 && memoria[i][j].second != -1 ) {
        return memoria[i][j];
    }
    else if (i > j) {
        memoria[i][j] = {0, 0};
        return memoria[i][j];
    }
    else if ( i == j ) {
        int inc = 0;
        if ( a[i] ) inc++;
        memoria[i][j] = { 1, inc };
        return memoria[i][j];
    } else if ( s[i] == s[j] ) {
        int inc = 0;
        if ( a[i] ) inc++;
        if ( a[j] ) inc++;
        memoria[i+1][j-1] = solve(i+1, j-1);
        return { 2 + memoria[i+1][j-1].first, inc + memoria[i+1][j-1].second };
    }
    memoria[i+1][j] = solve(i+1,j);
    memoria[i][j-1] = solve(i,j-1);
    if ( memoria[i+1][j].second == memoria[i][j-1].second ) {
        memoria[i][j] = (memoria[i+1][j].first > memoria[i][j-1].first) ? memoria[i+1][j] : memoria[i][j-1];
    } else {
        memoria[i][j] = (memoria[i+1][j].second > memoria[i][j-1].second) ? memoria[i+1][j] : memoria[i][j-1];
    } 
    return memoria[i][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    while(cin >> s) {
        for(int i=0; i<s.size(); ++i) {
            for(int j=0; j<s.size(); ++j) {
                memoria[i][j].first = -1;
            }
        }
        cin >> n;
        for(int i=0; i<n; ++i) {
            cin >> x;
            a[x-1] = true;
        }
        celda ans = solve(0,s.size()-1);
        cout << ans.second << " " << ans.first << '\n';
        fill(a, a+s.size(), false);
    }
    return 0;
}