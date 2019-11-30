#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
//#include <vector>
//#include <string>
#include <numeric>

using namespace std;

int lider[100000];
int   tam[100000];

int findSet(int x) {	
	if (lider[x] != x) {
      lider[x] = findSet(lider[x]);
   }
   return lider[x];
}

bool isSameSet(int i, int j) { 
	return findSet(i) == findSet(j); 
}

void unionSetBySize(int i, int j) {
   int x = findSet(i);
   int y = findSet(j);

   if (x != y) {
      if (tam[y] < tam[x]) {
         swap(x, y);
      }
      lider[x] = y;
      tam[y] += tam[x];
   }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m;

	cin >> n >> m;

	iota( lider, lider+n , 0);

	char opc;
	int x, y;
	for (int i=0;i<m;++i)
	{
		cin >> opc;
		cin >> x >> y;

		if (opc=='P') {
			if (isSameSet(x,y)) {
				cout << "1" << '\n';
			} 
			else {
				cout << "0" << '\n';
			}
		} else {
			if (!isSameSet(x,y)) {
				unionSetBySize( x, y );
			}
		}
	}

	return 0;
}