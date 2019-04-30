#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<int,string> tabla;

    tabla.emplace(614,"Chihuahua");
    tabla.emplace(621,"Saucillo");
    tabla.emplace(625,"Cuauhtemoc");
    tabla.emplace(626,"Coyame");
    tabla.emplace(627,"Parral");
    tabla.emplace(628,"Santa Barbara");
    tabla.emplace(629,"Jimenez");
    tabla.emplace(635,"Creel");
    tabla.emplace(636,"Casas Grandes");
    tabla.emplace(639,"Delicias");
    tabla.emplace(648,"Camargo");
    tabla.emplace(649,"Guachochi");
    tabla.emplace(652,"Madera");
    tabla.emplace(656,"Juarez");
    tabla.emplace(659,"Bachiniva");
    
    int n;
    cin >> n;

    if (tabla.count(n) > 0)
    {
    	cout << tabla[n] << '\n';
    }

    return 0;
}