// este programa ejemplifica una implementación de un árbol binario de búsqueda (ligeramente simplificado usando la expresión ternaria)
// esta implementación es recursiva, es más fácil de entender que la iterativa que estaba intentando hacer los últimos minutos de la clase
#include <iostream>
using namespace std;

struct nodo {                       // cada nodo del árbol guarda un valor y dos apuntadores
   int valor;                       // uno al hijo izquierdo (opcional, puede ser nulo)
   nodo* izq = nullptr;             // y el otro al hijo derecho (opcional, puede ser nulo)
   nodo* der = nullptr;
};

struct arbol {
   nodo* raiz = nullptr;            // un árbol guarda un apuntador a su nodo raíz (el árbol está vacío si el apuntador es nulo)
};

void inserta(nodo*& n, int v)       // tomamos el apuntador por referencia, si es modificado entonces el llamante podrá ver el cambio
{
   if (n == nullptr) {              // nos piden insertar y llegamos a un apuntador nulo, entonces el nuevo nodo lo creamos ahí
      n = new nodo{v};              // la sintaxis nodo{v} inicializa directamente los miembros del struct (cero o nulo para los miembros no mencionados)
   } else {                         // si n apunta a un nodo ya creado, entonces bajamos por el lado izquierdo si el valor que queremos insertar es menor al del nodo actual, en otro caso bajamos por la derecha
      inserta((v < n->valor ? n->izq : n->der), v);
   }
}

bool busca(const nodo* n, int v)    // tomamos el apuntador por valor, es barato de copiar y no necesitamos modificarlo
{
   if (n == nullptr) {              // nos piden buscar y llegamos a un apuntador nulo, entonces el valor no está
      return false;
   } else if (v == n->valor) {      // si n apunta a un nodo ya creado que tiene el valor buscado, devolvemos que ya lo encontramos
      return true;
   } else {                         // si n apunta a un nodo ya creado, entonces bajamos por el lado izquierdo si el valor que buscamos es menor al del nodo actual, en otro caso bajamos por el lado derecho
      return busca((v < n->valor ? n->izq : n->der), v);
   }
}

void inserta(arbol& a, int v)       // cuando nos piden insertar un nuevo elemento a un árbol, delegamos a la función que toma un apuntador a nodo y mandamos la raíz
{
   inserta(a.raiz, v);
}

bool busca(const arbol& a, int v)   // cuando nos piden buscar un valor en un árbol, delegamos a la función que toma un apuntador a nodo y mandamos la raíz
{
   return busca(a.raiz, v);
}

int main( )
{
   arbol a;
   inserta(a, 5);
   inserta(a, 3);
   inserta(a, 7);
   inserta(a, 1);
   inserta(a, 8);
   inserta(a, 4);

   for (int i = 0; i <= 10; ++i) {
      cout << i << ": " << busca(a, i) << "\n";
   }
}
