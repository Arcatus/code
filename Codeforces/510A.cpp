#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    char a[n + 5][m + 5];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            a[i][j] = '.';
        }
    }
    int i = 0, j = 0;
    while(i < n) {
        if(j == 0) {
            while(j < m) { 
                a[i][j] = '#';  
                j++;
            }
            j--;
        } else {
            while(j >= 0) {
                a[i][j] = '#'; 
                j--;
            }
            j++;
        }
        a[i + 1][j] = '#';
        i += 2;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cout << a[i][j];
        }
        cout << '\n';
    }
    return 0;
}