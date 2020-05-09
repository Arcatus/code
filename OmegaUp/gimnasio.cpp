#include <bits/stdc++.h>

using namespace std;

struct maquina {
    int t_uso;
    int t_enfriamiento;
} M[10];

struct vecinos {
    int t_uso, t_enfriamiento, t_inicio;
} N[10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0; i<10; ++i) {
        cin >> M[i].t_uso >> M[i].t_enfriamiento;
    }
    int u, r, t;
    int inicio[10] = { };
    for(int i=0; i<10; ++i) {
        cin >> N[i].t_uso >> N[i].t_enfriamiento >> N[i].t_inicio;
        inicio[i] = N[i].t_inicio;
    }
    int tiempo_global = 0;
    int maquina_actual = 0;
    int cantidad_usos[10] = { };
    function<bool(int, int)> disponible = [&](int k, int t) {
        if ( t < inicio[k] ) {
            return true;
        } else {
            return ( ((t - N[k].t_inicio) % (N[k].t_uso +  N[k].t_enfriamiento) ) < N[k].t_uso ) ? false : true;
        }
    };      
    while( cantidad_usos[9] < 3 ) {
        if ( disponible(maquina_actual, tiempo_global) ) {
           cantidad_usos[maquina_actual]++;
           tiempo_global += M[maquina_actual].t_uso;
           for(int i=tiempo_global-M[maquina_actual].t_uso+1; i<=tiempo_global;++i) {
              if ( !disponible(maquina_actual,i) ) {
                   N[maquina_actual].t_inicio = tiempo_global;
                   break;
               } 
               //else { i+= N[maquina_actual].t_enfriamiento/10; }
            }
            tiempo_global += M[maquina_actual].t_enfriamiento;
            maquina_actual = (maquina_actual+1) % 10 ;
        } else {
            int espera = N[maquina_actual].t_uso - 
                ((tiempo_global - N[maquina_actual].t_inicio) % (N[maquina_actual].t_uso+N[maquina_actual].t_enfriamiento));
            tiempo_global += espera;
        }        
    }
    cout << tiempo_global - M[9].t_enfriamiento << '\n';
    return 0;
}