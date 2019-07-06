#include <iostream>

struct nodo {
   int valor;
   nodo* ant;
   nodo* sig;
};

struct apuntaNodo {
   nodo* posicion;
   apuntaNodo* ant;
   apuntaNodo* sig;
};

int main( ) {
   std::ios::sync_with_stdio(false);
   std::cin.tie(0); std::cout.tie(0);

   int n;
   std::cin >> n;

   nodo* ini = nullptr;
   nodo* ult = nullptr;

   char opc[13];

   apuntaNodo* posIni[10];
   apuntaNodo* posFin[10];

   for (int i=0;i<10;++i) {
      posIni[i] = posFin[i] = nullptr;
   }

   for (int i = 0; i < n; ++i) {

      int valor;

      std::cin >> opc >> valor;

      if (opc[7] == 'I')
      {
         nodo* p = new nodo{ valor, nullptr, nullptr };

         if (ini == nullptr) {
            ini = p;
            ult = p;
         } else {
            ini->ant = p;
            p->sig = ini;
            ini = p;
         }

         apuntaNodo* ap = new apuntaNodo{ p, nullptr, nullptr };

         if ( posIni[valor] == nullptr ) {
            posIni[valor] = ap;
            posFin[valor] = ap;
         } else {
            posIni[valor]->ant = ap;
            ap->sig = posIni[valor];
            posIni[valor] = ap;
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

         apuntaNodo* ap = new apuntaNodo{ p, nullptr, nullptr };

         if ( posFin[valor] == nullptr ) {
            posIni[valor] = ap;
            posFin[valor] = ap;
         } else {
            posFin[valor]->sig = ap;
            ap->ant = posFin[valor];
            posFin[valor] = ap;
         }
      }
      else if (opc[6] == 'P')
      {
            if (posIni[valor]->posicion->ant != nullptr) {
               posIni[valor]->posicion->ant->sig = posIni[valor]->posicion->sig;
            }
            if (posIni[valor]->posicion->sig != nullptr) {
               posIni[valor]->posicion->sig->ant = posIni[valor]->posicion->ant;
            }
            if (ini == posIni[valor]->posicion) {
               ini = posIni[valor]->posicion->sig;
            }
            if (ult == posIni[valor]->posicion) {
               ult = posIni[valor]->posicion->ant;
            }

            delete posIni[valor]->posicion;

            if ( posIni[valor] == posFin[valor] )
            {
               posIni[valor] = nullptr;
               posFin[valor] = nullptr;
            }
            else 
            {
               posIni[valor] = posIni[valor]->sig;
               delete posIni[valor]->ant;
            }
      } 
      else 
      {
            if (posFin[valor]->posicion->ant != nullptr) {
               posFin[valor]->posicion->ant->sig = posFin[valor]->posicion->sig;
            }
            if (posFin[valor]->posicion->sig != nullptr) {
               posFin[valor]->posicion->sig->ant = posFin[valor]->posicion->ant;
            }
            if (ini == posFin[valor]->posicion) {
               ini = posFin[valor]->posicion->sig;
            }
            if (ult == posFin[valor]->posicion) {
               ult = posFin[valor]->posicion->ant;
            }

            delete posFin[valor]->posicion;
            
            if (  posIni[valor] == posFin[valor] )
            {
               posIni[valor] = nullptr;
               posFin[valor] = nullptr;
            }
            else 
            {
               posFin[valor] = posFin[valor]->ant;
               delete posFin[valor]->sig;
            }
      }
   }
   for (nodo* p = ini; p != nullptr; p = p->sig) {
        std::cout << p->valor << " ";
   }
   std::cout << "\n";
}