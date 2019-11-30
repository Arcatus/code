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

ll arr[1000000+1], segmentTree[4000000+1], lazy[4000000+1];

void createSegmentTree(ll indice, ll l, ll r) {
	if ( l == r ) {
		segmentTree[indice] = arr[l];
		return;
	} else {
		createSegmentTree(2*indice, l,(l+r)/2);
		createSegmentTree(2*indice+1, (l+r)/2 + 1,r);
		segmentTree[indice]
			= max(segmentTree[2*indice], segmentTree[2*indice+1]);
	}
}

void updateLazy(ll indice, ll l, ll r, ll queryL, ll queryR, ll max_val) 
{	
	if ( lazy[indice] != 0 ) {		
		segmentTree[indice] += lazy[indice];
		if ( l != r ) {
			if ( segmentTree[2*indice] + lazy[2*indice] == max_val ) {
				lazy[2*indice] += lazy[indice];
			}
			if ( segmentTree[2*indice+1] + lazy[2*indice+1] == max_val ) {
				lazy[2*indice+1] += lazy[indice];
			}
		}
		lazy[indice] = 0;
	}
	if ( l > r || l > queryR || r < queryL ) {
		return;
	}
	if ( l >= queryL && r <= queryR ) {
		if( segmentTree[indice] == max_val ) {
			
			segmentTree[indice] += 1;
			if ( l != r ) {
				if ( segmentTree[2*indice] + lazy[2*indice] == max_val ) {
					lazy[2*indice] += 1;
				}
				if ( segmentTree[2*indice+1] + lazy[2*indice+1] == max_val ) {
					lazy[2*indice+1] += 1;
				}				
			}
		}
		return;
	}
	updateLazy(2*indice, l, (l+r)/2, queryL, queryR, max_val );
	updateLazy(2*indice+1, (l+r)/2 + 1, r, queryL, queryR, max_val );

	segmentTree[indice] 
		= max(segmentTree[2*indice], segmentTree[2*indice+1]);
}

ll queryRange(ll indice, ll l, ll r, ll queryL, ll queryR) {
	if ( lazy[indice] != 0 ) {
		ll backtrack = segmentTree[indice];
		segmentTree[indice] += lazy[indice];
		if ( l != r ) {
			if ( segmentTree[2*indice] + lazy[2*indice] == backtrack ) {
				lazy[2*indice] += lazy[indice];
			}
			if ( segmentTree[2*indice+1] + lazy[2*indice+1] == backtrack ) {
				lazy[2*indice+1] += lazy[indice];
			}
		}
		lazy[indice] = 0;
	}
	if ( l > r || l > queryR || r < queryL ) {
		return -1;
	}
	if ( queryL <= l && r <= queryR ) {
		return segmentTree[indice];
	}
	ll hijoIzquierdo = queryRange(2*indice, l, (l+r)/2, queryL, queryR);
	ll hijoDerecho   = queryRange(2*indice+1, (l+r)/2+1, r, queryL, queryR);
	return max(hijoIzquierdo, hijoDerecho);
}

void print(ll indice, ll l, ll r) {
	
	if ( lazy[indice] != 0 ) {
		ll backtrack = segmentTree[indice];
		segmentTree[indice] += lazy[indice];
		if ( l != r ) {
			if ( segmentTree[2*indice] + lazy[2*indice] == backtrack ) {
				lazy[2*indice] += lazy[indice];
			}
			if ( segmentTree[2*indice+1] + lazy[2*indice+1] == backtrack ) {
				lazy[2*indice+1] += lazy[indice];
			}
		}
		lazy[indice] = 0;
	}
	if ( l == r ) {
		cout << segmentTree[indice] << ' ';
		return;
	}
	print(2*indice, l, (l+r)/2);
	print(2*indice+1, (l+r)/2+1, r);
}

int main() 
{	
	setIo(); ll n; cin >> n;

	for (ll i = 1; i <= n; ++i) cin >> arr[i];
	
	createSegmentTree(1,1,n);

	ll m; cin >> m;

	ll x, y, inc;
	while( m-- ) {
		cin >> x >> y;
		inc = queryRange(1, 1, n, x+1, y);
		updateLazy(1, 1, n, x+1, y, inc);
	}
	print(1, 1, n);
}