#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>
#include <vector>
//#include <string>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

char arr[128];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	char letra;
	while(cin >> letra) {	
		arr[letra]++;
	}
	vector<int> count;

	count.push_back( arr[109] );
	count.push_back( arr[105] );
	count.push_back( arr[103] );
	count.push_back( arr[117] );
	count.push_back( arr[101] );
	count.push_back( arr[108] );

	sort( count.begin(), count.end() );

	cout << count[0] << '\n';

	return 0;
}