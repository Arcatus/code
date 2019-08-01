#include <iostream>
#include <climits>
#include <set>

using namespace std;

int tablero[1000][1000];
int distancias[1000][1000];

struct celda
{
    int x;
    int y;
    int distancia;
};

bool operator<(const celda& a, const celda& b) 
{ 
    if (a.distancia == b.distancia) {
        if (a.x != b.x) 
            return a.x < b.x;
        else
            return a.y < b.y;
    }
    return a.distancia < b.distancia;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;

    cin >> n >> m;

    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> tablero[i][j];
            distancias[i][j] = INT_MAX;
        }
    }
    int dx[] = {-1, 0, 1, 0}; 
    int dy[] = {0, 1, 0, -1};

    set<celda> st;

    st.insert( { 0, 0, 0 } );

    distancias[0][0] = tablero[0][0];

    while( !st.empty() )
    {
        celda k = *st.begin();
        st.erase(st.begin());
        
        for (int i=0; i<4; ++i) {

            int x = k.x + dx[i];
            int y = k.y + dy[i];

            if ( 0 <= x && x < n && 0 <= y && y < m ) {
                if ( distancias[k.x][k.y] + tablero[x][y] < distancias[x][y] ) {
                    if ( distancias[x][y] != INT_MAX ) {
                        if (!st.empty()) {
                            st.erase(st.find( { x, y, distancias[x][y] } ));
                        }
                    }
                    distancias[x][y] = distancias[k.x][k.y] + tablero[x][y];
                    st.insert( {x, y, distancias[x][y] } );
                }
            }
        }
    }
    cout << distancias[n-1][m-1] << '\n';
}