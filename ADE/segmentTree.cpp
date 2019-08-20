#include <iostream>

using namespace std;

int arr[100];
int segmentTree[4*100];

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

int update(int indice, int l, int r, int i, int v) {

	if ( l == r ) {
		arr[i] = v;
		segmentTree[indice] = v;
	} else {
		if ( l <= i && i <= (l+r)/2 ) {
			update(2*indice, l, (l+r)/2, i, v);
		} else {
			update(2*indice+1, (l+r)/2, r, i, v);
		}
		segmentTree[indice] = segmentTree[2*indice] + segmentTree[2*indice+1];
	}
}

int query(int indice, int l, int r, int inicio, int final) {

	if ( final < l || r < inicio ) {
		return 0;
	}
	if ( inicio <= l && r <= final ) {
		return segmentTree[indice];
	}
	int hijoIzquierdo = query(2*indice, l, (l+r)/2, inicio, final);
	int hijoDerecho   = query(2*indice+1, (l+r)/2 + 1,r, inicio, final);
	return hijoIzquierdo + hijoDerecho;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	createSegmentTree(1,0,n-1);

	int ans = query(1, 0, 0, 0, 0);

	cout << ans << '\n';

}