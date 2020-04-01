#include <iostream>

using namespace std;

int main()
{
    int t;

    cin >> t;
    
    int x;
    while(t--) {
        cin >> x;
        cout << "Area a comprar: " << (x<<1) << '\n';
    }
}