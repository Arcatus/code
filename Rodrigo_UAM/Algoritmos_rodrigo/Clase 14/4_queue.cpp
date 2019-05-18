// ejemplo de uso de queue de C++
// push( ) y pop( ) equivalen a push_back( ) y pop_front( ) de deque
#include <deque>
#include <iostream>
#include <queue>
using namespace std;

int main( )
{
   deque<int> d;
   d.push_back(3);               // { 3 }
   cout << d.front( ) << " " << d.back( ) << "\n";
   d.push_back(1);               // { 3, 1 }
   cout << d.front( ) << " " << d.back( ) << "\n";
   d.push_back(7);               // { 3, 1, 7 }
   cout << d.front( ) << " " << d.back( ) << "\n";
   d.pop_front( );               // { 1, 7 }
   cout << d.front( ) << " " << d.back( ) << "\n";

   cout << "------\n";

   queue<int> q;
   q.push(3);                    // { 3 }
   cout << q.front( ) << " " << q.back( ) << "\n";
   q.push(1);                    // { 3, 1 }
   cout << q.front( ) << " " << q.back( ) << "\n";
   q.push(7);                    // { 3, 1, 7 }
   cout << q.front( ) << " " << q.back( ) << "\n";
   q.pop( );                     // { 1, 7 }
   cout << q.front( ) << " " << q.back( ) << "\n";
}
