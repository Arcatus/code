#include <iostream>

using namespace std;

int n;

int blacks[9+1];

int mat[9][9];

int varianza[20];

long long colorea(int fila, int columna)
{
	if ( columna == n ) {
		int contador=0;
		for (int i=0; i<n; ++i) {
			for (int j=0; j<n; ++j) {
				if (mat[i][j]==1) contador+=1;
				//cerr << mat[i][j] << ' ';
			}// cerr << '\n';
		}
		varianza[contador]+=1;
		//cerr << "...........\n";
		return 1;
	}
	long long res = 0;
	
	int is_enough = blacks[columna+1] + blacks[columna];

	if ( is_enough == n ) {

		res += colorea(0, columna+1);
	}
	else if (is_enough == 2*n)
	{
		return 1;
	} 
	else {
		if ( fila+1 == n ) {
			
			res += colorea(0, columna+1);

			blacks[columna+1]+=1;
			mat[fila][columna] = 1;
			res += colorea(0, columna+1);
			mat[fila][columna] = 0;
			blacks[columna+1]-=1;
		}
		else {
			res += colorea(fila + 1, columna);

			mat[fila][columna] = 1;
			blacks[columna+1]+=1;
			res += colorea( fila + 1, columna);
			blacks[columna+1]-=1;
			mat[fila][columna] = 0;
		}
	}
	return res;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	n = stoi(argv[1]);

	cout << colorea(0,0) << '\n';

	for (int i=0;i<20;++i)
		cout << varianza[i] << ' ';
	cout << '\n';

	return 0;
}