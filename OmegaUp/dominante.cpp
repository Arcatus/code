#include <cstdio>

int main()
{
	int a, dom;

	int cdom = 1;

	scanf("%d",&a);

	dom = a;

	while( (scanf("%d",&a)) == 1 )
	{	
		if(cdom==0)
		{
			dom=a;
		}
		if(dom==a)
		{
			cdom++;
		}
		else{
			cdom--;
		}
	}

	printf("%d\n", dom);
	return 0;
}