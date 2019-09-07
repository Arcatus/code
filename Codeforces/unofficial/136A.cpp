#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int to[n+1];
	int gift;
	for(int i=1; i<=n; ++i) {
		cin >> gift;
		to[gift] = i;
	}
	for(int i=1; i<=n; ++i) {
		cout << to[i] << ' ';
	}
}