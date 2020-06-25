#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin >> n;
    long long pares = n/2;
    long long impares = n - pares;
    pares = (((pares)*(pares+1))/2)*2;
    impares = ( ((impares-1)*(impares))/2 )*2 + impares;
    cout << -impares + pares << '\n';
    return 0;
}