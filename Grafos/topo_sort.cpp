#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vi ts; // global vector to store the toposort in reverse order

void topoDfs(int u, vi AdjList[], vb& visited) {
	visited[u] = true;
	for (int j = 0; j < (int)AdjList[u].size(); j++) { 
		int v = AdjList[u][j];

		if (visited[v] == false) {
			topoDfs(v,AdjList,visited);
		}
	} 
	ts.push_back(u);
}

int main()
{
	int v, e;

	cin >> v >> e;

	vi AdjList[v];
	vb visited(v,false);

	// Directed Acyclic Graph
	for(int i = 0; i < e; ++i) {
		int x, y;
		cin >> x >> y;
		AdjList[x].push_back(y);
	}

	for (int i=0;i<v;++i) {
		if(visited[i] == false)
			topoDfs(i,AdjList,visited);
	}

	for (int i = (int)ts.size() - 1; i >= 0; i--)
		printf("%d ", ts[i]);
	
	cout << '\n';
}