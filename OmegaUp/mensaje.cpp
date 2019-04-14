#include <iostream>
#include <algorithm>

using namespace std;
struct letra
{
	short pos;
	char code;
};

bool cmp(letra a, letra b)
{
	return a.code < b.code;
}
short i, j, n;
letra arr[6];
char codigo[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (i = 0; i < n; ++i)	{
		arr[i].pos = i;
		cin >> arr[i].code;
	}
	for (i = 0; i < n; ++i)	{
		for (j = 0; j < n; ++j)	{
			cin >> codigo[i*n + j];
		}
	}
	sort(arr,arr+n,cmp);
	for (i = 0; i < n; ++i)	{
		for (j = 0; j < n; ++j)	{
			cout << codigo[i*n + arr[j].pos];
		}
		cout << '\n';
	}
	return 0;
}