#include <iostream>

struct nodo {
   int valor;
   nodo* ant;
   nodo* sig;
};

struct apuntaNodo {
   nodo* posicion;
   nodo* ant;
   nodo* sig;
};

int main( ) {
   std::ios::sync_with_stdio(false);
   std::cin.tie(0); std::cout.tie(0);

   int n;
   std::cin >> n;

   nodo* ini = nullptr;
   nodo* ult = nullptr;

   char opc[13];

   for (int i = 0; i < n; ++i) {

      int valor;

      std::cin >> opc >> valor;

      if (opc[7] == 'I')
      {
         nodo* p = new nodo{valor, nullptr, nullptr};

         if (ini == nullptr) {
            ini = p;
            ult = p;
         } else {
            ini->ant = p;
            p->sig = ini;
            ini = p;
         }
         if ( localizadorIzq[valor] == nullptr )
         {
            
         }
      }
      else if (opc[7] == 'D')
      {
         nodo* p = new nodo{valor, nullptr, nullptr};

         if (ini == nullptr) {
            ini = p;
            ult = p;
         } else {
            ult->sig = p;
            p->ant = ult;
            ult = p;
         }
      }
      else if (opc[6] == 'P')
      {
            for (nodo* p = ini; p != nullptr; p = p->sig) {
               if (p->valor == valor ) {
                  if (p->ant != nullptr) {
                     p->ant->sig = p->sig;
                  }
                  if (p->sig != nullptr) {
                     p->sig->ant = p->ant;
                  }
                  if (ini == p) {
                     ini = p->sig;
                  }
                  if (ult == p) {
                     ult = p->ant;
                  }
                  delete p;
                  break;
               }
            }
      } 
      else 
      {
            for (nodo* p = ult; p != nullptr; p = p->ant) {
               if ( p->valor == valor ) {
                  if (p->ant != nullptr) {
                     p->ant->sig = p->sig;
                  }
                  if (p->sig != nullptr) {
                     p->sig->ant = p->ant;
                  }
                  if (ini == p) {
                     ini = p->sig;
                  }
                  if (ult == p) {
                     ult = p->ant;
                  }
                  delete p;
                  break;
               }
            }
      }
   }
   for (nodo* p = ini; p != nullptr; p = p->sig) {
        std::cout << p->valor << " ";
   }
   std::cout << "\n";
}