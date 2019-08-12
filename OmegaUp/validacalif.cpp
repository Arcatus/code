#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	float f1=0.0f, f2=0.0f;

	int estado = 0;

	cout << fixed;
	cout.precision(2);
	
	while(cin >> f1) {
		if ( estado == 0 && 0.0f <= f1 && f1 <= 10.0f ) {
			estado = 1;
			f2 = f1;
		} else if ( estado == 1 && 0.0f <= f1 && f1 <= 10.0f ) {
			estado = 2;
			cout << "Promedio = " << (f1+f2)/2 << '\n';
		} else if ( estado == 2 ) {
			cout << "Nuevo calculo (1-Si 2-No)?\n";
			if ( 0.9999f <= f1 && f1 <= 1.0001f ) {
				estado = 0;
			} else if ( 1.9999f <= f1 && f1 <= 2.0001f ) {
				return 0;
			}
		} else {
			cout << "Calificacion invalida\n";
		}
	}
}