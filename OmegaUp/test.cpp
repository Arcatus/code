#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i = 10, a;
    a = i++ / ++i;
    printf("%d ... %d", a, i);
    return 0;
}