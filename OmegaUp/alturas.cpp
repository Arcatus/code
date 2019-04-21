#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.precision(2);
	cout << fixed;

	int n;
	cin >> n;

	float l;
	for (int i = 0; i < n; ++i)
	{
		cin >> l;
		cout << sqrt( pow(l,2) - pow((l/2.0f),2) ) << '\n';
	}

	return 0;
}