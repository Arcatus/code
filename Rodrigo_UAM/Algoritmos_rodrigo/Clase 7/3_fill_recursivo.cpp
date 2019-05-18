#include <iostream>
using namespace std;

void fill(int* ini, int* fin, int v)
{
   if (ini == fin) {
      return;
   } else {
      *ini = v;
      fill(ini + 1, fin, v);
   }
}

int main( )
{
   int arr[5];
   fill(&arr[0], &arr[5], 2);
   for (int i = 0; i < 5; ++i) {
      cout << arr[i] << " ";
   }

/*
   fill(&arr[0], &arr[5], 2) escribe en *ini y delega -->
      fill(&arr[1], &arr[5], 2) escribe en *ini y delega -->
         fill(&arr[2], &arr[5], 2) escribe en *ini y delega -->
            fill(&arr[3], &arr[5], 2) escribe en *ini y delega -->
               fill(&arr[4], &arr[5], 2) escribe en *ini y delega -->
                  fill(&arr[5], &arr[5], 2) termina
*/

}


