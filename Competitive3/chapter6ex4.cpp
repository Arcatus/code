#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string buffer;

	getline(cin,buffer);

	stringstream line(buffer);

	vector<string> tokens;

	while(getline(line,buffer,' '))
	{
		tokens.push_back(buffer);
	}

	sort(tokens.begin(), tokens.end());

	for (auto& i: tokens)
		cout << i << '\n';
}