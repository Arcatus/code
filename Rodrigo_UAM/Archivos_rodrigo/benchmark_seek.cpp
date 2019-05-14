#include <algorithm>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <numeric>
#include <vector>

int main( ) {
   FILE* archivo = std::fopen("archivo.txt", "r");
   if (archivo == nullptr) {
      return std::cout << "No se pudo abrir el archivo\n", 0;
   }

   std::fseek(archivo, 0, SEEK_END);
   auto tam = std::ftell(archivo);
   std::rewind(archivo);

   char buffer[4096];
   std::vector<long> orden(tam / sizeof(buffer));
   std::iota(orden.begin( ), orden.end( ), 0);
   std::cout << "Desea revolver los accesos? 1/0: ";
   bool revolver; std::cin >> revolver;
   if (revolver) {
      std::random_shuffle(orden.begin( ), orden.end( ));
   }

   std::cout << "Lectura: ";
   std::clock_t t0 = std::clock( );
   for (auto p : orden) {
      std::fseek(archivo, p * sizeof(buffer), SEEK_SET);
      std::fread(buffer, 1, sizeof(buffer), archivo);
   }
   std::clock_t t1 = std::clock( );
   std::cout << double(t1 - t0) / CLOCKS_PER_SEC << "\n";

   std::fclose(archivo);
}
