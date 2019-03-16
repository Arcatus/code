//#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>
//#include <utility>

struct interval
{
	short indice;
	int left;
	int right;
};

bool left_comparer(interval a, interval b)
{
	return a.left < b.left;
}

bool index_comparer(interval a, interval b)
{
	return a.indice < b.indice;
}

int main()
{
		
}