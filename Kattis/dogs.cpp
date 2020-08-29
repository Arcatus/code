#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct punto {
    int x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    punto a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    int m;
    cin >> m;
    punto b[m];
    for(int i = 0; i < m; ++i) {
        cin >> b[i].x >> b[i].y;
    }
    
    return 0;
}