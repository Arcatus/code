#include <iostream>
#include <cstdlib>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;

struct muro {
	int arqueros;
	int posicion;
	int defensa;
};

ll min(ll& a, int& b) {
	return a<b ? a:b;
}

bool operator<(const muro& a, const muro& b){
	
	if( a.arqueros == b.arqueros ) {
		return a.defensa > b.defensa;
	}	
	return a.arqueros > b.arqueros;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll k, inc;
	int n, r;

	cin >> n >> r >> k;

	int arr[n];

	fill(arr, arr+n, 0);
	
	cout << "Read data\n";
	
	int a_i;
	for(int i=0; i<n; ++i) {
		cin >> a_i;
		for( int j=max(0,i-r); j <= min(n-1, i+r) ; ++j ) {
			arr[j] += a_i;
		}
	}

	cout << "Fill queue\n";
	priority_queue<muro> linea_defensa;
	int defensa;
	for(int i=0; i<n; ++i) {
		defensa = 0;
		for( int j=max(0,i-r); j <= min(n-1, i+r) ; ++j ) {
			defensa += arr[j];
		}
		linea_defensa.push( muro{ arr[i], i, defensa - arr[i] } );
	}

	cout << "Algorithm\n";

	while( k>0 && !linea_defensa.empty() ) {
		
		vector<muro> actual;
		muro i = linea_defensa.top();
		actual.push_back( i );
		
		linea_defensa.pop();
		
		while ( !linea_defensa.empty() && 
				i.arqueros == linea_defensa.top().arqueros ) {
			actual.push_back( linea_defensa.top() );
			linea_defensa.pop();
		}
		if ( linea_defensa.empty() ) {
			break;
		}
		
		if ( k >= abs( linea_defensa.top().arqueros - actual[0].arqueros )*actual.size() ) {
			inc = abs( linea_defensa.top().arqueros - actual[0].arqueros );
		} else {
			inc = actual.size()/(2*r+1);
		}
		if ( inc == 0 ) {
			break;
		}		
		for ( muro l: actual ) {
			if ( k - inc < 0 ) break;
			int defensa = 0;
			for( int j=max(0,l.posicion-r); j <= min(n-1, l.posicion+r) ; ++j ) {
				arr[j] += inc;
				defensa += arr[j];
			}
			k -= inc;
			linea_defensa.push( muro{arr[l.posicion], l.posicion, defensa - arr[l.posicion] } );
		}
	}

	ll ans = LLONG_MAX;
	for( int i=0; i<n; ++i) ans = min(ans, arr[i]);

	cout << ans << '\n';
}