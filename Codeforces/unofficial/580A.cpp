#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;
	
	int ant;
	cin >> ant;
	
	int maxi = 1;
	int contador = 1;
	int x;

	for(int i=1; i<n; ++i) {
		cin >> x;
		if ( ant > x ) {
			contador = 1;
		} else {
			contador += 1;
		}
		ant = x;
		maxi = max(maxi, contador);
	}
	cout << maxi << '\n';
}