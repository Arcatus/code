#include <iostream>
#include <tuple>

using namespace std;

#define mt(a,b) make_tuple(a,b);

typedef tuple<int,int,int> tiii;

tiii extEuclid(int a, int b)
{
    int s0 = 1, t0 = 0, s1 = 0, t1 = 1;
    int r0 = a, r1 = b;
    while( r1 ) {
        int q = r0 / r1;
        tie(r0, r1) = mt(r1, r0 - r1*q);
        tie(s0, s1) = mt(s1, s0 - s1*q);
        tie(t0, t1) = mt(t1, t0 - t1*q);
    }
    return { s0, t0, r0 };
}

int main()
{
    int a, b;
    cin >> a >> b;
    int x, y, gcd;
    
    tie(x,y,gcd) = extEuclid(a,b);

    cout << "GCD: " << gcd << ", x = " << x << ", y = " << y << '\n';
}