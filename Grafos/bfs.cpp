#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
	int v, e;

	cin >> v >> e;

	vector<int> AdjList[v];

	int x, y;

	for (int i=0;i<e;++i)
	{
		cin >> x >> y;
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}	

	queue<int> bfs;

	int distance[v];

	bool visited[v];

	memset( visited, false, sizeof visited );

	cin >> x;

	visited[x] = true;
	distance[x] = 0;
	bfs.push(x);

	while( !bfs.empty() )
	{
		int s = bfs.front();
		bfs.pop();
		cout << s << ' ';

		for (auto u : AdjList[s] )
		{
			if ( !visited[u] ) {
				visited[u] = true;
				distance[u] = distance[s] + 1;
				bfs.push(u);
			}
		}
	}
	return 0;
}
