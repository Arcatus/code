#include<stdio.h>
void derecha(int *a, int *b, int *c, int *d, int *e){
 int cam;
 cam=*e;
 *e=*d;
 *d=*c;
 *c=*b;
 *b=*a;
 *a=cam;
}
void izquierda(int *a, int *b, int *c, int *d, int *e){
 int aux;
 aux=*a;
 *a=*b;
 *b=*c;
 *c=*d;
 *d=*e;
 *e=aux; 
}
int main(){
 int u=1, v=2, w=3, x=4, y=5;
 int I,D;
 scanf("%d, %d", &I, &D);
 for(int i = 0; i < D; ++i) {
     derecha(&u, &v, &w, &x, &y);
 }
 printf("%d %d %d %d %d", u, v, w, x, y);
 return 0;
}