//http://academicos.azc.uam.mx/franz/dda/2012p/t4.html

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, a, b;

int turno, costo_minimo;

bool visitado[20][20];

//vector< pair<int,int> > steps;

int entradas;

void alcanza(int f, int c)
{	
	if (f == n-1 && c == n-1)
	{
		if ( turno < costo_minimo ) 
		{
			/*for (int i=0;i<steps.size();++i)
			{
				cout << steps[i].first <<  " " << steps[i].second << '\n';
			}
			cout << "\n";*/
			costo_minimo = turno;
		}
	}

	int destinos[8][2] = {
		{f - a, c - b},
		{f - a, c + b},
		{f - b, c - a},
		{f - b, c + a},
		{f + a, c - b},
		{f + a, c + b},
		{f + b, c - a},
		{f + b, c + a}
	};

	for (int i=0;i<8;++i)
	{
		if ( 0 <= destinos[i][0] && destinos[i][0] < n &&  
			 0 <= destinos[i][1] && destinos[i][1] < n && 
			 !visitado[destinos[i][0]][destinos[i][1]] )
		{
			visitado[destinos[i][0]][destinos[i][1]] = true;
			turno+=1;
			if ( turno < costo_minimo )
			{
				//steps.push_back( { destinos[i][0], destinos[i][1] } );
				alcanza(destinos[i][0],destinos[i][1]);
				//steps.pop_back();
			}
			turno-=1;
			visitado[destinos[i][0]][destinos[i][1]] = false;
		}
	}	
}

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);

	cin >> n >> a >> b;

	costo_minimo = n*n;
	
	visitado[0][0] = true;

	alcanza(0,0);

	cout << costo_minimo << '\n';
}