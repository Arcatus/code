#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef unsigned long long ll;

struct nodo{
	int deg3;
	int deg2;
	ll valor;
};

int getDeg3(ll i)
{
	int k=0;
	while( i % 3 == 0 ) {
		i = i / 3;
		k++;
	}
	return k;
}

int getDeg2(ll i)
{
	int k=0;
	while( i % 2 == 0 ) {
		i = i / 2;
		k++;
	}
	return k;
}

int main()
{
	int n;

	cin >> n;

	nodo arr[n];

	for(int i=0; i<n; ++i) {
		cin >> arr[i].valor;
		arr[i].deg3 = getDeg3( arr[i].valor );
		arr[i].deg2 = getDeg2( arr[i].valor );
		//cerr << " val "<< arr[i].valor << " deg 3 " << arr[i].deg3 << " deg2 " << arr[i].deg2 << '\n';
	}
	sort(arr, arr+n, [](nodo a, nodo b) {
			if ( a.deg3 == b.deg3 ) {
				return a.deg2 < b.deg2;
			}	
			else return a.deg3 > b.deg3;
	} );

	for( auto i: arr ) {
		cout << i.valor << ' ';
	}
	cout << '\n';
}