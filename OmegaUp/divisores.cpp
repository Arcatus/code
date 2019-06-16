#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n;
	while(cin >> n)
	{
		if (n % 2 == 0) {
			cout << "2 ";
		}
		if (n % 3 == 0) {
			cout << "3 ";
		}
		if (n % 5 == 0) {
			cout << "5 ";
		}
		if (n % 7 == 0) {
			cout << "7 ";
		}
		cout << '\n';
	}

	return 0;
}