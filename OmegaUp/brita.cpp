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

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	long n;
	cin >> n;

	long millas = n / 63360;

	long sobrante = n%63360;

	long furlongs = sobrante/7920;

	sobrante = sobrante%7920;

	long yardas = sobrante/36;

	sobrante = sobrante%36;

	long pies = sobrante/12;

	sobrante = sobrante%12;

	cout << millas << " " << furlongs << " " << yardas <<" " << pies << " " <<sobrante<< '\n';

	return 0;
}