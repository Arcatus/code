#include <iostream>
#include <utility>
#include <unordered_map>

using namespace std;

int arr[100000+1], ans[100000+1], segmentTree[400000+1], n;

unordered_map<int,int> finder;

void createSegmentTree(int indice, int l, int r)
{
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

pair<int, int> query(int indice, int l, int r, int queryL, int queryR)
{
	if ( queryR < l || r < queryL ) {
		return { -1, -1 };
	}
	if ( queryL <= l && r <= queryR ) {
		return { segmentTree[indice], finder[segmentTree[indice]] };
	}
	auto [ hijoIzquierdo, indice_izquierdo ] = query(2*indice, l, (l+r)/2, queryL, queryR);
	auto [ hijoDerecho, indice_derecho] = query(2*indice+1, (l+r)/2 + 1,r, queryL, queryR);

	if ( hijoIzquierdo > hijoDerecho ) {
		return { hijoIzquierdo, indice_izquierdo }; 
	} else {
		return { hijoDerecho, indice_derecho };
	}
}

int construye_ciudad(int a, int b)
{
	if ( a < 1 || a > b || b > n  || a > n ) {
		return 0;
	}
	else if ( a == b ) {
		ans[a] = 1;
		return ans[a];
	}

	auto [ valor, posicion ] = query(1, 1, n, a, b);

	ans[ posicion ] = 1;
	int l = construye_ciudad(a,posicion-1);
	int r = construye_ciudad(posicion+1,b);

	ans[ posicion ] += l + r;

	return ans[ posicion ];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		finder.emplace( arr[i], i );
	}

	createSegmentTree(1,1,n);

	auto [ valor, posicion ] = query(1, 1, n, 1, n);

	ans[ posicion ] = construye_ciudad(1,posicion-1) + construye_ciudad(posicion+1,n) + 1;

	for(int i=1; i<=n; ++i) { cout << ans[i] << ' '; } cout << '\n';
}