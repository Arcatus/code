#include <bits/stdc++.h>

using namespace std;

struct nodo {
    int v, c;
};

bool operator <(nodo a, nodo b) {
    return a.c > b.c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    priority_queue<nodo> q;
    q.push({0, 0});
    q.push({1, 1});

    cout << q.top().v << '\n';

    return 0;
}
