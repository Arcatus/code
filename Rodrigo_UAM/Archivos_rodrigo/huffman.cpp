#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct nodo {
   char simbolo;
   int peso;
   nodo* izq;
   nodo* der;
};

bool compara_nodo(nodo* p1, nodo* p2) {
   return p1->peso > p2->peso;
}

void imprime(nodo* p, string s) {
   if (p->izq == nullptr && p->der == nullptr) {
      cout << p->simbolo << ": " << s << "\n";
   } else {
      imprime(p->izq, s + "0");
      imprime(p->der, s + "1");
   }
}

int main( ) {
   string s;
   cin >> s;

   int frecuencia[256] = { };
   for (int i = 0; i < s.size( ); ++i) {
      frecuencia[s[i]] += 1;
   }

   nodo nodos[512];
   nodo* monticulo[256];
   int usados = 0, activos = 0;
   for (int i = 0; i < 256; ++i) {
      if (frecuencia[i] != 0) {
         nodos[usados] = { char(i), frecuencia[i], nullptr, nullptr };
         monticulo[activos++] = &nodos[usados++];
      }
   }

   make_heap(monticulo, monticulo + activos, compara_nodo);
   while (activos != 1) {
      nodo* p1 = monticulo[0];
      pop_heap(monticulo, monticulo + activos--, compara_nodo);
      nodo* p2 = monticulo[0];
      pop_heap(monticulo, monticulo + activos--, compara_nodo);
      nodos[usados] = { '\0', p1->peso + p2->peso, p1, p2 };
      monticulo[activos++] = &nodos[usados++];
      push_heap(monticulo, monticulo + activos, compara_nodo);
   }

   imprime(monticulo[0], "");
}
