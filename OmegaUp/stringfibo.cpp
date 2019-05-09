#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<string> fib(15+1);

	cin >> fib[1];
	cin >> fib[2];

	int n;
	cin >> n;
	for (int i=3; i<=n;++i)
	{
		fib[i] = fib[i-2] + fib[i-1];
	}
	cout << fib[n] <<'\n';

	return 0;
}