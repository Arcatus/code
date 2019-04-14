#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>
//#include <vector>
#include <string>

using namespace std;

int suma(string a, string b)
{
	int n = a.length(), m = b.length(); 

	int l = 1 + max(n,m);

	string ans(l,'0');

	a = string(l-n,'0') + a;
	b = string(l-m,'0') + b;

	int sum = 0, ac = 0, contador = 0;

	for (int i = l - 1; i >= 0; i--)
	{
		sum = (a[i] - '0') + (b[i] - '0') + ac;
		ans[i] = (sum % 10) + '0';
		ac = sum / 10;
		if (ac > 0)
			contador++;
	}
	return contador;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string a, b;

	cin >> a >> b;
	cout << suma(a,b) << '\n';
}