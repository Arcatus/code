#include <iostream>

using namespace std;

long mod(long a, long b)
{ 
    return ( a % b + b ) % b;
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << mod(a,b) << '\n';
}
