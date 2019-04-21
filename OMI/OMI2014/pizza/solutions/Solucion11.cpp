#include <stdio.h>

int main(){
	int n, d, ins;
	scanf("%d", &n);
	
	int visibles = 0;
	
	for(int i = 0; i < n; i++){
		scanf("%d", &ins);
		if(ins != 0) scanf("%d", &d);
		
		switch(ins){
			case 0: printf("%d\n", visibles); break;
			case 1: visibles++; break;
			case 2: visibles -= d;
		}
	}
	
	return 0;
}