#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum { VISITED, UNVISITED };

const int TAM_ADJLIST = 9;

typedef vector<int> vi;

vi dfs_num(10,UNVISITED);

vi AdjList[TAM_ADJLIST]; int node_count;

void dfs(int u) {

	dfs_num[u] = VISITED;

	for (int j = 0; j < (int)AdjList[u].size(); j++) 
	{ 
		int v = AdjList[u][j];

		if (dfs_num[v] == UNVISITED){
			node_count++;
			dfs(v);
		}
	} 
}
int main()
{
	int v, e, cases;

	cin >> cases;

	for(int c = 0; c < cases; ++c)
	{
		node_count = 1;
		
		fill(dfs_num.begin(),dfs_num.end(),UNVISITED);

		for (int i = 0; i < TAM_ADJLIST; ++i)
			fill(AdjList[i].begin(),AdjList[i].end(),UNVISITED);

		cin >> v;
		for (int i = 0; i < v; ++i) {
			for (int j = 0; j < v; ++j) {
				cin >> e;
				if (e == 1){
					AdjList[i].push_back(j);
					AdjList[j].push_back(i);
				}
			}
		}

		cout << "Case " << c + 1 <<'\n';

		dfs(0);

		sort(dfs_num.begin(), dfs_num.end());

		putchar('+');
		for (int i = 0; i < node_count*2 - 1; ++i ) 
			putchar('-');
		printf("+\n");

		for (int k = 0; k < node_count; ++k) {
			if ( dfs_num[k] == VISITED )
				cout << "|Y";
			else
				cout << "|N";
		}printf("|\n+");
			
		for (int i = 0; i < node_count*2 - 1; ++i )
			putchar('-');
		printf("+\n");
	}
}

