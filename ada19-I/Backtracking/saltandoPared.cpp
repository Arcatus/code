#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> s;
vector<int> ans(1000);

int c, l, d;
int contador;
int costo_global = INT_MAX, costo_local=0;

void saltos(int posicion)
{
	cerr << posicion << '\n';
	if ( posicion == d )
	{
		if ( costo_local < costo_global )
		{
			/*for (int i=0;i<costo_local;++i) {
				ans[i] = s[i];
			}*/
			costo_global = costo_local;
		}
	}
	else 
	{
		int destinos[] = { c, l, -l, -c };

		for (int i=0;i<4;++i)
		{
			if ( (posicion+destinos[i]) < 0 || d < (posicion+destinos[i]) ) continue;
			
			if ( costo_local < costo_global )
			{
				costo_local+=1;
				//s.push_back(destinos[i]);
				saltos(posicion+destinos[i]);
				//s.pop_back();
				costo_local-=1;
			}
			
		}
	}
}

int main()
{
	cin >> c >> l >> d;

	saltos(0);

	cout << costo_global << '\n';

	for (int i=0;i<costo_global;++i)
	{
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}