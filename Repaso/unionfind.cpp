#include <iostream>
#include <algorithm>

using namespace std;

int _rank[100000+1];
int parent[100000+1];

int findSet(int k) {
    return k == parent[k] ? k : parent[k] = findSet(parent[k]);
}

bool sameSet(int a, int b)
{
    return findSet(a) == findSet(b);
}

void unionSet(int a, int b)
{
    a = findSet(a); b = findSet(b);

    if ( _rank[a] != _rank[b] ) {
        if ( _rank[a] > _rank[b] ) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    } else {
        _rank[a]++;
        parent[b] = a;
    }
}

int main()
{
    ios::sync_with_stdio(false);    
    cin.tie(0); cout.tie(0);

    int n, m;

    cin >> n >> m;

    for(int i=0; i<n; ++i) {
        parent[i] = i, _rank[i] = 0;
    }

    char opcion;
    int a, b;
    for(int i=0; i<m; ++i) {
        cin >> opcion;
        if ( opcion == 'P' ) {
            cin >> a >> b;
            cout << sameSet(a,b) << '\n';
        } else {
            cin >> a >> b;
            if ( !sameSet(a,b) ) {
                unionSet(a,b);
            }
        }
    }
}