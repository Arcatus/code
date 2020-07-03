#include <bits/stdc++.h>

using namespace std;

struct punto
{
    double x, y;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    punto a[n];
    for(int i=0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }   
    int b[n];
    for(int i=0; i<n; ++i) cin >> b[i];
    
    return 0;
}