#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	int t;
	cin >> n;

	char opc[13];

	list<int> milista;

	vector<int> derecha[10];
	vector<int> izquierda[10];

	int k = 0, l = 0;

	for (int i=0;i<n;++i)
	{
		cin >> opc;
		cin >> t;

		if (opc[0] == 'A') // AGREGAR
		{
			if (opc[7] == 'I') {
				milista.push_front(t);
				izquierda[t].push_back(k);
				k+=1;
			}
			else 
			{
				milista.push_back(t);
				derecha[t].push_back(l);
				l+=1;
			}
		}
		else // QUITAR
		{	
			// buscando la ocurrencia empezando del lado izquierdo
			bool completed = true;
			if (opc[6] == 'P') {
				if ( izquierda[t].size() > 0 ) {
					for (int i=izquierda[t].size()-1; i>=0; --i)
					{
						if ( izquierda[t][i] != -1 ) {
							auto it = milista.begin(); 
							advance(it, k - izquierda[t][i] - 1 );
							izquierda[t][i] = -1;
							*it = -1;
							completed = false;
							break;
						}
					}
				}
				if ( completed )
				{
					for (int i=0; i<derecha[t].size(); ++i)
					{
						if ( derecha[t][i] != -1 ) {
							auto it = milista.begin();
							advance( it, derecha[t][i] + k );
							derecha[t][i] = -1;
							*it = -1;
							break;
						}
					}
				}
			}
			else // buscando la ocurrencia empezando del lado derecho
			{
				if ( derecha[t].size() > 0 ) {
					for (int i=derecha[t].size()-1; i>=0; --i)
					{
						if ( derecha[t][i] != -1 ) {
							auto it = milista.begin();
							advance( it, k + derecha[t][i] );
							derecha[t][i] = -1;
							*it = -1;
							completed = false;
							break;
						}
					}
				}
				if ( completed )
				{
					for (int i=0; i<izquierda[t].size(); ++i)
					{
						if ( izquierda[t][i] != -1 ) {
							auto it = milista.begin();
							advance(it, k - izquierda[t][i] - 1);
							izquierda[t][i] = -1;
							*it = -1;
							break;
						}
					}
				}
			}
		}
	}	

	for (auto i: milista)
	{		
		if (i != -1) cout << i << ' ';
	}
	cout << '\n';

	return 0;
}