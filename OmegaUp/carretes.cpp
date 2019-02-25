#include <iostream>
//#include <cstdio>
//#include <string>
//#include <algorithm>
#include <cmath>
#include <string>

int main()
{
	std::string s1, s2;
	
	int n;
	scanf("%d",&n);

	std::cin >> s1 >> s2;

	int counter = 0;

	for(int i = 0; i < n; ++i)
	{
		int a = s1[i] - '0';
		int b = s2[i] - '0';

		int t1, t2;
		
		if ( a < b )
		{
			t1 = b - a;

			t2 = ( a+10  - b);
		}
		else
		{
			t1 = a - b;

			t2 = ( b+10  - a);	
		}
		if ( t1 < t2)
		{	
			counter += t1;
		}
		else
		{
			counter += t2;
		}
	}
	printf("%d\n",counter);
}