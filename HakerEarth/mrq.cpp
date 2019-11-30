#include <iostream>
#include <algorithm>
#include <climits> 
#include <cmath>
using namespace std;

int arr[100005];
int segmentTree[400005];

void createSegmentTree(int indice, int l, int r) {
	if ( l == r ) {
		segmentTree[indice] = arr[l];
		return;
	} else {
		createSegmentTree(2*indice, l,(l+r)/2);
		createSegmentTree(2*indice+1, (l+r)/2 + 1,r);
		segmentTree[indice]
		= min(segmentTree[2*indice],segmentTree[2*indice+1]);
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
			update((2*indice)+1, ((l+r)/2)+1, r, i, v);
		}
		segmentTree[indice] 
			= min(segmentTree[2*indice], segmentTree[(2*indice)+1]);
	}
}

int query(int indice, int l, int r, int inicio, int final) {
	
	if ( final < l || r < inicio ) {
		return INT_MAX;
	}
	if ( inicio <= l && r <= final ) {
		return segmentTree[indice];
	}
	int hijoIzquierdo = query(2*indice, l, (l+r)/2, inicio, final);
	int hijoDerecho   = query((2*indice)+1, ((l+r)/2)+1,r, inicio, final);

	return min(hijoIzquierdo, hijoDerecho);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, q;

	cin >> n >> q;

	/* Segment tree is 1 indexed otherwise it could give the wrong answer */
	
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}

	createSegmentTree(1,1,n);
	
	int a, b; char opc;
	while( q-- ) {
		cin >> opc;
		if ( opc == 'q' ) {
			cin >> a >> b;
			int ans = query(1, 1, n, a, b);
			cout << ans << '\n';
		} else {
			cin >> a >> b;
			update(1, 1, n, a, b);
		}	
	}
}