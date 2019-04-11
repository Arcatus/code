#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

void dfs(int u, vi AdjList[], vb& visited) {
	visited[u] = true;
	cout << u << ' ';
	for (int j = 0; j < (int)AdjList[u].size(); j++) { 
		int v = AdjList[u][j];

		if (visited[v] == false){
			dfs(v,AdjList,visited);
		}
	} 
}

int main()
{
	int v, e;

	cin >> v >> e;

	vi AdjList[v];
	vb visited(v,false);

	for(int i = 0; i < e; ++i) {
		int x, y;
		cin >> x >> y;
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}
	int inicial;
	cin >> inicial;
	dfs(inicial,AdjList,visited);
	cout << '\n';
}