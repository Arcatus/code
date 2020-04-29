#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    for(int i=0; i<n; ++i) {
        cin >> a[i];
    }
    for(int i=0; i<n; ++i) {
        cin >> b[i];
    }
    vector<int> p;
    vector<int> al;
    int x, y;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            if (i == j ) continue;
            p.push_back( a[x]+a[y]);
            al.push_back( b[x]+b[y]);
        }
    }   
    sort(p.begin(),p.end());
    sort(al.begin(),al.end());

    cerr << "p :" << p.size() << '\n';
    cerr << "al :"<< al.size() << '\n';

    int ans = 0;
    for(int i=0; i<p.size(); ++i) {
        int x = p[i];
        ans += lower_bound(al.begin(),al.end(),x) - al.begin();
    }
    cout << ans << '\n';
}