#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;

	cin >> n;

	string buffer;
	cin >> buffer;

	for (int i=0; i < buffer.length()-1; i++)
	{
		if ( buffer[i] > buffer[i+1] )
		{
			cout << "YES" << '\n';
			cout << i + 1 << " " << i + 2 << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
	return 0;
}