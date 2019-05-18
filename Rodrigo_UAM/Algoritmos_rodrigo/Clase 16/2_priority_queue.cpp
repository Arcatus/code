// este programa ejemplifica el uso de priority_queue
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int main( )
{
   priority_queue<int> q;
   q.push(3);
   q.push(1);
   q.push(4);
   q.push(1);
   cout << q.top( ) << "\n";
   q.push(5);
   q.push(9);
   q.push(2);
   q.push(7);
   cout << q.top( ) << "\n";
   cout << "---\n";

   while (!q.empty( )) {
      cout << q.top( ) << "\n";
      q.pop( );
   }
}

