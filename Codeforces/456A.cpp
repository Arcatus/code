#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct laptop {
    int q, p;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;  
    cin >> n;
    laptop a[n];
    for(int i = 0; i < n; ++i) {
        cin >> a[i].p >> a[i].q;
    }
    sort(a, a + n, [](laptop a, laptop b) {
        return a.p > b.p;
    });
    int q = a[0].q;
    for(int i = 1; i < n; ++i) {
        if(a[i].q > q) {
            cout << "Happy Alex\n";
            return 0;
        }
        q = min(q, a[i].q);
    }
    cout << "Poor Alex\n";
    return 0;
}