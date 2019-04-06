#include <iostream>
//#include <cstdio>
//#include <string>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	string lexic = "";

	char t;

	for (int i = 0; i < n; ++i)
	{
		cin >> t;
		lexic += t;
	}
	sort(lexic.begin(),lexic.end());
	
	for (int i = 1; i <= n; ++i)
	{
		cout << lexic[i-1];
		if (i%80==0)
			cout << '\n';
	}
}