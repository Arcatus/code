#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
	int v;
	cin >> v;
	vector<int> AdjList[v];
	int x, y;
	for (int i = 0; i < v - 1; ++i) {
		cin >> x >> y; x--; y--;
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}	
	queue<int> bfs;
	int color[v];
	bool visited[v];
	memset(visited, false, sizeof visited);
	x = 0;
	visited[x] = true;
	color[x] = 0;
	bfs.push(x);
	while( !bfs.empty() ) {
		int s = bfs.front();
		bfs.pop();
		for (auto u : AdjList[s] ) {
			if ( !visited[u] ) {
				visited[u] = true;
				color[u] = 1 - color[s];
				bfs.push(u);
			}
		}
	}
    ll black = 0, white = 0;
    for(int i = 0; i < v; ++i) {
        if (color[i]) {
            black++;
        } else {
            white++;
        }
    }
    cout << white*black - (v - 1) << '\n';
	return 0;
}
