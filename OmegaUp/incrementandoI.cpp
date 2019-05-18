#include <iostream>

using namespace std;

int izq[1000001];
int der[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int inc;
	int n, m;
	int x, i, y;

	cin >> n >> m;

	for (i=0;i<m;++i) {
		cin >> x >> y;
		izq[x]+= 1;
		der[y]+= 1;
	}

	for (i=0;i<n;++i) {
		if (izq[i] | 0) inc += izq[i];
		if (der[i] | 0) inc -= der[i];
		cout << inc << ' ';
	}
	return 0;
}