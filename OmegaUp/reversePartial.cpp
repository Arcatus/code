#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a, b;

	cin >> a >> b;

	string buffer;
	getline(cin, buffer);
	getline(cin, buffer);
	
	reverse( buffer.begin()+a, buffer.begin()+b+1);

	cout << buffer << '\n';

	return 0;
}