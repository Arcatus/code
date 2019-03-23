//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

int main()
{
	int n;
	scanf("%d",&n);
	int t;
	while(n > 0)
	{
		n--;
		scanf("%d",&t);
		if (t == 1)
		{
			printf("HARD\n");
			return 0;
		}
	}
	printf("EASY\n");
}