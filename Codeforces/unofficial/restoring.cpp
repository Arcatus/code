#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int numbers[4];

	for(int i=0; i<4; ++i) {
		cin >> numbers[i];
	}
	sort( numbers, numbers+4 );

	for (int i=0; i<3; ++i) {
		cout << numbers[3]-numbers[i] << ' ';
	}
}