#include <iostream>

using namespace std;


int n;
int count=0;
int column[15+1];
int diag1[15+1];
int diag2[15+1];

void search(int y) {
	if (y == n) {
		count++;
		return;
	}
	for (int x = 0; x < n; x++) {
		
		if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;

		column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;

		search(y+1);

		column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
	}
}

int main()
{
	cin >> n;

	search(0);

	cout << count << '\n';

	return 0;
}