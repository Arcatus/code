#include <iostream>
#include <tuple>
#include <utility>
#include <numeric>
#include <cstring>
#include <algorithm>

using namespace std;

const int vertices = 8;

int lider[vertices];
int   tam[vertices];
	
int findSet(int x) {	
	if (lider[x] != x) {
      lider[x] = findSet(lider[x]);
   }
   return lider[x];
}

bool isSameSet(int i, int j) { 
	return findSet(i) == findSet(j); 
}

void unionSetBySize(int i, int j) {
   int x = findSet(i);
   int y = findSet(j);

   if (x != y) {
      if (tam[y] < tam[x]) {
         swap(x, y);
      }
      lider[x] = y;
      tam[y] += tam[x];
   }
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);

	int v, e;

	cin >> v >> e;

	iota(lider+1, lider+v+1, 1);
	
	fill(tam+1, tam+v+1, 1);

	vector< tuple<int,int,int> > edges;

	int x, y, w;

	int num_subsets = v;
	
	for (int i = 0; i < e; i++) {
		cin >> x >> y >> w;
		edges.push_back( { w, x, y } );
	}
	
	sort(edges.begin(), edges.end() );
	
	long long costo = 0;

	for (int i = 0; i < e; i++) {

		tie(w, x, y) = edges[i];

		if ( ! isSameSet(x, y) ) { 
			costo += w;
			unionSetBySize(x, y);
			num_subsets-=1;
		}
	}

	cout << "MST kruskal: " << costo <<" subsets: "<< num_subsets << '\n';

	if ( num_subsets == 1)
		cout << "Grafo Completo" << '\n';
	else
		cout << "Grafo Incompleto" << '\n';
	return 0;
}