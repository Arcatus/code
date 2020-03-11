#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n; 

    cin >> n;

    int a[5000+1];

    fill(a,a+5001,-1);

    for(int i=1; i<=n; ++i) {
        cin >> a[i];
    }

    for(int i=1; i<=n; ++i) {
        //cerr << a[i] << " " <<  a[ a[i] ] << " " << i << '\n';
        if( i == a[ a[ a[i] ] ] ) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}