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

bool a[5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	a[n] = true;

	int m;
	cin >> m;
	int t;
	for (int i=0;i<m;++i)
	{
		cin >> t;
		switch(t)
		{
			case 1:
			{
				swap(a[1],a[2]); break;
			}
			case 2:
			{
				swap(a[1],a[3]); break;
			}
			case 3:
			{
				swap(a[1],a[4]); break;
			}
			case 4:
			{
				swap(a[2],a[3]); break;
			}
			case 5:
			{
				swap(a[2],a[4]); break;
			}
			case 6:
			{
				swap(a[3],a[4]);
			}
		}
	}
	for (int i=1;i<=4;++i)
	{
		if ( a[i] == true ) {
			printf("%d\n",i);
			break;
		}
	}

	return 0;
}