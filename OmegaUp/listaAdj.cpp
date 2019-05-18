#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int v, e;
	cin >> v >> e;

	vector<int> adjList[v];

	int x, y;
	for (int i=0;i<e;++i)
	{
		cin >> x >> y;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
	int tam=0;
	for (int i=0;i<v;++i)
	{
		tam = adjList[i].size();
		cout << i  << ": ";
		for (int j=0;j<tam-1; ++j)
		{
			cout << adjList[i][j] << "->";
		}
		if ( tam > 0 )
			cout << adjList[i][tam-1] << '\n';
		else cout <<'\n';
	}
	return 0;
}