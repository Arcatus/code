#include <iostream>

using namespace std;

typedef long long ll;

int n;
int contador=0;
int turno;

bool tablero[6+1][6+1];

int impI[] = { 0, 1, 0, -1 };
int impJ[] = { 1, 0, -1, 0 };
int parDiagI[] = { -1, 1, 1, -1 };
int parDiagJ[] = { 1, 1, -1, -1 };
int r, c;

void recorrido( int i, int j )
{
	turno+=1;

	tablero[i][j] = true;

	if (turno & 1) {
		for (int k=0;k<4;k++) {
			r = i+impI[k];
			c = j+impJ[k];
			if ( c < 0 || r == n || r < 0 || c == n) continue;
			if ( ! tablero[r][c] ) recorrido(r, c);
		}
	} 
	else { 
		for (int k=0;k<4;k++) {
			r = i+parDiagI[k];
			c = j+parDiagJ[k];
			if ( c < 0 || r == n || r < 0 || c == n) continue;
			if ( ! tablero[r][c] ) recorrido(r, c);
		}
	}

	if (turno == n*n) contador++;

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