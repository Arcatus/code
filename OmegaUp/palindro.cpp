#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string buffer;

	cin >> buffer;

	if (buffer == string(buffer.rbegin(),buffer.rend())) cout << "Si";
	else cout << "No";
	return 0;
}