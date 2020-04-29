#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {   
        ll a, b;
        cin >> a >> b;
        if (a%b==0) {
            cout << 0 << '\n';
        } else if ( a > b) {
            cout << ((a/b)+1)*b - a << '\n';
        } else {
            cout << b-a << '\n';
        }
    }
}