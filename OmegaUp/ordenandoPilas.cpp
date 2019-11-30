#include <iostream>

using namespace std;

struct num{
	int val;
	bool side; // true for a but b false
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int na, nb; 

	cin >> na >> nb;

	int n = na + nb;

	num *arr[n+1];

	int *base_pila_A = nullptr, *base_pila_B = nullptr;
	int *tope_pila_A = nullptr, *tope_pila_B = nullptr;

	int x;
	for(int i=0; i<na; ++i) {
		cin >> x;
		arr[x] = new int{x};
		cout << *arr[x] << '\n';
		if( i == 0) {
			base_pila_A = arr[x];
		}
		if( i == na-1) {
			tope_pila_A = arr[x];
		}
	}	

	for(int i=0; i<nb; ++i) {
		cin >> x;
		arr[x] = new int{x};
		cout << *arr[x] << '\n';
		if( i == 0) {
			base_pila_B = arr[x];
		}
		if( i == nb-1) {
			tope_pila_B = arr[x];
		}
	}
	/*
	cout << "base_pila_A " << *base_pila_A << " tope_pila_A " << *tope_pila_A << '\n';
	cout << "base_pila_B " << *base_pila_B << " tope_pila_B " << *tope_pila_B << '\n';
	*/
	
}