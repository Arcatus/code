#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;

    if ( a <= c && c <= b ) { 
        cout << "INTERVALO\n";
    } else if( b < c) {
        cout << "DERECHA\n";
    } else {
        cout << "IZQUIERDA\n";
    }
}