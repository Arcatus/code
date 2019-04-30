#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

#include <unordered_map>

using namespace std;
int n,m, a, b,i;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	unordered_map<int,int> dic;

	for (i = 0; i < n; ++i)
	{	
		cin >> a >> b;
		dic.emplace(a, b);
	}

	for (i = 0; i < m; ++i)
	{	
		cin >> a;
		if (dic.count(a) > 0) 
		{
			cout << dic[a] << '\n';
		}
		else
		{
			cout << "C?\n";
		}
	}
}