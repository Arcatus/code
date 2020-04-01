#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > a(100000+1);
vector<bool> v(100000+1, false);

void dfs(int k) {
    v[k] = true;
    for(int i: a[k]) {
        if ( !v[i] ) {
            dfs(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int x, y;
    for(int i=0; i<m; ++i) {
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    cin >> x;
    dfs(x);
    int ans = 0;
    for(int i=1; i<=n; ++i) {
        if ( !v[i] ) ans++;
    }
    cout << ans << '\n';
}