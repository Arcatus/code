#include <bits/stdc++.h>

using namespace std;

enum{POSITIVO, NEGATIVO};

struct interval {
    int x, y;
    bool signo;
};

class segmentManager {
    vector<interval> segments;
    segmentManager(int x, int y) {
        segments.push_back({x, y, POSITIVO});
    }
    bool addSegment(int x, int y) {
        vector<interval> tmp;
        for(int i = 0; i < segments.size(); ++i) {
            
        }
        return false;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    
    for(int i = 0; i < q; ++i) {
        char op;
        cin >> op;
        if(op == 'R') {
            int j, i1, i2;
            cin >> j >> i1 >> i2;

        } else {
            int i, j;
            cin >> i >> j;
        }
    }
    return 0;
}