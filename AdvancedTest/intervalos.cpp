#include <stdio.h>

int BIT[100000], a[100000], n;

void update(int x, int val)
{
    for(; x <= n; x += x&-x)
    BIT[x] += val;
}

int query(int x)
{
     int sum = 0;
     for(; x > 0; x -= x&-x)
         sum += BIT[x];
     return sum;
}



int main()
{

	int m, i, I, U, tmp;

	scanf("%d",&n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d",&tmp);
		a[i] = tmp;	
		update(i,a[i]);
	}

	scanf("%d",&m);

	int* ptr;

	for (i = 0; i < m; ++i)
	{
		scanf("%d%d",&I,&U);
		printf("%d\n",query(U+1) - query(I));
	}
}