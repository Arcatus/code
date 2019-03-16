//#include <iostream>
#include <cstdio>
//#include <string>
//#include <algorithm>
//#include <string>

void setAtBegin(const short m)
{
	fseek(stdin,4*m+4,SEEK_SET);
}
void setAtInterval(const short i)
{
	fseek(stdin,2+i*4,SEEK_SET);
}

void setAtPos(const short a)
{
	fseek(stdin, a*2,SEEK_CUR);
}

void setAtN(const short m)
{
	fseek(stdin,4*m+2,SEEK_SET);
}

int main()
{
	short m;

	scanf("%hi",&m);

	unsigned long a;
	unsigned long b;
	long long r;
	short t, t2, n;

	unsigned int res = 0;

	setAtN(m);
	scanf("%hi",&n);

	for (short i = 0; i < m; ++i )
	{
		setAtInterval(i);

		scanf("%lu %lu",&a,&b);

		setAtBegin(m);

		setAtPos(a);

		b = b-a;

		r = 0;

		for(unsigned long j = 1; j < b;j+=2)
		{
			scanf("%hi %hi",&t,&t2);
			r+=t+t2;
		}
		if (b%2==1)	
		{
			scanf("%hi",&t);
			r+=t;
		}

		printf("%lld\n",r);
	}
}