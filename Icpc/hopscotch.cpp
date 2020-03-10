#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cmath>
#include <limits.h>

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

    int ans = INT_MAX;

    int distancias[k+1];

    fill(distancias, distancias+k+1, INT_MAX );

    while( !cola.empty() ) {

        posicion v = cola.top();
        cola.pop();

        if ( v.k == k ) {
            //cout << v.distancia << '\n';            
            ans = min( v.distancia, ans );
            continue;
        }

        {
            int mindis = INT_MAX;
            pair<int,int> posnew;
            for(int j=0; j < reach[v.k + 1].size(); ++j) {
                int dist = v.distancia + abs( v.ubicacion.first - reach[ v.k+1 ][j].first )
                    + abs( v.ubicacion.second - reach[ v.k+1 ][j].second );
                if ( dist < mindis ) {
                    posnew = reach[v.k+1][j];
                    mindis = dist;
                }
            }

            if( reach[v.k+1].size() > 0 )
                cola.push( posicion{ v.k + 1, posnew, mindis } );
        }
    }
    if ( ans == INT_MAX ) cout << -1 << '\n';
    else cout << ans << '\n';
}