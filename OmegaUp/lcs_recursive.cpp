#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string a, b;

vector<string> indices;

int lcs(int i, int j)
{
   if (i == a.size( ) || j == b.size( )) {
      return 0;
   }
   
   if (a[i] == b[j]) {
   	  string a = "{";
   	  a+=to_string(i);
   	  a+=", ";
   	  a+=to_string(j);
   	  a+="}";
   	  indices.push_back(a);

      return 1 + lcs(i + 1, j + 1);     
   }
   return max(lcs(i + 1, j), lcs(i, j + 1));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> a >> b;

	cout << lcs(0,0) << '\n';

	for(int i=0;i<indices.size();++i)
	{
		cout << indices[i] << '\n';
	}
	
	return 0;
}