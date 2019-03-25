#include <iostream>

//#include <cstdio>
//#include <string>
#include <algorithm>
//#include <string>
#include <cstdlib>
#include <ctime>

int n, m;

using std::cin;
using std::cout;

void imprimeMatriz(const short *mat)
{
	for ( int i = 0; i < m ; ++i)
	{
		for ( int j = 0; j < n; ++j)
		{
			cout << mat[i*n + j] << ' ';
		}
		cout << '\n';
	}
}

void rotaV(short* mat)
{
	for (int i = 0; i < m/2 ; ++i)
	{
		for ( int j = 0; j < n; ++j )
		{	
			std::swap(mat[i*n + j ],mat[(m - 1 - i)*n + j ]);
		}
	}
}

void rotaH(short* mat)
{
	for (int i = 0; i < m ; ++i)
	{
		for ( int j = 0; j < n/2 ; ++j )
		{
			std::swap(mat[i*n + j ],mat[ i*n + n - 1 - j ]);
		}
	}	
}

short dfa_giros(const short& state, char opc)
{
	if ( state == 1 )
		return (opc=='V')?2:3;
	else if ( state == 2 )
		return (opc=='V')?1:4;
	else if ( state == 3 )
		return (opc=='V')?5:1;
	else if ( state == 4 )
		return (opc=='V')?7:2;
	else if ( state == 5 )
		return (opc=='V')?3:6;
	else if ( state == 6 )
		return (opc=='V')?1:5;
	else if ( state == 7 )
		return (opc=='V')?4:1;
}

int main()
{
	clock_t t1, t2, t3;

	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	cin >> m >> n;

	short arr[n*m];

	t1 = clock();

	for ( int i = 0; i < m; ++i)
	for (int j = 0; j < n; ++j)
		cin >> arr[ i*n + j ];

	t1 = clock() - t1;

	int k; 
	short state = 1;
	char opc;

	cin >> k;

	t2 = clock();

	for (int i = 0; i < k; ++i)
	{
		cin >> opc;
		state = dfa_giros(state,opc);
	}

	t2 = clock() - t2;

	t3 = clock();

	if ( state == 1 ){
		imprimeMatriz(arr);
	}
	else if ( state == 2 ){

		rotaV(arr);
		imprimeMatriz(arr);
	}
	else if ( state == 3 ){
		rotaH(arr);
		imprimeMatriz(arr);
	}
	else if ( state == 4 ){
		rotaV(arr);
		rotaH(arr);
		imprimeMatriz(arr);
	}
	else if ( state == 5 ){
		rotaH(arr);
		rotaV(arr);
		imprimeMatriz(arr);
	}
	else if ( state == 6 ){
		rotaH(arr);
		rotaV(arr);
		rotaH(arr);
		imprimeMatriz(arr);
	}
	else if ( state == 7 ){
		rotaV(arr);
		rotaH(arr);
		rotaV(arr);
		imprimeMatriz(arr);
	}

	t3 = clock() - t3;

	cout << "time for filling, clk:" << int(t1) << " " << (float(t1))/CLOCKS_PER_SEC << '\n';
	cout << "time in dfa, clk: " << int(t2) << " "<< (float(t2))/CLOCKS_PER_SEC << '\n';
	cout << "time in algorithm, clk: " << int(t3) <<" " << (float(t3))/CLOCKS_PER_SEC << '\n';
}
