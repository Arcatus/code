#include "cluedo.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

bool caso_resuelto;
int n_teoria, max_teorias;
int sospechoso, ubicacion, arma;
int Teoria(int c, int u, int a) {
  printf("Teoria #%d: %d %d %d.\n",
    n_teoria + 1, c, u, a);
  fflush(stdout);
  
  if (max_teorias <= n_teoria++) {
    puts("Excediste el numero maximo de teorias.");
    fclose(stdout); return 0;
  }
  if (sospechoso != c) {
    puts("El sospechoso es incorrecto.");
    fflush(stdout); return 1;
  }
  if (ubicacion != u) {
    puts("La ubicacion es incorrecta.");
    fflush(stdout); return 2;
  }
  if (arma != a) {
    puts("El arma es incorrecta.");
    fflush(stdout); return 3;
  }
  
  puts("La teoria es correcta!");
  caso_resuelto = true;
  fflush(stdout);
  return 0;
}

void ResolverCaso() {

	srand(time(NULL));

	int c=(rand()%6)+1;
	int u=(rand()%10)+1;
	int a=(rand()%6)+1;

	int respuesta=-1;

	int sospechosos[6];
	for(int i=0;i<6;++i) sospechosos[i] = 0;

	int ubicaciones[10];
	for(int i=0;i<10;++i) ubicaciones[i] = 0;

	int armas[6];
	for(int i=0;i<6;++i) armas[i] = 0;

	while(true)
	{
		respuesta = Teoria(c,u,a);

		if (respuesta==0) return;
		else
		{
			if (respuesta==1)
			{
				sospechosos[c-1] = -1;
			} 
			else if (respuesta==2) 
			{
				ubicaciones[u-1] = -1;
			} 
			else if(respuesta==3) 
			{
				armas[a-1] = -1;
			}
		}
		do{
			c=(rand()%6) + 1;
		}while(sospechosos[c-1]!=0);
		do{
			u=(rand()%10) + 1;
		}while(ubicaciones[u-1]!=0);
		do{
			a=(rand()%6) + 1;
		}while(armas[a-1]!=0);
	}
}

int main(){

  max_teorias = 360;

  scanf("%d%d%d", &sospechoso, &ubicacion, &arma);
  caso_resuelto = false;

  ResolverCaso();
  
  if (caso_resuelto) {
    puts("Has resuelto el caso, detective! :)");
    cout << n_teoria << '\n';
  }	else {
  	puts("El caso no ha sido resuelto :(");
  }

  fclose(stdout);
  return 0;
}