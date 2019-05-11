#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <utility>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, t;
	cin >> n;

	stack<int> pila1;
	stack<int> pila2;

	vector<int> a(n);

	for (int i=0; i<n;++i)
	{
		cin >> a[i];
	}

	for (int i = a.size()-1; i>=0;i--)
	{
		pila1.push(a[i]);
	}

	pair<int,int> key;
	vector<int> subarrays;
	set< pair<int,int> > tab;	

	while( !pila1.empty() )
	{
		subarrays.clear();

		while(!pila1.empty()) {
			subarrays.push_back(pila1.top());
			for (auto& i: subarrays) cout << i << ' '; cout << '\n';
			if (subarrays.size() > 1) {
				int size = subarrays.size();
				auto it = max_element(subarrays.begin(), subarrays.end());
				key.first = *it;
				*it = 0;
				it = max_element(subarrays.begin(), subarrays.end());
				key.second = *it;
				*it = 0;				
				if (key.first != 0 && key.second!=0 ) {
					//cout << key.first << " " << key.second << '\n';
					if ( tab.count( key ) == 0 ) {
						tab.emplace( key );
					}
				}
			}
			pila2.push(pila1.top());
			pila1.pop();
		}		

		while( pila2.size() != 1) {
			pila1.push(pila2.top());
			pila2.pop();
		}
		pila2.pop();
	}

	cout << tab.size() << '\n';

	return 0;
}