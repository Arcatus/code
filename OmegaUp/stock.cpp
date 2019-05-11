#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<int> mipila;
	int t;
	for (int i=0;i<n;++i)
	{
		cin >> t;
		mipila.push(t);
	}

	while(!mipila.empty() )
	{
		cout << mipila.top() << '\n';
		mipila.pop();
	}

	return 0;
}