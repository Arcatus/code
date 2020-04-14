#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	int a_i, b_i, a_ant, b_ant;

	cin >> a_ant >> b_ant;
	
	int capacity = b_ant;

	for(int i=1; i<n; ++i) {	
		cin >> a_i >> b_i;
		capacity = max( capacity, b_ant - a_i + b_i);
		b_ant = b_ant - a_i + b_i;
	}
	cout << capacity << '\n';
}