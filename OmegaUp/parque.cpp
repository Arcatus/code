#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int duracion, traslado;

	int ans = INT_MAX, espera, indice;

	for(int i=1; i<=n; ++i) {
		cin >> duracion >> traslado;
		
		int vuelta = traslado / duracion;

		if ( traslado%duracion != 0 ) {
			vuelta+=1;
		}
		
		espera = (vuelta*duracion) - traslado;		

		if ( espera + traslado < ans ) {
			ans = espera + traslado;
			indice = i;
		}
	}
	cout << indice << " " << ans << '\n';
}