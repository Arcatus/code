#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>
//#include <vector>
//#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

ll potencia(ll a, ll b)
{
   if (b == 0) {
      return 1;
   } else if (b == 1) {
      return a;
   } else {
      ll temp = potencia(a, b / 2LL);
      ll res = temp * temp;
      if (b % 2LL == 1LL) {
         res *= a;
      }
      return res;
   }
}

int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	cin >> n;
	ll opc;
	ll a, b;
	double raiz;

	for (int i=0;i<n;++i)
	{
		cin >> opc;
		switch(opc)
		{
			case 1: {
				cin >> a;
				cout << abs(a) <<'\n';break;
			}
			case 2: {
				cin >> a >> b;
				cout << max(a,b) << '\n';break;
			}
			case 3: {
				cin >> a >> b;
				cout << min(a,b) << '\n';break;
			}
			case 4: {
				cin >> raiz;
				printf("%.2f\n",sqrt(raiz));break;
			} 
			case 5: {
				cin >> a >> b;
				cout << potencia(a,b) << '\n';
			}
		}
	}

	return 0;
}