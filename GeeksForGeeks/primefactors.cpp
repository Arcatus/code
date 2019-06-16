#include <iostream>
#include <set>
#include <cmath> 

using namespace std;

typedef unsigned long long llu;

set<llu> primes;

void primeFactors(llu n) 
{ 
    while (n%2 == 0) {        
        primes.insert(2LL);
        n = n/2;
    }
    for (llu i = 3; i <= sqrt(n); i+=2) {
        while (n%i == 0) { 
            primes.insert(i);
            n = n/i; 
        } 
    }
    if (n > 2){
        primes.insert(n);
    }
} 

int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);

    llu n, t;
    
    while(cin >> t) {
        primes.clear();
        primeFactors(t);
        for (auto i: primes)
        {   
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0; 
}