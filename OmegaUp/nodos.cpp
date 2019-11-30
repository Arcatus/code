#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int m; 
	cin >> m;

	vector<int> link;

	link.reserve(100+1);

	for (int i=0; i<100; ++i) {
		link[i] = -1;
	}

	int x, y;
	for (int i=0; i<m; ++i) {
		cin >> x >> y;
		link[x] = y;
	}
	int i = 0;
	
	while ( i >= 0 && i != n-1 ) {
		int ant = i;
		i = link[i];
		link[ant] = -1;
	}

	cout << (i == n-1)?1:0 << '\n';
}