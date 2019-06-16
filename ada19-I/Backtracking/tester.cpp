#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int c, e, p, maxima_ganancia;

struct solicitud
{
	int a, b, t, g;
};

solicitud pedidos[22 + 1];

int disponibilidad[7+1];

int ganancia_global, ganancia_local, ganancia_posible;

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
				
				ganancia_local += pedidos[k].g;
				transporte(k+1);
				ganancia_local -= pedidos[k].g;
		
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

	while(scanf("%d %d %d",&c,&e,&p)==3)
	{
		if (c==0&&e==0&&p==0) break;
		
		ganancia_global = 0;
		maxima_ganancia = 0;

		for (int i=0; i<p; ++i) {
			scanf("%d %d %d",&pedidos[i].a,&pedidos[i].b,&pedidos[i].t);
			pedidos[i].g = (pedidos[i].b - pedidos[i].a) * pedidos[i].t;
			maxima_ganancia += pedidos[i].g;
		}

		ganancia_posible = maxima_ganancia;
		/*
		sort( pedidos, pedidos + p, 
			[](solicitud a, solicitud b) { return a.g > b.g; });
		*/
		transporte(0);

		printf("%d\n",ganancia_global);
	}
	return 0;
}