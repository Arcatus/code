#include <cstdio>

int contador;

int nearestSmallerEqFib(int n) 
{ 
    if (n == 0 || n == 1){
        if (n==1) contador++;
        return n;
    }
    int f1 = 0, f2 = 1, f3 = 1;
    while (f3 <= n) {
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2; 
    }
    contador++;
    return f2;
} 

void printFibRepresntation(int n) 
{ 
    while (n > 0) {
        int f = nearestSmallerEqFib(n);
        n = n - f;
    } 
}
int main() 
{ 
    int n; 
    scanf("%d",&n);
    printFibRepresntation(n);
    printf("%d\n",contador);
    return 0; 
} 