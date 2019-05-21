#include <iostream>
#include <utility>
#include <numeric>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;

int num_subsets;

int padre[100001];
int nivel[100001];
	
int findSet(int x) {	
	while (x != padre[x]) {		
		x = padre[x];
	}
	return x;
}

bool isSameSet(int i, int j) { 
	return findSet(i) == findSet(j); 
}

void unionSet(int i, int j) {	
	num_subsets-=1;

	int x = findSet(i);
	int y = findSet(j);

	if (nivel[x] > nivel[y]) {
		padre[y] = x;
	} else
	{
		padre[x] = y;
		if (nivel[x] == nivel[y]) nivel[x]++;
	}
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);	cout.tie(0);

	int casos, x, y, w, v, e, prop;

	cin >> casos;

	vector< pair<int, ii> > old_edges;
	vector< pair<int, ii> > new_edges;

	for (int z=0;z<casos;++z)
	{
		cin >> v >> e;

		iota( padre, padre+v, 0);
		memset( nivel, 1, sizeof nivel );

		num_subsets = v;

		old_edges.clear(), new_edges.clear();
		
		for (int i = 0; i < e; i++) {
			cin >> x >> y >> w;
			old_edges.push_back(make_pair(0, ii(x, y)));			
		}

		cin >> prop;

		for (int i = 0; i < prop ; i++) {
			cin >> x >> y >> w;
			new_edges.push_back(make_pair(w, ii(x, y)));			
		}
		
		sort(old_edges.begin(), old_edges.end());

		for (int i = 0; i < e && num_subsets > 1; ++i) {

			pair<int,ii> front = old_edges[i];

			if ( ! isSameSet( front.second.first, front.second.second ) ) {
				unionSet( front.second.first, front.second.second );
			}
		}

		if ( num_subsets == 1) {
			cout << "Thank you, Goodbye" <<'\n';
			continue;
		}

		long long costo = 0;

		sort(new_edges.begin(), new_edges.end());

		for (int i = 0; i < prop && num_subsets > 1; ++i) {

			pair<int,ii> front = new_edges[i];

			if ( ! isSameSet( front.second.first, front.second.second ) ) { 
				costo += front.first;
				unionSet( front.second.first, front.second.second );
			}
		}

		if ( num_subsets == 1 ) {
			cout << costo << '\n';
		} 
		else {
			cout << "You better hire someone else" << '\n';
		}
	}
	return 0;
}