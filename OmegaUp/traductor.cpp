#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

#include <map>

using namespace std;

int main()
{
	int n,m, a, b;
	scanf("%d %d",&n,&m);

	map<int,int> dic;

	for (int i = 0; i < n; ++i)
	{	
		scanf("%d %d",&a,&b);
		dic.emplace( a, b);
	}

	for (int i = 0; i < m; ++i)
	{	
		scanf("%d",&a);
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