#include <algorithm>
#include <cstdio>

using namespace std;

#define MAXN 1000010

int N, V;
int pancakes[MAXN];

int main(){
	scanf("%d %d", &N, &V);

	for (int i = 0; i < N; i++)
		pancakes[i] = i + 1;

	while (V--){
		int a;
		scanf("%d", &a);
		reverse(pancakes + a - 1, pancakes + N);
	}

	for (int i = 0; i < N; i++)
		printf("%d ", pancakes[i]);
	printf("\n");
}
