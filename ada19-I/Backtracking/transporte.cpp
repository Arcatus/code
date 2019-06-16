#include <iostream>
#include <algorithm>

using namespace std;

int c, e, p;

struct solicitud
{
	int a, b, t, g;
};

solicitud pedidos[22+1];

int disponibilidad[7+1];

int ganancia_global, ganancia_local, ganancia_posible;
int maxima_ganancia, maximo_flujo;

void transporte(int k)
{
	if (k == p) {
		ganancia_global = max(ganancia_global, ganancia_local);
		return;
	}
	else
	{
		if ( ganancia_global == maxima_ganancia ) return;

		if ( ganancia_local + ganancia_posible > ganancia_global)
		{
			bool isPosible = true;
			for (int i=pedidos[k].a; i < pedidos[k].b; ++i )
			{
				if ( disponibilidad[i] + pedidos[k].t > c ) {
					isPosible = false;
					break;
				}
			}
			if ( isPosible )
			{
				for (int i=pedidos[k].a; i < pedidos[k].b; ++i )
				{
					disponibilidad[i] += pedidos[k].t;
				}

				ganancia_posible -= pedidos[k].g;
				ganancia_local += pedidos[k].g;
				transporte(k+1);
				ganancia_local -= pedidos[k].g;
				ganancia_posible += pedidos[k].g;
		
				for (int i=pedidos[k].a; i < pedidos[k].b; ++i )
				{
					disponibilidad[i] -= pedidos[k].t;
				}
			}
		}

		ganancia_posible -= pedidos[k].g;
		if ( ganancia_local + ganancia_posible > ganancia_global )
		{
			transporte(k+1);
		}
		ganancia_posible += pedidos[k].g;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	while(cin >> c >> e >> p)
	{
		maximo_flujo = 0;
		ganancia_global = 0;
		maxima_ganancia = 0;

		for (int i=0; i<p; ++i) {			
			cin >> pedidos[i].a >> pedidos[i].b >> pedidos[i].t;
			pedidos[i].g = (pedidos[i].b - pedidos[i].a) * pedidos[i].t;
			maximo_flujo += pedidos[i].t;
			maxima_ganancia += pedidos[i].g;
		}

		if ( maximo_flujo <= c ) {
			cout << maxima_ganancia << '\n';
			continue;
		}

		ganancia_posible = maxima_ganancia;
		
		sort( pedidos, pedidos + p, 
			[](solicitud a, solicitud b) { return a.g > b.g; });

		transporte(0);

		cout << ganancia_global << '\n';
	}
	return 0;
}