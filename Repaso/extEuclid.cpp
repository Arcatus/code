#include <iostream>

using namespace std;

int xGCD(int a, int b, int &x, int &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    int x1, y1, gcd = xGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int main()
{
   int a, b, x, y, gcd;

   cin >> a >> b;

   gcd = xGCD(a, b, x, y);
   std::cout << "GCD: " << gcd << ", x = " << x << ", y = " << y << std::endl;

   return 0;
}