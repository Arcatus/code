#include <stdio.h>

#define MAXN 500000

int pizza[MAXN];

int visibles(int P){
	if(P == 0) return 0;
	
	int conteoVisibles = 1;
	int diametro = pizza[P - 1];
	for(int i = P - 2; i >= 0; i--){
		if(pizza[i] > diametro){
			diametro = pizza[i];
			conteoVisibles++;
		}
	}
	
	return conteoVisibles;
}

int main(){
	int n, d, ins;
	scanf("%d", &n);
	
	int P = 0;
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ins);
		if(ins != 0) scanf("%d", &d);
		
		switch(ins){
			case 0: printf("%d\n", visibles(P)); break;
			case 1: pizza[P++] = d; break;
			case 2: P -= d;
		}
	}
	
	return 0;
}