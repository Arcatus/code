// este programa ejemplifica una implementaci�n de un �rbol binario de b�squeda
// esta es la implementaci�n es iterativa y es la que estaba intentando hacer en los �ltimos minutos de la clase, pero estaba cometiendo un error
#include <iostream>
using namespace std;

struct nodo {                       // cada nodo del �rbol guarda un valor y dos apuntadores
   int valor;                       // uno al hijo izquierdo (opcional, puede ser nulo)
   nodo* izq = nullptr;             // y el otro al hijo derecho (opcional, puede ser nulo)
   nodo* der = nullptr;
};

struct arbol {
   nodo* raiz = nullptr;            // un �rbol guarda un apuntador a su nodo ra�z (el �rbol est� vac�o si el apuntador es nulo)

   void inserta(int v)
   {
      nodo** actual = &raiz;        // con el apuntador a apuntador vamos seleccionado qu� enlace hay que modificar para que apunte al nuevo nodo
      while (*actual != nullptr) {  // bajaremos por el �rbol mientras no encontremos un espacio libre
         actual = (v < (*actual)->valor ? &(*actual)->izq : &(*actual)->der);
      }
      *actual = new nodo{v};        // ya encontrado el espacio libre, el nuevo nodo lo creamos ah�
   }

   bool busca(int v)
   {
      nodo* actual = raiz;          // con el apuntador vamos seleccionado qu� nodo es el siguiente por revisar
      while (actual != nullptr) {   // bajaremos por el �rbol mientras no encontremos no lleguemos a un espacio vac�o y mientras no encontremos el valor buscado
         if (v == actual->valor) {  // en cuanto encontramos el valor buscado, regresamos true y terminamos
            return true;
         } else {
            actual = (v < actual->valor ? actual->izq : actual->der);
         }
      }
      return false;                 // si ya llegamos a un espacio vac�o y jam�s encontramos el valor buscado, es que no est�
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
