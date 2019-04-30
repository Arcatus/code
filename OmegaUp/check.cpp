//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algoritm>
//#include <string>

int main()
{
	int n;

	scanf("%d",&n);

	int a[n];
	for(int i=0; i<n; ++i)
	{
		scanf("%d",&a[i]);
	}		
	int k;			
	scanf("%d",&k);

	for (int j=0;j<n;++j)
	{
		if (a[j]==k) {
			printf("%d\n",j);
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}