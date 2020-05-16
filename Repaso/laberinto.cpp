#include <bits/stdc++.h>

using namespace std;

struct position {
    int y, x, lobos;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int L;
    cin >> L;
    int n;
    cin >> n;
    char lab[n][n];
    position entrada;
    for(int i=0; i<n; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> lab[i][j];
            if (lab[i][j] == 'E') {
                entrada.y = i;
                entrada.x = j;
                entrada.lobos = 0;
            }
        }
    }
    vector<position> actual = { entrada };
    int dx[] = {1, 0, -1, 0 };
    int dy[] = {0, 1, 0, -1 };
    int lob[n][n] =  { };    
    for (int i=0; i<n; ++i) {
	    for(int j=0; j<n; ++j) {
			lob[i][j] = INT_MAX;
		}
	}

    lob[entrada.y][entrada.x] = 0;
    for(int k = 0; !actual.empty(); ++k ) {
        vector<position> siguiente;
        for(position i: actual) {
            if ( lab[i.y][i.x] == 'S' ) {
                cout << k << '\n';
                return 0;
            }
            for(int j=0; j<4; ++j) {
                if ( 0 <= i.y+dy[j] && i.y+dy[j] < n && 
					 0 <= i.x+dx[j] && i.x+dx[j] < n && 
					 lab[i.y+dy[j]][i.x+dx[j]] != '#' ) {

                    position tmp = { i.y + dy[j], i.x + dx[j], i.lobos + (lab[i.y + dy[j]][i.x + dx[j]] == '*') };
                    if ( tmp.lobos <= L && tmp.lobos < lob[i.y + dy[j]][i.x + dx[j]] ) {
                        siguiente.push_back(tmp);
                        lob[i.y + dy[j]][i.x + dx[j]] = tmp.lobos;
                    }
                }
            }
        }
        actual.swap(siguiente);
    }
    cout << -1 << '\n';
    return 0;
}