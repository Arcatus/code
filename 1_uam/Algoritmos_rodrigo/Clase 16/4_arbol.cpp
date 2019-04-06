// este programa ejemplifica una implementación de un árbol binario de búsqueda (ligeramente simplificado usando la expresión ternaria)
// esta implementación es recursiva, es más fácil de entender que la iterativa que estaba intentando hacer los últimos minutos de la clase
#include <iostream>
using namespace std;                // ¡lo vemos la próxima clase! (y agrego los comentarios)

struct nodo {                       // terminé por cambiarle el nombre de subarbol a nodo
   int valor;
   nodo* izq = nullptr;
   nodo* der = nullptr;
};

struct arbol {
   nodo* raiz = nullptr;
};

void inserta(nodo*& n, int v)
{
   if (n == nullptr) {
      n = new nodo{v};
   } else {
      inserta((v < n->valor ? n->izq : n->der), v);
   }
}

bool busca(const nodo* n, int v)
{
   if (n == nullptr) {
      return false;
   } else if (v == n->valor) {
      return true;
   } else {
      return busca((v < n->valor ? n->izq : n->der), v);
   }
}

void inserta(arbol& a, int v)
{
   inserta(a.raiz, v);
}

bool busca(const arbol& a, int v)
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
