//#include <iostream>
//#include <cstdio>
//#include <string>
#include <stdio.h>
#include <algorithm>
//#include <string>
#include <map>
#include <utility>

short n, m;

void imprimeMatriz(const short *mat)
{
	for ( int i = 0; i < m ; ++i)
	{
		for ( int j = 0; j < n; ++j)
		{
			//cout << mat[i*n + j] << ' ';
			printf("%hi ",mat[i*n + j]);
		}
		printf("\n");
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

int main()
{

	//cin >> m >> n;
	scanf("%hi %hi", &m, &n);

	short* arr = new short[n*m];

	for ( int i = 0; i < m; ++i)
	for (int j = 0; j < n; ++j)
		//cin >> arr[ i*n + j ];
		scanf("%hi",&arr[ i*n + j ]);

	int k; 
	short state = 1;
	char opc;

	std::map< std::pair<short,char>, short> transitions;

	transitions.emplace( std::make_pair(  1, 'V' ) , 2);
	transitions.emplace( std::make_pair(  1, 'H' ) , 3);

	transitions.emplace( std::make_pair(  2, 'V' ) , 1);
	transitions.emplace( std::make_pair(  2, 'H' ) , 4);

	transitions.emplace( std::make_pair(  3, 'V' ) , 5);
	transitions.emplace( std::make_pair(  3, 'H' ) , 1);

	transitions.emplace( std::make_pair(  4, 'V' ) , 7);
	transitions.emplace( std::make_pair(  4, 'H' ) , 2);

	transitions.emplace( std::make_pair(  5, 'V' ) , 3);
	transitions.emplace( std::make_pair(  5, 'H' ) , 6);

	transitions.emplace( std::make_pair(  6, 'V' ) , 1);
	transitions.emplace( std::make_pair(  6, 'H' ) , 5);

	transitions.emplace( std::make_pair(  7, 'V' ) , 4);
	transitions.emplace( std::make_pair(  7, 'H' ) , 1);

	//cin >> k;
	scanf("%d",&k);

	for (int i = 0; i < k; ++i)
	{
		getchar();

		opc = getchar();

		state = transitions[ { state , opc } ];
	}

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
}
