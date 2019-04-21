#include <stack>
#include <stdio.h>

using namespace std;

#define MEDN 5000
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
	int respuesta;
	stack<int> pila;
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ins);
		if(ins != 0) scanf("%d", &d);
		
		switch(ins){
			case 0:
				respuesta = pila.size();
				if(n <= MEDN) respuesta = visibles(P);
				printf("%d\n", respuesta); break;
				
			case 1: 
				if(n > MEDN){
					while(not pila.empty())
						if(pila.top() > d) break;
						else pila.pop();
					pila.push(d);
				}
				pizza[P++] = d; break;
				
			case 2: P -= d;
		}
	}
	
	return 0;
}