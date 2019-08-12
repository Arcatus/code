#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int total = n*n;

	int negros = 4*n - 4 + 2*(n-2) - 1;

	cout << total - negros << " " << negros << '\n';
}