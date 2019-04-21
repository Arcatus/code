#include <cstdio>
#include <algorithm>

using namespace std;

#define mp make_pair
#define fst first
#define snd second

#define MAXV 50010

typedef pair<int,int> pii;

int N, V;
pii r[MAXV];

int _abs(int x){ return x < 0 ? -x : x; }
int siz(pii x){ return _abs(x.fst - x.snd) + 1; }

void flip(int i){
	reverse(r + i, r + N);
	for (; i < N; i++) swap(r[i].fst, r[i].snd);
}

int sign(pii x){
	if (x.fst == x.snd) return 0;
	if (x.fst < x.snd) return 1;
	return -1;
}

int main(){
	int i, j;

	scanf("%d %d", &N, &V);

	r[0] = mp(1, N);
	N = 1;

	while (V--){
		int a, s;
		scanf("%d", &a); a--;

		for (i = 0; a >= siz(r[i]); a -= siz(r[i]), i++);

		s = sign(r[i]);

		if (a == 0){
			flip(i);
		} else {
			pii toAdd = r[i];
			r[i].snd = r[i].fst + (a-1) * s;
			toAdd.fst = r[i].snd + s;

			flip(i+1);

			swap(toAdd.fst, toAdd.snd);
			r[N++] = toAdd;
		}
	}

	for (i = 0; i < N; i++){
		int s = sign(r[i]);
		for (j = r[i].fst; j != r[i].snd; j += s)
			printf("%d ", j);
		printf("%d ", j);
	}
	printf("\n");
}
