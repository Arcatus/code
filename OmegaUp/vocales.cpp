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

	string buffer;
	cin >> buffer;
	int contador=0;
	int size = buffer.length();
	for(int i=0;i<size;++i)
	{
		if (buffer[i]=='A'||buffer[i]=='E'||buffer[i]=='I'||buffer[i]=='O'||buffer[i]=='U')
			contador++;
	}

	cout <<size - contador<< ' ' << contador<< '\n';

	return 0;
}