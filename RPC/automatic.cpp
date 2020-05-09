#include <bits/stdc++.h>

using namespace std;

struct slot {
    int a, b;
};

struct coin {
    int th, mass;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int s;
    cin >> s;
    slot a[s];
    for(int i=0; i<s; ++i) {
        cin >> a[i].a >> a[i].b;
    }
    int c;
    cin >> c;
    
    return 0;
}