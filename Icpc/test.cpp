#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;


struct posicion
{
    int k;
    pair<int,int> ubicacion;
    int distancia;
};

bool operator<(const posicion& a, const posicion& b)
{   
    return a.distancia > b.distancia;
}

int main()
{   
    int n, k;

    cin >> n >> k;

    vector< vector< pair< int, int> > >  reach (n*n+1);

    priority_queue < posicion > cola;

    int val;

    for( int i=0; i<n; ++i  ) {
        for( int j=0; j<n; ++j  ) {
            cin >> val;
            reach[ val ].push_back( {i, j} );
            if ( val == 1 ) {
                cola.push( posicion{ 1, {i, j}, 0 } );
            }
        }
    }

    int ans = -1;

    while( !cola.empty() ) {
        posicion v = cola.top();
        cola.pop();

        if ( v.k == k ) {
            cout << v.distancia << '\n';
            return 0;
        }

        for(int j=0; j < reach[v.k + 1].size(); ++j) {
            cola.push( posicion{ v.k + 1, reach[v.k+1][j] ,
                v.distancia + abs( v.ubicacion.first - reach[ v.k+1 ][j].first ) +
                abs( v.ubicacion.second - reach[ v.k+1 ][j].second ) } );
        }

    }
    cout << ans << '\n';
}