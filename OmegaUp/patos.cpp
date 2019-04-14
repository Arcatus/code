#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <vector>
//#include <fstream>

using namespace std;

//typedef unsigned long long llu;
//typedef vector<int> vi;

vector<bool> todo_patos(101,false);

int main()
{
	int n, t;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> t;
		todo_patos[t-1] = true;
	}
	int i, j;
	//menor
	for (i = 0; i < 101; ++i) {
		if ( todo_patos[i] == true) {
			break;
		}
	}
	//mayor
	for (j = 100; j >= 0; j--) {
		if ( todo_patos[j] == true) {
			break;
		}
	}
	int contador = 0;
	for (;i<=j; ++i) {
		if (todo_patos[i] == false)
		{
			contador++;
		}
	}
	cout << contador << '\n';
	return 0;
}