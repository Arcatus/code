#include <iostream>
using namespace std;

int arr[100+1];
int segmentTree[4*100+1];
int lazy[4*100+1];

void createSegmentTree(int indice, int l, int r) {
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

void update(int indice, int l, int r, int i, int v) {
	
	if ( l == r ) {
		arr[i] = v;
		segmentTree[indice] = v;
	} else {
		if ( l <= i && i <= (l+r)/2 ) {
			update(2*indice, l, (l+r)/2, i, v);
		} else {
			update(2*indice+1, (l+r)/2+1, r, i, v);
		}
		segmentTree[indice] 
			= segmentTree[2*indice] + segmentTree[2*indice+1];
	}
}

void updateLazy(int indice, int l, int r, int queryL, int queryR, int v) {
	if ( lazy[indice] != 0 ) {
		segmentTree[indice] += (r-l+1)*lazy[indice];
		if ( l != r ) {
			lazy[2*indice] += lazy[indice];
			lazy[2*indice+1] += lazy[indice];
		}
		lazy[indice] = 0;
	}
	if ( l > r || l > queryR || r < queryL ) {
		return;
	}
	if ( l >= queryL && r <= queryR ) {
		segmentTree[indice] += (r-l+1)*v;
		if ( l != r ) {
			lazy[2*indice] += v;
			lazy[2*indice+1] += v;
		}
		return;
	}
	updateLazy(2*indice, l, (l+r)/2, queryL, queryR, v );
	updateLazy(2*indice+1, (l+r)/2 + 1, r, queryL, queryR, v );
	segmentTree[indice] 
		= segmentTree[2*indice] + segmentTree[2*indice+1];
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

int queryRange(int indice, int l, int r, int queryL, int queryR) {
	if ( l > r || l > queryR || r < queryL ) {
		return 0;
	}
	if ( lazy[indice] != 0 ) {
		segmentTree[indice] += (r-l+1)*lazy[indice];
		if ( l != r ) {
			lazy[2*indice] += lazy[indice];
			lazy[2*indice+1] += lazy[indice];
		}
		lazy[indice] = 0;
	}
	if ( l >= queryL && r <= r ) {
		return segmentTree[indice];
	}
	int hijoIzquierdo = queryRange(2*indice, l, (l+r)/2, queryL, queryR);
	int hijoDerecho = queryRange(2*indice+1, (l+r)/2, r, queryL, queryR);
	return hijoIzquierdo + hijoDerecho;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	createSegmentTree(1,1,n);

	int ans = queryRange(1, 1, n, 1, n );

	cout << ans << '\n';

	updateLazy(1, 1, n, 1, 5, 1);

	ans = queryRange(1, 1, n, 1, n );

	cout << ans << '\n';

	for(int i=0; i<4*n; ++i) {
		cout << segmentTree[i] << ' ';
	}
	cout << '\n';
}