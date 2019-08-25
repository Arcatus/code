#include <iostream>
using namespace std;

int arr[1000000+1], segmentTree[4000000+1], lazy[4000000+1];

void createSegmentTree(int indice, int l, int r) {
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

void update(int indice, int l, int r, int i, int v) {
	
	if ( l == r ) {
		arr[i] += v;
		segmentTree[indice] += v;
	} else {
		if ( l <= i && i <= (l+r)/2 ) {
			update(2*indice, l, (l+r)/2, i, v);
		} else {
			update(2*indice+1, (l+r)/2+1, r, i, v);
		}
		segmentTree[indice] 
			= max(segmentTree[2*indice], segmentTree[2*indice+1]);
	}
}

int query(int indice, int l, int r, int queryL, int queryR) {

	if ( queryR < l || r < queryL ) {
		return -1;
	}
	if ( queryL <= l && r <= queryR ) {
		return segmentTree[indice];
	}
	int hijoIzquierdo = query(2*indice, l, (l+r)/2, queryL, queryR);
	int hijoDerecho   = query(2*indice+1, (l+r)/2 + 1,r, queryL, queryR);

	return max(hijoIzquierdo, hijoDerecho);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	createSegmentTree(1,1,n);

	int m;
	cin >> m;
	int x, y, inc;
	while( m-- ) {
		cin >> x >> y;
		inc = query(1, 1, n, x+1, y);
		//cout << "max in range " << inc << '\n';
		for(int i=x+1; i<=y; ++i) {
			if ( arr[i] == inc ) {
				update(1,1,n,i,1);
			}
		}
	}
	/*
	cout << "lazy\n";
	for(int i=1; i<=4*n;++i) {
		cout << lazy[i] << ' ';
	}
	cout << '\n';
	*/
	for(int i=1; i<=n; ++i) {
		cout << arr[i] << ' ';
	}
	/*
	cout << '\n';
	for(int i=1; i<=4*n;++i) {
		cout << segmentTree[i] << ' ';
	}
	*/
}