#include <bits/stdc++.h>

using namespace std;
int n = 3;
vector<int> a;
void subsets(int k) {
    if (k == n+1) {
        for(int i: a) cout << i << ' '; cout << '\n';
        return;
    } else {
        a.push_back(k);
        subsets(k+1);
        a.pop_back();
        subsets(k+1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    subsets(1);
    return 0;
}