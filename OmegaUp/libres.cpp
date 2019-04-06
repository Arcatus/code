#include <iostream>
#include <cstdlib>
#include <cmath>
#include <set>

typedef unsigned long long llu;

using namespace std;

std::set<llu> factors;

void primeFactors(llu n)
{ 
    while (n%2 == 0)
    {
        if (factors.count(2) > 0){
            cout << "NO\n";
            exit(0);
        }
        else
            factors.emplace(2);
        n = n/2;
    }
    for (llu i = 3; i <= sqrt(n); i = i+2) 
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
    llu n;
    cin >> n;
    primeFactors(n);
    cin >> n;
    primeFactors(n);
} 