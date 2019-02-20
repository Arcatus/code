#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
	string s;

	cin >> s;

	int n = s.length();

	int sum = 0;

	for (int i = n - 1; i >= 0 ; i--)
	{
		sum += (s[i] - '0' ) % 10;
	}
	cout << sum << '\n';
}