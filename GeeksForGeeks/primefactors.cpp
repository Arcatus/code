// Program to print all prime factors 
#include <iostream>
#include <stdio.h> 
#include <math.h> 

using namespace std;

typedef unsigned long long llu;

void primeFactors(llu n) 
{ 
    while (n%2 == 0) { 
        printf("%d ", 2);
        n = n/2; 
    }
    for (llu i = 3; i <= sqrt(n); i = i+2) { 
        while (n%i == 0) { 
            printf("%llu ", i);
            n = n/i; 
        } 
    }
    if (n > 2)
        printf ("%llu ", n);
} 

int main() 
{ 
    llu n;
    cin >> n;
    primeFactors(n); 
    return 0; 
} 