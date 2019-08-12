#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	stack<int> mipila;

	char opcion[10];

	int n, v;
	cin >> n;

	for (int i=0; i<n; ++i) 
	{
		cin >> opcion;
		if ( opcion[0] == 'A' ) {
			cin >> v;
			mipila.push(v);
		} else if ( opcion[0] == 'C' ) {
			int a = mipila.top();
			mipila.pop();
			int b = mipila.top();
			mipila.pop();
			mipila.push( a+b );
		} else {
			cout << mipila.top() << '\n';
		}
	}
}