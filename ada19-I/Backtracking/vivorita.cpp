#include <iostream>
#include <cstdlib>

using namespace std;

int n;
int arr[25+1];

int vivora(int i)
{
	int res = 0;
	if ( abs( arr[0] - arr[i-1] ) > n-i ) return 0;
	if ( i == n-1 ) return 1;

	for (int d=0; d<=9; ++d) {
		arr[i] = d;
		if (i == 0 || abs( arr[i] - arr[i-1] ) == 1 )
		{
			res += vivora(i+1);
		}
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;

	if (n == 1) {
		cout << "10" << '\n';
	}	
	else if (n % 2 == 0) {
		cout << "0" << '\n';
	}
	else
	{
		cout << vivora(0) << '\n';
	}

	return 0;
}