// este programa ejemplifica una implementaci�n de un �rbol binario de b�squeda
// esta es la implementaci�n es iterativa y es la que estaba intentando hacer en los �ltimos minutos de la clase, pero estaba cometiendo un error
#include <iostream>
using namespace std;                // �lo vemos la pr�xima clase! (y agrego los comentarios)

struct nodo {                       // termin� por cambiarle el nombre de subarbol a nodo
   int valor;
   nodo* izq = nullptr;
   nodo* der = nullptr;
};

struct arbol {
   nodo* raiz = nullptr;

   void inserta(int v)
   {
      nodo** actual = &raiz;
      while (*actual != nullptr) {
         actual = (v < (*actual)->valor ? &(*actual)->izq : &(*actual)->der);
      }
      *actual = new nodo{v};
   }

   bool busca(int v)
   {
      nodo* actual = raiz;
      while (actual != nullptr) {
         if (v == actual->valor) {
            return true;
         } else {
            actual = (v < actual->valor ? actual->izq : actual->der);
         }
      }
      return false;
   }
};

int main( )
{
   arbol a;
   a.inserta(5);
   a.inserta(3);
   a.inserta(7);
   a.inserta(1);
   a.inserta(8);
   a.inserta(4);

   for (int i = 0; i <= 10; ++i) {
      cout << i << ": " << a.busca(i) << "\n";
   }
}
