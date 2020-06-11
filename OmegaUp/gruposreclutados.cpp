#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x;
    char opcion;
    string s;
    queue<string> nombres;
    while(cin >> opcion) {
        if(opcion == 'R') {
            cin >> s;
            nombres.push(s);
        } else {
            cin >> x;
            if (nombres.size() >= x) {
                for(int i=0; i<x; ++i) {
                    cout << nombres.front() << ' ';
                    nombres.pop();
                }
                cout << '\n';
            } else {
                cout << "IMPOSIBLE\n";
            }
        }
    }
    return 0;
}
