#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	float tmp;
	float res=0.0f;
	for (int i=0;i<n;++i)
	{
		cin >> tmp;

		res += tmp;
	}

	printf("%.2f\n",(float) res/n );

	return 0;
}