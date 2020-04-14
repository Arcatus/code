#include <bits/stdc++.h>
#include "fairworkload.h"

using namespace std;

int main() {
    vector<int> s = {722, 235, 642, 251, 105, 860, 532, 980, 483, 256, 226, 256, 799, 761, 200};
    int w = 9;
    int ans = FairWorkload::getMostWork(s,w);
    cout << ans << '\n';
}
