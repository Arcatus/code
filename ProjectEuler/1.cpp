#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long ans = 0;

    long long n = floor(1000000000/3);
    ans += ( 3* n*(n+1) ) / 2;

    n = floor(1000000000/5-1);
    ans += ( 5* n*(n+1) ) / 2;

    n = floor(1000000000/15);
    ans -= ( 15* n*(n+1) ) / 2;

    cout << ans << '\n';
}