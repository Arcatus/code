#include <iostream>

using namespace std;

typedef unsigned long long llu;

int main()
{
	llu n;
	cin >> n;

	llu num = n * (n+1LL);

	cout << (n * (n+1LL)) / 2LL << '\n';

	return 0;
}