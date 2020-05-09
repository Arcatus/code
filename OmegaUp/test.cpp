#include <bits/stdc++.h>

using namespace std;

struct curso {
    int id, k;
    vector<int> duras;
    vector<int> suaves;
};

bool operator <(curso a, curso b) {
    return a.k > b.k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    priority_queue< curso > q;
    int x; string opc;
    curso a[1000+1];
    for(int i=0; i<n; ++i) {
        curso t;
        cin >> t.id >> t.k;
        a[i].id = t.id;
        a[i].k = t.k;
        for(int j=0; j<t.k; ++j) {
            cin >> opc;
            if ( opc[0] == '~' ) {
                x = stoi(opc.substr(1,opc.size()-1), nullptr, 10);
                t.suaves.push_back(x);
                a[t.id].suaves.push_back(x);
            } else {
                x = stoi(opc, nullptr, 10);
                t.duras.push_back( x );
                a[t.id].duras.push_back(x);
            }
        }
        q.push(t);
    }    
    int m;
    cin >> m;
    bool aprobadas[1000+1] = { };
    for(int i=0; i<m; ++i) {
        cin >> x;
        aprobadas[x] = true;
    }  
    function<bool(int, int)> check = [&](int k, int ini) {
        if ( k == ini ) return false;
        for(int i=0; i<a[k].duras.size(); ++i) {
            if ( !aprobadas[ a[k].duras[i] ] ) {
                return false;
            }
        }
        for(int i=0; i<a[k].suaves.size(); ++i) {
            if ( !check( a[k].suaves[i], ini ) ) {
                return false;
            }
        }
        return true;
    };
    set<int> ans;
    while( !q.empty() ) {
        curso v = q.top();
        q.pop();
        if ( aprobadas[v.id] ) {
            continue;
        }
        bool req = true;
        for(int i=0; i<v.duras.size(); ++i) {
            if ( !aprobadas[ v.duras[i] ] ) {
                req = false; break;
            }
        }
        for(int i=0; i<v.suaves.size(); ++i) {
            if ( !check( v.suaves[i], v.id ) ) {
                req = false; break;
            }
        }
        if ( req ) {
            ans.insert(v.id);
        }
    }
    for(auto i = ans.begin(); i != ans.end(); ++i ) cout << *i << ' '; cout << '\n';
    return 0;
}