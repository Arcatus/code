#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int v, e, x, y;
	cin >> v >> e;

	vector<int> AdjList[v];

	for(int i = 0; i < e; ++i)
	{
		cin >> x >> y;

		AdjList[x].push_back(y);
	}

	int inicial;	
	cin >> inicial;

	queue<int> q; q.push(inicial);

	vector<int> color(v, -1); 

	color[inicial] = 0;

	bool isBipartite = true; // addition of one boolean flag, initially true

	while (!q.empty() & isBipartite) { // similar to the original BFS routine

		int u = q.front(); q.pop();
		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			int actual = AdjList[u][j];

			if (color[actual] == -1) {
				// but, instead of recording distance,
				color[actual] = 1 - color[u]; // we just record two colors {0, 1}
				q.push(actual); 

			} else if (color[actual] == color[u]) { // u & v.first has same color
				isBipartite = false; break; 
			} 
		}
	}			// we have a coloring conflict
	if ( isBipartite )
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';

	return 0;
}
