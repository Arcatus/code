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

typedef long long ll;

vector<ll>::iterator inicio;
vector<ll>::iterator mitad;

ll binSearch(vector<ll>::iterator ini, vector<ll>::iterator fin, ll v)
{
   if (ini == fin) {
      return 0;
   } else {                         
      mitad = ini + (fin - ini) / 2LL;
      if (v == *mitad) {
         return mitad - inicio;
      } else if (v < *mitad) {
         return binSearch(ini, mitad, v);
      } else {
         return binSearch(mitad + 1LL, fin, v);
      }
   }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll n, q, opc;
	cin >> n >> q;

	vector< ll > tab(n);

	for (ll i=0;i<n;++i)
	{
		cin >> tab[i];
	}

	//sort(tab.begin(), tab.end());

	inicio = tab.begin();

	for (ll i=0;i<q;++i) 
	{
		cin >> opc;

		cout << binSearch(tab.begin(), tab.end(), opc) << ' ';
	}
	cout << '\n';
	return 0;
}