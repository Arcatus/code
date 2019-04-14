#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int cuentas[128];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string buffer;

	int n = s.length();

	for (i = 0; i < n; ++i)
	{
      cuentas[s[i]] += 1;
  	}

	stringstream line(buffer);

	vector<int> sizes;

	while(getline(line,buffer,' '))
	{
		sizes.push_back(buffer.length());
	}

	sort(sizes.begin(), sizes.end());

	cout << sizes[sizes.size()-1] << '\n';
}