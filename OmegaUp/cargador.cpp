#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <fstream>

using namespace std;

typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	llu n, m;
	int a, b;
	cin >> n >> m >> a >> b;

	int i = 1;

	while( m*i < n)
	{
		i++;
	}

	llu x = (m*i - n)*a; 
	llu y = (n - m*(i-1))*b;

	cout << min(x,y)<< '\n';
}