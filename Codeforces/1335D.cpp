#include <bits/stdc++.h>

using namespace std;

int sudoku[9+1][9+1];
pair<int,int> pos(int i, int j) {
    if ( i <= 2 && j <= 2 ) return {0,0};
    else if ( i <= 2 && j <= 5 ) return {0,3};
    else if ( i <= 2 && j <= 8 ) return {0,6};
    else if ( i <= 5 && j <= 2 ) return {3,0};
    else if ( i <= 5 && j <= 5 ) return {3,3};
    else if ( i <= 5 && j <= 8 ) return {3,6};
    else if ( i <= 8 && j <= 2 ) return {6,0};
    else if ( i <= 8 && j <= 5 ) return {6,3};
    else return {6,6};
}

int getFromGrid(int a, int b) {
    auto [x, y] = pos(a,b);
    for(int i=x; i<x+3; ++i) {
        for(int j=y; j<y+3; ++j) {
            if ( i != a && j != b ) {
                return sudoku[i][j];
            }
        }
    }    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n;
    cin >> t;
    while(t--) {
        string s;
        for(int i=0; i<9; ++i) {
            cin >> s;
            for(int j=0; j<9; ++j) {
                sudoku[i][j] = s[j]-'0';
            }
        }
        bool isv[9+1][9+1];
        for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j) {
            isv[i][j] = false;
        }
        int index=1;
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                if ( !isv[i][j] ) {
                    sudoku[i][j] = getFromGrid(i,j);
                    for(int k = 0; k<9; ++k) isv[i][k] = true;
                    for(int k = 0; k<9; ++k) isv[k][j] = true;
                    auto [x,y] = pos(i,j);
                    for(int k=x; k<x+3; ++k) {
                        for(int l=y; l<y+3; ++l) {
                            isv[k][l] = true;
                        }
                    }
                }
            }
        }
        
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                cout << sudoku[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}