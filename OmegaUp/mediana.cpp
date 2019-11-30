#include <iostream>
#include <algorithm>

using namespace std;

struct dato{
	int valor; 
	int posicion;
};

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	dato arr[n];
	for (int i=0; i<n; ++i) {
		cin >> arr[i].valor;
		arr[i].posicion = i;
	}

	sort(arr, arr+n, []( dato a, dato b ) {
		return a.valor < b.valor;
	} );

	cout << arr[n>>1].valor << " " << arr[n>>1].posicion << '\n';
}