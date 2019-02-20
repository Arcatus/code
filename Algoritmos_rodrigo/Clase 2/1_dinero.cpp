// https://omegaup.com/arena/problem/Quien-tiene-mas-dinero#problems
#include <cstdio>

int main( )
{
   int j1, j2, j3, p1, p2;
   std::scanf("%d%d%d%d%d", &j1, &j2, &j3, &p1, &p2);

   if (j1 + j2 + j3 > p1 + p2) {
      std::printf("Juan");
   } else {
      std::printf("Pedro");
   }
}
