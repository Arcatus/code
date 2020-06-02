#include <bits/stdc++.h>

using namespace std;

bool sumaL(int a, int b, int c) { return a+b == c; }
bool sumaR(int a, int b, int c) { return a == b + c; }
bool restaL(int a, int b, int c) { return a - b == c; }
bool restaR(int a, int b, int c) { return a == b - c; }
bool multL(int a, int b, int c) { return a * b == c; }
bool multR(int a, int b, int c) { return a == b * c; }
bool divL(int a, int b, int c) { return a / b == c; }
bool divR(int a, int b, int c) { return a == b / c; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, c;
    while(cin >> a >> b >> c) {
        if ( sumaL(a,b,c) ) {
            cout << a << " + " << b << " = " << c << '\n';
        } else if ( sumaR(a,b,c) ) {
            cout << a << " = " << b << " + " << c << '\n';
        } else if ( restaL(a,b,c) ) {
            cout << a << " - " << b << " = " << c << '\n';
        } else if ( restaR(a,b,c) ) {
            cout << a << " = " << b << " - " << c << '\n';
        } else if ( multL(a,b,c) ) {
            cout << a << " * " << b << " = " << c << '\n';
        } else if ( multR(a,b,c) ) {
            cout << a << " = " << b << " * " << c << '\n';
        } else if ( divL(a,b,c) ) {
            cout << a << " / " << b << " = " << c << '\n';
        } else if ( divR(a,b,c) ) {
            cout << a << " = " << b << " /" << c << '\n';
        }
    }
    return 0;
}