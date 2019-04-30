#include <iostream>
#include <cmath> 
#include <vector> 

using namespace std;

typedef unsigned long long llu;

vector<int> factores;

void primeFactors(llu n) 
{ 
    while (n%2 == 0) {
        factores.push_back(2);
        n = n/2;
    }
    for (llu i = 3; i <= sqrt(n); i+=2) {
        while (n%i == 0) {             
            factores.push_back(i);
            n = n/i; 
        } 
    }
    if (n > 2)
        factores.push_back(n);
} 

int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    llu n;
    cin >> n;

    primeFactors(n);

    if ( factores.size()==1 )
        cout << "PRIMO" <<'\n';
    else 
        cout << "COMPUESTO" <<'\n';

    return 0; 
}