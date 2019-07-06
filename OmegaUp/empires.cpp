#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct unidad // ~ 13 bytes
{
	char tipo;
	int iniciado;
	int terminado;
	int restantes;
};

bool operator<(const unidad& a, const unidad& b)
{
	return (a.terminado != b.terminado)?(a.terminado > b.terminado):(a.iniciado > b.iniciado);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int T, M;

	char U;

	priority_queue< unidad > lista_unidades;

	int simulated_time = 0;

	const int costo[] = { 25, 27, 30 };

	cin >> T >> U >> M;

	simulated_time = T;

	while ( n )
	{
		if ( !lista_unidades.empty() && simulated_time == lista_unidades.top().terminado ) {
			do{
				auto actual = lista_unidades.top();				
				cout << actual.terminado << " " << actual.tipo << '\n';

				lista_unidades.pop();
				if ( actual.restantes > 1 ) {
					lista_unidades.push(
						{ actual.tipo, actual.iniciado, actual.terminado+costo[actual.tipo-'A'], actual.restantes-1 } );
				}
			} while( !lista_unidades.empty() && simulated_time == lista_unidades.top().terminado );
		}

		if ( simulated_time == T ) {
			lista_unidades.push( { U, T, T+costo[U-'A'], M } );
			if ( n > 1) {
				cin >> T >> U >> M;
			} n-=1;
		}
		simulated_time+=1;
	}

	while( !lista_unidades.empty() )
	{
		while ( !lista_unidades.empty() && simulated_time == lista_unidades.top().terminado )
		{
			auto actual = lista_unidades.top();
			cout << actual.terminado << " " << actual.tipo << '\n';
			lista_unidades.pop();

			if ( actual.restantes > 1 ) {
				lista_unidades.push(
					{ actual.tipo, actual.iniciado, actual.terminado+costo[actual.tipo-'A'], actual.restantes-1 });
			}
		}
		simulated_time +=1;
	}
}