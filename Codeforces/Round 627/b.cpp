#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int t;

    cin >> t;

    for(int i=0; i<t; ++i) {
        int n, s;
        cin >> n;
        multiset<int> a;
        vector< vector<int> > posiciones(n+1);
        for(int k=0; k<n; ++k) {
            cin >> s;
            a.insert(s);
            posiciones[s].push_back(k);
        }
        bool ans = false;
        for(int h=1; h<=n; ++h) {
            if ( a.count(h) >= 2 ) {
                if ( abs( posiciones[h][0] - posiciones[h][a.count(h)-1] ) != 1 ) {
                        ans = true;
                        break;
                }
            }
        }
        if ( ans ) cout << "YES\n";
        else cout << "NO\n";
    }
}