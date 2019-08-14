#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<int> v;

	for (int i=1; i<=n; ++i) {
		if (n % i == 0) {
			v.push_back(i);
		}
	}	
	for(int i=v.size()-1; i>=0; --i) {
		cout << v[i] << '\n';
	}
}