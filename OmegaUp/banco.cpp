#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	stack< string > mipila;
	queue< string > micola;

	int n, fila;
	string nombre;
	cin >> n;

	char opc;

	for (int i=0;i<n;++i)
	{
		cin >> opc;

		if (opc== 'E')
		{
			cin >> fila >> nombre;
			if ( fila & 1 )
			{
				micola.push(nombre);
			}
			else 
			{
				mipila.push(nombre);
			}
		}
		else
		{
			cin >> fila;

			if ( fila & 1 )
			{
				cout << micola.front() << '\n';
				micola.pop();
			}
			else 
			{
				cout <<  mipila.top() << '\n';
				mipila.pop();
			}
		}
	}
	return 0;
}