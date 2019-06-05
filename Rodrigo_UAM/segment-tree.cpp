#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

template<typename T, typename F>
class segment_tree {
public:
   segment_tree(T n = { }, F f = { })
   : pisos(1), neutro(std::move(n)), funcion(std::move(f)) {
   }

   int size( ) const {
      return pisos[0].size( );
   }

   void update(T v, int i) {
      for (int p = 0;; ++p, i /= 2) {
         pisos[p][i] = std::move(v);
         if (i + (i % 2 == 0) == pisos[p].size( )) {
            break;
         }
         v = funcion(pisos[p][i - i % 2], pisos[p][i - i % 2 + 1]);
      }
   }

   void push_back(T v) {
      for (int p = 0;; ++p, pisos.resize(std::max(p + 1, int(pisos.size( ))))) {
         pisos[p].push_back(std::move(v));
         if (pisos[p].size( ) % 2 == 1) {
            break;
         }
         v = funcion(*(pisos[p].end( ) - 2), *(pisos[p].end( ) - 1));
      }
   }

   void pop_back( ) {
      for (int p = 0; p < pisos.size( ); ++p) {
         pisos[p].pop_back( );
         if (pisos[p].size( ) % 2 == 0) {
            break;
         }
      }
   }

   T query(int ini, int fin) const {
      return query(ini, fin, pisos.size( ) - 1);
   }

   std::vector<const T*> visit(int ini, int fin) const {
      std::vector<const T*> res;
      visit(ini, fin, pisos.size( ) - 1, res);
      return res;
   }

private:
   T query(int ini, int fin, int p) const {
      if (ini == fin) {
         return neutro;
      } else {
         int grupo = 1 << p, xi = ini / grupo + bool(ini % grupo), xf = fin / grupo;
         if (xi < xf && xf <= pisos[p].size( )) {
            return funcion(std::accumulate(pisos[p].begin( ) + xi, pisos[p].begin( ) + xf, neutro, funcion), funcion(query(ini, xi * grupo, p - 1), query(xf * grupo, fin, p - 1)));
         } else {
            return query(ini, fin, p - 1);
         }
      }
   }

   void visit(int ini, int fin, int p, std::vector<const T*>& v) const {
      if (ini == fin) {
         return;
      } else {
         int grupo = 1 << p, xi = ini / grupo + bool(ini % grupo), xf = fin / grupo;
         if (xi < xf && xf <= pisos[p].size( )) {
            std::for_each(pisos[p].begin( ) + xi, pisos[p].begin( ) + xf, [&](const T& actual) {
               v.push_back(&actual);
            });
            visit(ini, xi * grupo, p - 1, v);
            visit(xf * grupo, fin, p - 1, v);
         } else {
            visit(ini, fin, p - 1, v);
         }
      }
   }

   std::vector<std::vector<T>> pisos;
   F funcion;
   T neutro;
};

int main( ) {
   segment_tree<int, std::plus<int>> s;
   for (int i = 0; i < 50; ++i) {
      s.push_back(i);
   }

   std::cout << s.query(5, 10) << "\n";
   for (auto p : s.visit(5, 10)) {
      std::cout << *p << " ";
   }
}