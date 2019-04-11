#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int e, v, x, y;

	cin >> v >> e;

	queue<int> q;
	vector<int> AdjList[v];

	vector<int> d(v, -1);

	for(int i = 0; i < e; ++i)
	{
		cin >> x >> y;

		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}
	
	int inicial;	
	cin >> inicial;

	d[inicial] = 0;
	q.push(inicial);

	while (!q.empty()) {

		int u = q.front(); q.pop();

		cout << u << ' ';

		for (int j = 0; j < (int)AdjList[u].size(); j++) {
			
			int v = AdjList[u][j];

			if (d[v] == -1) {
				
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
	cout << '\n';

	int distancia_minima;
	cin >> distancia_minima;

	cout << d[distancia_minima] << '\n';
}