#include <iostream>
//#include <cstdio>
//#include <string>
#include <algorithm>
#include <string>

using namespace std;

int i, j, x, y;
string a, b;

void find_intersecction()
{
	for (x = 0; x < a.length(); ++x)
	for (y = 0; y < b.length(); ++y)
		if ( a[x] == b[y]) return;
}

int main()
{
	cin >> a >> b;

	char matrix[ a.length()*b.length() ];
	std::fill(matrix,matrix+(a.length()*b.length()),'.');

	find_intersecction();

	for (i=0; i<a.length();++i)
	{
		matrix[y*a.length() + i] = a[i];
	}
	for (i=0; i<b.length();++i)
	{
		matrix[ i*a.length() + x ] = b[i];
	}

	for (i = 0; i < b.length(); ++i)
	{
		for (j = 0; j < a.length(); ++j)
		{
			cout << matrix[ a.length()*i + j ];
		}
		cout << '\n';	
	}
}