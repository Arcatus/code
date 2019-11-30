#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int g = 1;
	char magnetAnt[2+1];

	cin >> magnetAnt;

	char magnetNew[2+1];

	for(int i=1; i<n; ++i) {
		cin >> magnetNew;
		if ( magnetAnt[1] == magnetNew[0] ) {
			g += 1;			
		}
		swap(magnetNew, magnetAnt);
	}
	cout << g << '\n';
}