#include <stdio.h>

#define MAXV 50010

typedef struct {
	int fst, snd;
} pii;

int N, V;
pii r[MAXV];

int _abs(int x){ return x < 0 ? -x : x; }
int siz(pii x){ return _abs(x.fst - x.snd) + 1; }

void flip(int x){
	int i, j, a;
	pii b;
	for (i = x, j = N-1; i < j; i++, j--){
		b = r[i];
		r[i] = r[j];
		r[j] = b;
	}

	for (i = x; i < N; i++){
		a = r[i].fst;
		r[i].fst = r[i].snd;
		r[i].snd = a;
	}
}

int sign(pii x){
	if (x.fst == x.snd) return 0;
	if (x.fst < x.snd) return 1;
	return -1;
}

int main(){
	int i, j;

	scanf("%d %d", &N, &V);

	r[0].fst = 1;
	r[0].snd = N;

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

			r[N].fst = toAdd.snd;
			r[N++].snd = toAdd.fst;
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
