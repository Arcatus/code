#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int t;

    cin >> t;

    for(int k=0; k<t; ++k) {
        int n;
        cin >> n;
        int a[n];
        int cut = INT_MAX;
        for(int i=0; i<n; ++i) {
            cin >> a[i];
            cut = min(cut,a[i]);
        }
        bool ans = true;
        for(int i=0; i<n; ++i) {
            a[i] -= cut;
            if ( a[i] % 2 == 1) {
                ans = false;
                break;
            }
        }
        if ( ans ) cout << "YES\n";
        else cout << "NO\n";
    }
}