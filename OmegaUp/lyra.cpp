#include <iostream>

using namespace std;



int main()
{
	char bit;

	int n, cont1=0, cont2=0;

	int a[2];
	int b[2];
	a[0] = '1'; a[1] = '0';
	b[0] = '0'; b[1] = '1';

	scanf("%d",&n); getchar();
	
	for(int x = 0; x < n; ++x )
	{
		bit = getchar();
		getchar();
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