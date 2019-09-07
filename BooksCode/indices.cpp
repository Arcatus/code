#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	for (int i = n - 1; i > 0; --i)  {
		cout << i << " = " << (i << 1) << " + " << (i << 1 | 1) << '\n';
		//t[i] = t[i<<1] + t[i<<1|1];
	}
}