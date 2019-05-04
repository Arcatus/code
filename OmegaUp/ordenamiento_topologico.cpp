#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

vector<int> AdjList[5];
vector<bool> visited(5,false);
vector<int> ts;

void topoSort(int u)
{
	visited[u] = true;
	for (int i=0;i<(int)AdjList[u].size();++i)
	{
		int v = AdjList[u][i];
		if (visited[v]==false)
			topoSort(v);
	}	
	ts.push_back(u);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v, e;

	cin >> v >> e;
	int x, y;
	for (int i=0;i<e;++i) // DAG
	{	 
		cin >> x >> y;
		AdjList[x].push_back(y);	
	}

	for (int i=0;i<v;++i)
	{
		if ( visited[i]==false )
			topoSort(i);
	}

	reverse( ts.begin(),ts.end() );
	for (auto& i: ts)
	{	
		cout << i << ' ';
	}
	cout << '\n';

	return 0;
}