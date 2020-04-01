#include <bits/stdc++.h>
using namespace std;

struct s{ int x, y, c; };

int r[10000+1], p[10000+1];

int findSet(int k) {
    return k == p[k]? k : p[k] = findSet(p[k]);
}

bool isSame(int a, int b) {
    return findSet(a) == findSet(b);
}

void Union(int a, int b) {
    int x = findSet(a), y = findSet(b);
    if ( x == y ) {
        p[y] = x;
        r[x]++;
    } else {
        if (r[x] > r[y]) {
            p[y] = x;
        } else {
            p[x] = y;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >>m;
    s e[m+1];
    iota(p, p+n+1, 0);
    for(int i=0; i<m; ++i) {
        cin >> e[i].x >> e[i].y >> e[i].c;
    }
    sort(e, e+m, [](s a, s b){ return a.c < b.c; } );
    int ans = 0;
    for(int i=0; i<m; ++i) {
        if ( findSet(e[i].x) != findSet(e[i].y) ) {
            Union(e[i].x, e[i].y);
            ans += e[i].c;
        }
    }
    cout << ans << '\n';
}