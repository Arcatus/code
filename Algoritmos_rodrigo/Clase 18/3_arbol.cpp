// este programa ejemplifica una implementaci�n de un �rbol binario de b�squeda
#include <algorithm>
#include <iostream>
using namespace std;

struct nodo {
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
   } else if (v < n->valor) {
      inserta(n->izq, v);
   } else {
      inserta(n->der, v);
   }
}

int altura(nodo* n)                 // devuelve la altura del �rbol a partir del nodo n
{
   if (n == nullptr) {              // si realmente no apuntamos a un nodo, no hay �rbol a partir de ah�
      return 0;                     // y el �rbol es de altura 0
   } else {
      return max(altura(n->izq), altura(n->der)) + 1;       // calculamos la altura de ambos lados, obtenemos el m�ximo y sumamos 1 porque nosotros estamos arriba de ellos
   }
}

int nodos(nodo* n)                 // devuelve el n�mero de nodos del �rbol a partir del nodo n
{
   if (n == nullptr) {              // si realmente no apuntamos a un nodo, no hay �rbol a partir de ah�
      return 0;                     // y el �rbol tiene 0 nodos
   } else {
      return nodos(n->izq) + nodos(n->der) + 1;       // calculamos el n�mero de nodos de ambos lados y sumamos 1 porque nosotros tambi�n contamos
   }
}

void inserta(arbol& a, int v)
{
   inserta(a.raiz, v);
}

int altura(const arbol& a)    // cuando nos piden la altura de un �rbol, contamos desde la ra�z
{
   return altura(a.raiz);
}

int nodos(const arbol& a)     // cuando nos piden contar los nodos de un �rbol, contamos desde la ra�z
{
   return nodos(a.raiz);
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

   cout << nodos(a) << " nodos en el arbol\n";
   cout << altura(a) << " de altura\n";
}
