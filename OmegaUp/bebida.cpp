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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tiendas;
	cin >> tiendas;

	vector<int> precioInka(tiendas);

	for (int i=0; i < tiendas; ++i)
	{
		cin >> precioInka[i];
	}

	int dineros;
	cin >> dineros;

	sort(precioInka.begin(),precioInka.end());

	int dinero;
	for (int i = 0; i < dineros; ++i)
	{
		cin >> dinero;
		auto it = lower_bound(precioInka.begin(),precioInka.end(),dinero);

		int distance = it - precioInka.begin();


		if (*it < dinero && *it < precioInka[0] )
			cout << "0" << '\n';
		else if(*it > dinero && *it > precioInka[0])
		{
			cout << distance << '\n';
		}
		else
		{
			cout << distance + 1  << '\n';
		}
	}
	return 0;
}