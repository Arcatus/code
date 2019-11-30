#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int n;

int lider[100000+1];
int tam[100000+1];

int find(int a) {
	return a == lider[a] ? a : lider[a] = find(lider[a]);
}

bool isSameSet(int a, int b) {
	return find(a) == find(b);
}

void unionBySize(int a, int b) {

	int x = find(a);
	int y = find(b);
	if ( x!=y ) {
		if ( tam[x] > tam[y] ) swap(x,y);
		lider[x] = y;
		tam[y] += tam[x];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	iota(lider, lider+n, 0);
	fill(tam, tam+n, 1);

	char opc; int a, b;
	for(int i=0; i<m; ++i) {
		cin >> opc;
		cin >> a >> b;
		if( opc== 'U') {
			unionBySize(a,b);
		} else {
			cout << isSameSet(a,b) << '\n';
		}
	}
}