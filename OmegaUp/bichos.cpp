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
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, dias, i;

	cin >> n >> dias;

	int bichos_type_A = n;
	int bichos_type_B = 0;
	int bichos_type_C = 0;
	int bebes_type_A=0;
	int bebes_type_B=0;
	int bebes_type_C=0;

	int res = 0;

	while(dias >= 0) {
		// los bebes se convierten en adultos
		bichos_type_A += bebes_type_A;
		bichos_type_B += bebes_type_B;
		bichos_type_C += bebes_type_C;
		// quitamos bebes
		bebes_type_A = 0;
		bebes_type_B = 0;
		bebes_type_C = 0;

		// generacion de bebes
		for (i = 0; i < bichos_type_A; ++i) 
		{
			bebes_type_A += 1;
			bebes_type_B += 3;
			bebes_type_C += 1;
		}
		for (i = 0; i < bichos_type_B; ++i) 
		{
			bebes_type_B += 2;
			bebes_type_C += 2;
		}
		for (i = 0; i < bichos_type_C; ++i) 
		{
			bebes_type_A += 1;
			bebes_type_C += 4;
		}
		dias--;
	}
	cout << bichos_type_A + bichos_type_B + bichos_type_C << '\n';

	return 0;
}