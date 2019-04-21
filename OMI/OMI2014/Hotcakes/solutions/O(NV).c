#include <stdio.h>

#define MAXN 1000010

int N, V;
int pancakes[MAXN];

int main(void){
	int i, j;
	scanf("%d %d", &N, &V);

	for (i = 0; i < N; i++)
		pancakes[i] = i + 1;

	while (V--){
		int a;
		scanf("%d", &a);
		for (i = a-1, j = N-1; i < j; i++, j--){
			a = pancakes[i];
			pancakes[i] = pancakes[j];
			pancakes[j] = a;
		}
	}

	for (i = 0; i < N; i++)
		printf("%d ", pancakes[i]);
	printf("\n");

	return 0;
}
