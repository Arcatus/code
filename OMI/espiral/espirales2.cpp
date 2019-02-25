#include <cstdio>
#include <algorithm>
using namespace std;

const int M=1000000000;
int Cont[500][500];
int F, C;
int N;

int main(){
	int i, k, h;
	int a, b;
	scanf("%d %d", &F, &C);
	N=max(F, C);
	for(i=1;i<=N;i++){
		Cont[1][i]=i;
		Cont[i][1]=i;
	}
	for(i=2;i<=N;i++){
		for(k=2;k<=i;k++){
			for(b=1;b<=2;b++){
				Cont[i][k]=k;
				for(a=1;a<=k;a++){
					Cont[i][k]+=Cont[a][i-1];
					Cont[i][k]%=M;
				}
				swap(i, k);
			}
		}
	}
	printf("%d\n", Cont[F][C]);
	return 0;
}
