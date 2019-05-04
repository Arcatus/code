#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int v, e;

	cin >> v >> e;
	int x, y;

	vector<int> AdjList[v];

	for (int i=0; i<e;++i)
	{
		cin >> x >> y;
		AdjList[x].push_back(y);
		AdjList[y].push_back(x);
	}	
	int inicial;

	cin >> inicial;

	vector<int> distancia(v);

	fill(distancia.begin(),distancia.end(),-1);

	distancia[inicial] = 0;

	queue<int> cola;
	cola.push(inicial);

	while( !cola.empty() )
	{
		int u = cola.front();
		cola.pop();

		cout << u << ' ';

		for(int i=0;i<(int)AdjList[u].size();++i)
		{
			int v = AdjList[u][i];

			if (distancia[v] == -1 ) {
				distancia[v] = distancia[u] + 1;
				cola.push(v);
			}
		}
	}
	cout <<'\n';
	int destino;
	cin >> destino;

	cout << distancia[destino] << '\n';

	return 0;
}