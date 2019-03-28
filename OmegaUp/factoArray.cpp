#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

using namespace std;

int factorial[] = 
{
	1,
	1,
	2,
	6,
	24,
	120,
	720,
	5040,
	40320,
	362880,
	3628800,
	39916800,
	479001600
};

int main()
{

	int a, b;
	cin >> a >> b;

	cout << factorial[a] / factorial[b]<<'\n';
}