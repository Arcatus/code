#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << -1 << '\n';
        } else {
            for(int i=1; i<n; ++i) {
                cout << "5";
            }
            cout << "8\n";
        }
    }
}