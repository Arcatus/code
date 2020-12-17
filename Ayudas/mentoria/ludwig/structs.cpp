#include <iostream> // cout
#include <vector> // vector
#include <algorithm> //necesario para sort

using namespace std;
using ll = long long;

// en c++ no hace falta usar typedef
// puedes armar tu struct con lo que sea que quieras, 
// incluso meter estructuras como listas, vector o maps

struct alumno {
    int id;
    string nombre;
    float calificacion;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // elemntos unicos
    alumno a;
    a.id = 0;
    a.calificacion = 10.0f;
    a.nombre = "Carlos Ramirez";

    cout << a.id << " " << a.nombre << " " << a.calificacion << '\n';

    // con vectors
    vector<alumno> alumnos;
    //staticos
    alumno alumnos2[20];
    //dinamicos
    alumno* alumnos3 = new alumno[20];

    // aniadimos a vector
    alumnos.push_back(alumno{1, "Carlos Ramirez",10.0f});

    cout << alumnos[0].id << " " << alumnos[0].nombre << " " << alumnos[0].calificacion << '\n';

    // aniadimos a staticos
    alumnos2[0] = alumno{2, "Carlos Ramirez",10.0f};

    cout << alumnos2[0].id << " " << alumnos2[0].nombre << " " << alumnos2[0].calificacion << '\n';

    // aniadimos a dinamicos
    alumnos3[0].id = 3;
    alumnos3[0].nombre = "Carlos Ramirez";
    alumnos3[0].calificacion = 10.0f;

    cout << alumnos3[0].id << " " << alumnos3[0].nombre << " " << alumnos3[0].calificacion << '\n';

    // usando apuntadores

    alumno *ptrAlumno = &alumnos2[0];

    cout << ptrAlumno->id << " " << ptrAlumno->nombre << " " << ptrAlumno->calificacion << '\n';

    // podemos ordenarlos, anidadimos 2 mas de ejemplo, 
    // la lambda puede ser bastante compleja este solo es un ejemplo
    
    alumnos.push_back(alumno{2, "Juan Perez", 9.3f});
    alumnos.push_back(alumno{3, "Raul Jimenez", 8.1f});

    sort(alumnos.begin(), alumnos.end(), [](alumno a, alumno b) {
        return a.calificacion < b.calificacion; // ordena de menor calificacion a mayor
    });

    for(auto i : alumnos) {
        cout << i.id << " " << i.nombre << " " << i.calificacion << '\n';
    }

    return 0;
}