#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int fila, columna;
    cin >> fila >> columna;

    int matriz[fila][columna];

    for (int i=0; i<fila; ++i) {
        for(int j=0; j<columna; ++j) {
            cin >> matriz[i][j];
        }
    }

    int costos[fila][columna];

    for (int i=0; i<fila; ++i) {
        for(int j=0; j<columna; ++j) {
            costos[i][j] = INT_MAX;
        }
    }

    int dx[] = { 1, 0, -1,  0 };
    int dy[] = { 0, 1,  0, -1 };

    vector< tuple<int,int,int> > actual;

    actual.push_back( make_tuple( 0, 0, 0 ) );

    costos[0][0] = matriz[0][0];

    for (int i=0; !actual.empty(); ++i )
    {
        vector< tuple<int,int,int> > siguiente;

        for (int k=0; k<actual.size(); ++k) {
            if ( get<0>(actual[k]) == fila-1 && get<1>(actual[k]) == columna-1 ) {
                cout << costos[fila-1][columna-1] << '\n';
                return 0;
            } 
            for (int f=0; f<4; ++f) {
                if ( 0 <= get<0>(actual[k]) + dy[f] && get<0>(actual[k]) + dy[f] < fila &&
                     0 <= get<1>(actual[k]) + dx[f] && get<1>(actual[k]) + dx[f] < columna && 
                      ( get<2>(actual[k]) + matriz[get<0>(actual[k])+dy[f]][get<1>(actual[k])+dx[f]] )
                      < costos[ get<0>(actual[k]) + dy[f] ][ get<1>(actual[k]) + dx[f] ]
                    )
                {
                    tuple<int, int, int > sig = make_tuple( 
                        get<0>(actual[k]) + dy[f],
                        get<1>(actual[k]) + dx[f],
                        get<2>(actual[k]) + matriz[get<0>(actual[k])+dy[f]][get<1>(actual[k])+dx[f]] );

                    siguiente.push_back( sig );

                    costos[ get<0>(actual[k]) + dy[f] ][ get<1>(actual[k]) + dx[f] ]
                      = get<2>(sig);
                }
            }
        }
        actual.swap(siguiente);
    }
}