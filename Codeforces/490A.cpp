#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n;
    queue<int> p1, p2, p3; 
    for(int i = 1; i <= n; ++i) {
        cin >> t;
        if(t == 1) {
            p1.push(i);
        } else if(t == 2) {
            p2.push(i);
        } else {
            p3.push(i);
        }
    }
    cout << min(min(p1.size(), p2.size()), p3.size()) << '\n';
    while(p1.size() > 0 && p2.size() > 0 && p3.size() > 0) {
        cout << p1.front() << " " << p2.front() << " " << p3.front() << '\n';
        p1.pop(); p2.pop(); p3.pop();
    }
    return 0;
}