#pragma GCC optimize ("Ofast")

#include <iostream>
#include <algorithm>
using namespace std;

typedef int ll;

namespace io {
	void setIo() {
		ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	}
}
using namespace io;

ll arr[1000000+1], segmentTree[4000000+1];

void createSegmentTree(ll indice, ll l, ll r) {
	if ( l == r ) {
		segmentTree[indice] = arr[l];
		return;
	} else {
		createSegmentTree(2*indice, l,(l+r)/2);
		createSegmentTree(2*indice+1, (l+r)/2 + 1,r);
		segmentTree[indice]
			= segmentTree[2*indice] + segmentTree[2*indice+1];
	}
}

int query(int indice, int l, int r, int queryL, int queryR) {

	if ( queryR < l || r < queryL ) {
		return 0;
	}
	if ( queryL <= l && r <= queryR ) {
		return segmentTree[indice];
	}
	int hijoIzquierdo = query(2*indice, l, (l+r)/2, queryL, queryR);
	int hijoDerecho   = query(2*indice+1, (l+r)/2 + 1,r, queryL, queryR);

	return hijoIzquierdo + hijoDerecho;
}

int main() 
{	
	setIo(); ll n; cin >> n;

	for (ll i = 1; i <= n; ++i) cin >> arr[i];
	
	createSegmentTree(1,1,n);

	ll m; cin >> m;

	ll x, y, suma;
	while( m-- ) {
		cin >> x >> y;
		suma = query(1, 1, n, x+1, y+1);
		cout << suma << '\n';
	}
}