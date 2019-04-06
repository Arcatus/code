#include <iostream>
#include <vector>

using namespace std;

enum { VISITED, UNVISITED };

typedef vector<int> vi;

vi dfs_num(10,UNVISITED);

vi AdjList[9];

void dfs(int u) {

	cout << u << ' ';
	dfs_num[u] = VISITED;

	for (int j = 0; j < (int)AdjList[u].size(); j++) 
	{ 
		int v = AdjList[u][j];

		if (dfs_num[v] == UNVISITED){
			dfs(v);
		}
	} 
}

int main()
{
	int v, e;

	cin >> v >> e;

	for(int i = 0; i < e; ++i)
	{
		int x, y;
		cin >> x >> y;

		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}

	dfs(0);
	cout << '\n';
}