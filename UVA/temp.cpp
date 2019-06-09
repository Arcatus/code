#include <iostream>
#include <vector>

using namespace std;

vector<int> AdjList[10];

vector<bool> visited(10,false);

void dfs(int u)
{	
	visited[u] = true;

	cout << u << ' ';

	for(int j=0;j<(int)AdjList[u].size();++j) {
		int v = AdjList[u][j];
		if (visited[v] == false ) {
			dfs(v);
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v, e;
	cin >> v >> e;

	int x, y;
	for (int i=0;i<e;++i)
	{
		cin >> x >> y;
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}

	dfs(1);

	return 0;
}