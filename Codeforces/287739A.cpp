#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll n, m, k, a, b, x, y, node, edge;
bool visited[1000 + 5];
set<pair<ll, ll>> checker;
vector<ll> adj[1000 + 5];
void dfs(ll k) {
     if(!visited[k]) {
          node++;
          visited[k] = true;
     }
     for(ll i : adj[k]) {
     	x = min(k, i);
  	y = max(k, i);
     	if(checker.count({x, y}) == 0 ) {
     	     checker.insert({x, y});
     	     edge++;
     	     dfs(i);
     	}
     }
}

int main()
{
     ios::sync_with_stdio(false);
     cin.tie(0);
     cin >> n >> m >> k;
     ll p[n];
     for(int i = 0; i < k; ++i) {
          cin >> p[i]; p[i]--;
     } 
     for(int i = 0; i < m; ++i) {
          cin >> a >> b; a--; b--;
          adj[a].push_back(b);
          adj[b].push_back(a);
     }
     ll ans = 0;
     vector<pair<ll, ll>> r;
     for(int i = 0; i < k; ++i) {
          checker.insert({-1, p[i]});
          dfs(p[i]);
          r.push_back({node, edge});
          edge = node = 0;
     }
     ll unused = 0;
     for(int i = 0; i < n; ++i) {
          if(!visited[i]) {
          	unused++;
          }
     }
     for(int i = 0; i < k; ++i) {
     	ans = max(ans, ((r[i].first+unused)*(r[i].first+unused-1))/2 - r[i].second);
     }
     cout << ans << '\n';
     return 0;
}
