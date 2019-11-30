#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<bool> checker(100,false);
	
	for (int i=70;i<100;++i) {	
		checker[i] = true;
	}

	int x = -1;

	auto ok = [&](int x)
	{
		return checker[x];
	};

	int z = 100;
	for (int b = z; b >= 1; b /= 2) {
		while (!ok(x+b)) x += b;
		cout << b << " " << x << '\n';
	}
	int k = x+1;

	cout << k << '\n';

	return 0;
}