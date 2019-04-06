#include <stdio.h>

int main()
{
	char bit;

	int n, cont1=0, cont2=0;

	char a[2];
	char b[2];
	a[0] = 'B'; a[1] = 'W';
	b[0] = 'W'; b[1] = 'B';

	scanf("%d",&n); getchar();
	
	for(int x = 0; x < n; ++x )
	{
		bit = getchar();
		if (bit != a[x%2])
			cont1++;
		if (bit != b[x%2])
			cont2++;
	}
	
	if (cont1 < cont2){
		printf("%d\n",cont1);
	}
	else{
		printf("%d\n",cont2);
	}
}