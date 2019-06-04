#include <cstdio>

using namespace std;

int cuenta(int n, int k)
{
	if (n == 0) 
	{
		return 1;
	}
	else if( n == 1 )
	{
		return 2;
	}
	else
	{
		if (k == 0) {
			return cuenta(n-2,1) + cuenta(n-1,1);
		}
		else
		{
			return cuenta(n-1,0) + cuenta(n-1,1);
		}
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%d\n",cuenta(n,1));
	return 0;
}