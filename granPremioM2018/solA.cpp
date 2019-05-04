#include <iostream>

using namespace std;

typedef long long ll;

const ll factorial[] =
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
	479001600,
};

int repeticiones[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	string n;
	
	for (int i=0;i<t;++i) {
		cin >> n;		
		for (int j=0;j<(int)n.size();++j) 
		{
			repeticiones[n[j]-'0']++;
		}
	}

	return 0;
}