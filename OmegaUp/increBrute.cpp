#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>

using namespace std;

int arr[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int a, b;
	for (int i=0;i<m;++i)
	{
		cin >> a >> b;

		for (int j=a;j<b;++j)
			arr[j]++;
	}

	for (int i=0;i<n;++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}