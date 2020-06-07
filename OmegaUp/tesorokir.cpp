#include <iostream>
typedef long long int li;
const long long p = 1000000000;
li f(int N){
    if (N%2) return 0;
    li pA[2]={1,1};
    for (int i=2; i<=N; i++)
        if (i&1) pA[1] = (pA[1] + pA[0])%p;
        else pA[0] = (pA[0] + ((pA[1])<<1))%p;
    return pA[0]%p;
}

int main() {
    int n;
	scanf("%d",&n);
	printf("%li\n",f(n));
	return 0;
}