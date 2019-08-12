#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int tiempo = 0;

	while( n <= m) {
		n *= 3;
		m *= 2;
		tiempo++;
	}	
	cout << tiempo << '\n';
}