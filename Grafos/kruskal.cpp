#include <iostream>
#include <tuple>
#include <utility>
#include <numeric>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

typedef pair<int,int> ii;

const int vertices = 8;

int num_subsets;
int padre[vertices];
int nivel[vertices];
	
int findSet(int x) {	
	while (x != padre[x]) x = padre[x];
	return x;
}

bool isSameSet(int i, int j) { 
	return findSet(i) == findSet(j); 
}

void unionSet(int i, int j) {
	//if (!isSameSet(i, j)) {  // redundante
	num_subsets-=1;

	int x = findSet(i);
	int y = findSet(j);

	if ( nivel[x] > nivel[y] ) {
		padre[y] = x;
	} else {
		padre[x] = y;
		if (nivel[x] == nivel[y]) nivel[y]++;
	}
	//}
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v, e;

	cin >> v >> e;

	iota( padre, padre+v, 0);

	vector< tuple<int,int,int> > edges;

	int x, y, w;

	num_subsets = v;
	
	for (int i = 0; i < e; i++) {
		cin >> x >> y >> w;
		edges.push_back( { w, x, y } );
	}
	
	sort(edges.begin(), edges.end());
	
	long long costo = 0;

	for (int i = 0; i < e; i++) {
		cout << "[ "; for (auto& i: padre) cout << i << ' ';  cout << "]\n";
		cout << "[ "; for (auto& i: nivel) cout << i << ' ';  cout << "]\n";

		tie(w, x, y) = edges[i];

		if ( ! isSameSet(x, y) ) { 
			costo += w;
			unionSet(x, y);
		}
	}
	cout << "[ "; for (auto& i: padre) cout << i << ' ';  cout << "]\n";
	cout << "[ "; for (auto& i: nivel) cout << i << ' ';  cout << "]\n";

	cout << "MST kruskal: " << costo <<" subsets: "<< num_subsets << '\n';

	if ( num_subsets == 1)
		cout << "Grafo Completo" << '\n';
	else
		cout << "Grafo Incompleto" << '\n';
	return 0;
}