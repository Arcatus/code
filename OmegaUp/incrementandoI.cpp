#include <iostream>
//#include <cstdio>
//#include <fstream>
//#include <unordered_map>
//#include <map>
//#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	priority_queue<int> s;
	priority_queue<int> e;

	int a, b;
	for (int i=0;i<m;++i)
	{
		cin >> a >> b;
		s.push(a);
		e.push(b);
	}
	int pek;
	int incremento=0;
	for (int i=0;i<n;++i)
	{
		if (incremento==0) {
			i = min(s.top(),e.top());
			cout << "skipping to " << i << '\n';
		}
		while( s.top() == i ) {
			s.pop();
			incremento++;
		}
		while( e.top() == i ) {
			e.pop();
			incremento--;
		}
		arr[i] += incremento;
	}	

	for (int i=0;i<n;++i)
	{
		cout << arr[i] << ' ';
	}
	cout << '\n';
	return 0;
}