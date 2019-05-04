#include <iostream>

using namespace std;

typedef long long ll;

int n;
ll contador=0LL;
int turno;

long long tablero[ 1<<36 ];

int impI[] = { 0, 1, 0, -1 };
int impJ[] = { 1, 0, -1, 0 };
int parDiagI[] = { -1, 1, 1, -1 };
int parDiagJ[] = { 1, 1, -1, -1 };
int r, c;

int check()
{
	for (int y=0;y<n;++y) 
	for (int x=0;x<n;++x) 
		if (!tablero[x][y]) return 0;
	return 1;
}

void recorrido( int i, int j )
{
	turno+=1;

	tablero[i][j] = true;

	//print();

	if (turno & 1) {
		for (int k=0;k<4;k++) {
			r = i+impI[k];
			c = j+impJ[k];	
			if ( c < 0 || r == n || r < 0 || c == n) {
				continue;
			}
			if ( ! tablero[r][c] ) {
				recorrido(r, c);
			}
		}
	} 
	else { 
		for (int k=0;k<4;k++) {
			r = i+parDiagI[k];
			c = j+parDiagJ[k];
			if ( c < 0 || r == n || r < 0 || c == n) {
				continue;
			}
			if ( ! tablero[r][c] ) {
				recorrido(r, c);
			}
		}
	}

	contador += check();

	tablero[i][j] = false;
	turno-=1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	recorrido(0,0);
	cout << contador << '\n';

	return 0;
}