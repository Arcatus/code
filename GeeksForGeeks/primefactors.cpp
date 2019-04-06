// Program to print all prime factors 
#include <iostream>
#include <stdio.h> 
#include <math.h> 

using namespace std;

void primeFactors(int n) 
{ 
    while (n%2 == 0) 
    { 
        printf("%d ", 2); 
        n = n/2; 
    }
    for (int i = 3; i <= sqrt(n); i = i+2) 
    { 
        while (n%i == 0) 
        { 
            printf("%d ", i); 
            n = n/i; 
        } 
    } 
    // This condition is to handle the case when n  
    // is a prime number greater than 2
    if (n > 2) 
        printf ("%d ", n); 
} 

int main() 
{ 
    int n;
    cin >> n;
    primeFactors(n); 
    return 0; 
} 