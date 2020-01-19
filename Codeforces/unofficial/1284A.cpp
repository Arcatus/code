#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<string> s;
	vector<string> t;

	int n, m;

	cin >> n >> m;

	string tmp;

	for(int i=0; i<n; ++i) {
		cin >> tmp;
		s.push_back(tmp);
	}
	for(int i=0; i<m; ++i) {
		cin >> tmp;
		t.push_back(tmp);
	}

	int q, r;
	string ans;
	cin >> q;

	for(int i=0; i<q; ++i) {
		cin >> r;
		r-=1;
		//cout << "indexing " << r % s.size() << " " << r % t.size() << '\n';
		cout << s[ r % s.size() ] << t[ r % t.size() ] << '\n';
	}
}