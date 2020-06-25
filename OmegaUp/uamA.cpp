#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
float xUno;
float xDos;
float yUno;
float yDos;

float dist = 0.0f;

int main()
{
	int n;
	cin >> n;
	cin >> xUno >> yUno;

	float ini_a = xUno;
	float ini_b = yUno;

	for (int i = 1; i < n; i++)
	{
		cin >> xDos >> yDos;
		double r = hypot( xUno - xDos , yUno - yDos );
		dist += r;
		xUno = xDos;
		yUno = yDos;
	}

	double r = hypot( xDos - ini_a , yDos - ini_b );
	dist += r;
	cout << fixed << setprecision(2) << dist << '\n';
}