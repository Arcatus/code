#include <bits/stdc++.h>
using namespace std;

struct s{ int x, c; };
bool operator<(s a, s b) { return a.c > b.c; };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int x, y, c;
    vector<vector<pair<int,int>>> a(n+1);
    for(int i=0; i<m; ++i) {
        cin >> x >> y >> c;
        a[x].push_back({y,c});
        a[y].push_back({x,c});
    }
    priority_queue<s> q;
    q.push({1,0});
    vector<bool> v(n+1,false);
    int ans = 0;
    while(!q.empty()) {
        s p = q.top();
        q.pop();
        if ( !v[p.x]) {
            v[p.x] = true;
            ans += p.c;
            for(pair<int,int> t : a[p.x] ) {
                q.push({ t.first , t.second });
            }
        }
    }
    cout << ans << '\n';
}