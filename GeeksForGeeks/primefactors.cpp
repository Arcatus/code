#include <iostream>
#include <cmath> 

using namespace std;

typedef unsigned long long llu;

void primeFactors(llu n) 
{ 
    while (n%2 == 0) {
        cout << "2 ";
        n = n/2;
    }
    for (llu i = 3; i <= sqrt(n); i+=2) {
        while (n%i == 0) { 
            cout << i << ' ';
            n = n/i; 
        } 
    }
    if (n > 2)
        cout << n;
} 

int main() 
{ 
    ios::sync_with_stdio(false);
    cin.tie(0);

    llu n, t;
    cin >> n;

    for (llu i=0;i<n;++i)
    {
        cin >> t;
        primeFactors(t);
        cout << '\n';
    }
    return 0; 
}