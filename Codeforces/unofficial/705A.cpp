#include <cstdio>

int n, k;

const char *feelings[] = {
	"I hate that ",
	"I love that ",
	"I hate it ",
	"I love it ",
};

int main()
{
	scanf("%d",&n);
	if (n == 1){
		printf("I hate it\n");
	}
	else if( n == 2){
		printf("I hate that I love it\n");
	}
	else {
		for (k = 0; k < n-1;++k)
		{
			printf("%s",feelings[k%2]);
		}
		printf("%s\n",feelings[k%2+2]);
	}
}