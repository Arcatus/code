#include <cstdio>
#include <algorithm>
using namespace std;

int Df[]={0, 1, 0, -1};
int Dc[]={1, 0, -1, 0};
int F, C;
bool V[1005][1005];

int cuenta(int f, int c, int m, int d){
	int r=0;
	if(f<1 || c<1 || f>F || c>C || V[f][c]){
		return 0;
	}
	V[f][c]=true;
	r++;
	r+=cuenta(f+Df[d], c+Dc[d], max(0, m-1), d);
	if(m==0){
		d++;
		d%=4;
		r+=cuenta(f+Df[d], c+Dc[d], 0, d);
	}
	V[f][c]=false;
	return r;
}

int main(){
	scanf("%d %d", &F, &C);
	printf("%d\n", cuenta(1, 1, 0, 0));
	return 0;
}
