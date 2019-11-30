#include <iostream>
#include <algorithm>

using namespace std;

struct nodo
{
	int valor;
	nodo* atras;
	nodo* siguiente;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	nodo* arr[n+1];
	arr[0] = new nodo{ 0, nullptr, nullptr };
	for(int i=1; i<n; ++i) {
		arr[i] = new nodo{ i, arr[i-1], nullptr };
		arr[i-1]->siguiente = arr[i];
	}	

	nodo* inicio = arr[0];
	int valor_inicial = 0;

	int v, x;
	char opc;

	for(int i=0; i<m; ++i) {
		cin >> v >> opc >> x;		
		
		if ( arr[v]->atras != nullptr ) {
			arr[v]->atras->siguiente = arr[v]->siguiente;
		}
		if( arr[v]->siguiente != nullptr ) {
			arr[v]->siguiente->atras = arr[v]->atras;
		}

		if ( opc == 'A') {
			if ( valor_inicial == v ) {
				valor_inicial = arr[v]->siguiente->valor;
				inicio = arr[v]->siguiente;
			}
			if ( arr[x]->atras != nullptr ) {
				arr[x]->atras->siguiente = arr[v];
			}
			arr[v]->atras = arr[x]->atras;
			arr[x]->atras = arr[v];
			arr[v]->siguiente = arr[x];
			if ( valor_inicial == x ) {
				valor_inicial = v;
				inicio = arr[v];
			}
		} else {
			if ( valor_inicial == v ) {
				valor_inicial = arr[v]->siguiente->valor;
				inicio = arr[v]->siguiente;
			}
			if ( arr[x]->siguiente != nullptr ) {
				arr[x]->siguiente->atras = arr[v];
			}
			arr[v]->atras = arr[x];
			arr[v]->siguiente = arr[x]->siguiente;
			arr[x]->siguiente = arr[v];
		}
	}
	
	while ( inicio ) {
		cout << inicio->valor << ' ';
		inicio = inicio->siguiente;
	}
	cout << '\n';
}