#include <cstdio>
#include <string>

using namespace std;

int n, is_solution;
int contador=0;
int turno=0;

bool tablero[6*6 + 1];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int r, c;

void recorrido(char i, char j)
{
	turno+=1;
	tablero[i*n + j] = true;
	for (int k=0;k<4;++k) {
	r = i + dx[k];
	c = j + dy[k];
		if ( c < 0 || r == n || r < 0 || c == n) continue;
		if ( ! tablero[r*n + c] ) 
			recorrido(r, c);
	}

	if (turno == is_solution) contador+=1;

	tablero[i*n + j] = false;	

	turno-=1;
}

int main(int argc, char **argv)
{
	n = stoi( argv[1] );

	turno = 1;
	tablero[0] = true;

	is_solution = n*n;

	recorrido( 0, 1 );

	printf("%d\n",contador*2);

	return 0;
}