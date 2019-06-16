#include <cstdio>
#include <algorithm>

using namespace std;

char a[5000+1];
char b[5000+1];

int lcs(int i,int j)
{
	if (a[i] == '\0' || b[j]== '\0')
	{
		return 0;
	}
	else if ( a[i] == b[j] )
	{		
		return 1+lcs(i+1,j+1);
	}
	else 
	{
		return max(lcs(i+1,j),lcs(i,j+1));
	}
}

int main()
{
	scanf("%s",a);
	scanf("%s",b);

	printf("%d\n",lcs(0,0));
	
	return 0;
}