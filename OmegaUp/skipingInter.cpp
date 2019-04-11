#include <iostream>
//#include <cstdio>
//#include <string>
#include <algorithm>
#include <vector>
//#include <fstream>
#include <set>

using namespace std;

//typedef unsigned long long llu;
typedef vector<int> vi;

int a;
vi arr;
vi brr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;

	std::set<int> intersection;

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		arr.push_back(a);
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		brr.push_back(a);
	}

	vi old_a( arr.begin(), arr.end() );
	vi old_b( brr.begin(), brr.end() );

	sort(arr.begin(),arr.end());
	sort(brr.begin(),brr.end());

	set_intersection(
		arr.begin(),arr.end(), brr.begin(), brr.end(),
			inserter( intersection,intersection.begin() ) );

	for (int i = 0; i < n; ++i)
	{
		if ( intersection.count(old_a[i]) == 0 )
		{
			cout << old_a[i] << ' ';
		}
	}
	cout << '\n';

	for (int i = 0; i < n; ++i)
	{
		if ( intersection.count(old_b[i]) == 0 )
		{
			cout << old_b[i] << ' ';
		}
	}
	cout << '\n';
}