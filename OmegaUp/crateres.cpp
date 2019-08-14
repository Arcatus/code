#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int tablero[500+1][500+1];
bool visitados[500+1][500+1];

int f, c;
int dx[] = { 1,  0, -1, 0 };
int dy[] = { 0, -1,  0, 1 };

int flood(const int& i, const int& j) {
	
	visitados[i][j] = true;

	int ans = tablero[i][j];
	for(int k=0; k<4; ++k ) {
	
		int y = i + dy[k];
		int x = j + dx[k];
		if ( 0 <= y && y < f && 0 <= x && x < c && 
				!visitados[y][x] && tablero[y][x] != 0 ) {
			ans += flood(y,x);
		}
	}
	return ans;
}

struct crater{
	int rocas;
	int numero;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> f >> c;

	for ( int i=0; i<f; ++i) {
		for ( int j=0; j<c; ++j) {
			cin >> tablero[i][j];
			visitados[i][j] = false;
		}
	}

	vector< crater* > ans;

	int conteo = 1;
	
	for ( int j=0; j<c; ++j) {
		for ( int i=0; i<f; ++i) {
			if ( !visitados[i][j] && tablero[i][j] > 0 ) {
				ans.emplace_back( new crater{ flood(i,j), conteo++ });
			}
		}
	}
	if ( ans.size() == 0 ) {
		cout << "0 0\n";
		return 0;
	}

	sort( ans.begin(), ans.end(), [](crater* a, crater* b) {
		if ( a->rocas == b->rocas ) {
			return a->numero < b->numero;
		}
		return a->rocas > b->rocas;
	} );

	cout << ans[0]->numero << " " << ans[0]->rocas << '\n';
}