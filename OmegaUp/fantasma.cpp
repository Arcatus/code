#include <bits/stdc++.h>

using namespace std;

int n, m, f;
int posicionF[1001];
vector<vector<int>> adj(1001);

int memoria[1000+1][1000+1];
int fantasma(int k, int t) {
	if (t == f) {
		return 0;
	} else {
		if ( memoria[k][t] != -1 ) {
			return memoria[k][t];
		}
		memoria[k][t] = fantasma(k,t+1);		
		for(int i=0; i < adj[k].size(); ++i ) {
			memoria[ adj[k][i] ][t+1] = fantasma(adj[k][i], t+1);
			memoria[k][t] = max(memoria[k][t], memoria[ adj[k][i] ][t+1]);
		}
		memoria[k][t] += (posicionF[t] == k);
		return memoria[k][t];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int x, y;
	for(int i=0; i<m; ++i) {
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> f;
	for(int i=0; i<f; ++i) {
		cin >> posicionF[i];
	}
	memset(memoria, -1, sizeof memoria);
	int ans = fantasma(0,0);
	cout << ans << '\n';
	return 0;
}