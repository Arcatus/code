#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	cin >> a >> b >> c;

	if (a+b+c/3.0f < 6.0f )
	{
		cout << "0" << '\n';
	}
	else
	{
		cout << "1" << '\n';
	}

	return 0;
}