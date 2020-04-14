#include <bits/stdc++.h>

using namespace std;

char buffer[1000001];

int main()
{
	scanf("%s",buffer);
	long long k=0;
	for(int i=0; buffer[i]; i++)
	{
		if (buffer[i]=='1') k++;
	}
	printf("%lld\n",(k*(k+1LL))/2LL);
	return 0;
}