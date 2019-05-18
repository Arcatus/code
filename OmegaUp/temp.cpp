#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
#include <string>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);	
	
	int n, k, t;
	cin >> n >> k;
	int contador=0;
	for (int i=0; i<n;++i)
	{
		cin >> t;
		if (t >= k)
		{
			contador+=1;
		}
	}
	printf("%d\n",contador);

	return 0;
}