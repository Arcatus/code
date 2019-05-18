#include <iostream>

using namespace std;

int main()
{
	int x = 5328;	// 00000000000000000001010011010000

	cout << __builtin_clz(x) << "\n"; // 19
	cout << __builtin_ctz(x) << "\n"; // 4
	cout << __builtin_popcount(x) << "\n"; // 5
	cout << __builtin_parity(x) << "\n"; // 1

	return 0;
}