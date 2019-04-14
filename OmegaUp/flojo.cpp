#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
//#include <algorithm>
#include <vector>
//#include <string>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int ejercicios;
	cin >> ejercicios;

	int sol[4][2];

	int resX, resY, x1,x2,y1,y2;

	vector<char> solucion(ejercicios);

	for (int i = 0; i < ejercicios; ++i)
	{
		cin >> x1 >> y1 >> x2 >> y2;

		cin >> sol[0][0] >> sol[0][1];
		cin >> sol[1][0] >> sol[1][1];
		cin >> sol[2][0] >> sol[2][1];
		cin >> sol[3][0] >> sol[3][1];

		resX = x1 + x2;
		resY = y1 + y2;
		for(int k = 0; k < 5; k++)
			if ( sol[k][0] == resX && sol[k][1] == resY){
				solucion[i] = k + 'A';break;
			}

	}
	for(auto& i: solucion)
		cout << i;
	cout << '\n';

	return 0;
}