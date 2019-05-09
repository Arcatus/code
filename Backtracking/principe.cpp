#include <cstdio>

int n;
int contador=0;
int turno=0;

bool tablero[6+1][6+1];

int impI[] = { 0, 1, 0, -1 };
int impJ[] = { 1, 0, -1, 0 };
int r, c;

void recorrido( int i, int j )
{
	turno+=1;

	tablero[i][j] = true;
	for (int k=0;k<4;k++) {
		r = i+impI[k];
		c = j+impJ[k];
		if ( c < 0 || r == n || r < 0 || c == n) continue;
		if ( ! tablero[r][c] ) recorrido(r, c);
	}

	if (turno == n*n) contador++;

	tablero[i][j] = false;
	turno-=1;
}

int main()
{
	scanf("%d",&n);
	recorrido(0,0);
	printf("%d\n",contador);

	return 0;
}