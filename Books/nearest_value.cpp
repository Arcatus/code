#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	vector<int> s;

	for (int i=1;i<10;i+=2) {
		s.push_back(i+2);
		cout << i+2 << ' ';
	}
	cout <<'\n';
	int x;
	cin >> x;
	auto it = lower_bound(s.begin(),s.end(),  x);

	if (it == s.begin()) {
		cout << *it << "\n";
	} else if (it == s.end()) {
		it--;
		cout << *it << "\n";
	} else {
		int a = *it; it--;
		int b = *it;
		if (x-b < a-x) cout << b << "\n"; // nearest bigger than
		else cout << a << "\n";
	}
	return 0;
}