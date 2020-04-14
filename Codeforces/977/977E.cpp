#include <iostream>
#include <vector>

using namespace std;

bool visitados[ 200000+1 ];
vector< int > adjList[ 200000+1 ];
vector< int > components[ 200000+1 ];

int conected_components = 0;

void dfs(int nodo_actual)
{
	visitados[ nodo_actual ] = true;
	for( int i=0; i< adjList[ nodo_actual ].size(); ++i ) {
		if ( !visitados[ adjList[ nodo_actual ][i] ] ) {
			dfs( adjList[ nodo_actual ][ i ] );
		}
	}
	components[conected_components].push_back( nodo_actual );
}

int main()
{
	int v, e;

	cin >> v >> e;

	int a, b;

	for (int i=0; i<e; ++i) {
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}

	for(int i=0; i<v; ++i) 
	{
		if ( !visitados[ i ] ) {
			dfs( i );
			conected_components += 1;
		}
	}
	
	int ans = 0;

	for(int i=0; i<conected_components; ++i) {
		bool itsok = true;
		for(int j=0; j<components[i].size(); ++j) {
			if ( adjList[ components[i][j] ].size() != 2 ) {
				itsok = false;
				break;
			}
		}
		if ( itsok ) ans++;
	}

	cout << ans << '\n';
}