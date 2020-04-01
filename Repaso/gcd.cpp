#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b) { int r = a % b; a = b; b = r; }
    return a;
}

int main()
{
    int a, b;

    cin >> a >> b;

    int ans = gcd(a,b);

    cout << ans  <<'\n';
}