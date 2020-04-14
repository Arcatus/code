#include <iostream>

using namespace std;

int n, v;

int viaje(int origen, int gasolina) {
	if ( origen == n ) {
		return 0;
	} else {
		if ( n - origen == gasolina - 1 ) {
			return 0;
		} else {
			if ( gasolina == 0 ) {
				return viaje(origen+1, min(v, n - origen)) + min(v, n - origen);
			} else {
				return viaje(origen+1, gasolina) + origen;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);


	cin >> n >> v;

	int costo = viaje(1,0);
	
	cout << costo << '\n';
}