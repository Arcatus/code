// ejemplo de uso de stack de C++
// top( ), push( ) y pop( ) equivalen a back( ), push_back( ) y pop_back( ) de vector y deque
#include <deque>
#include <iostream>
#include <stack>
using namespace std;

int main( )
{
   deque<int> d;
   d.push_back(3);               // { 3 }
   cout << d.back( ) << "\n";
   d.push_back(1);               // { 3, 1 }
   cout << d.back( ) << "\n";
   d.push_back(7);               // { 3, 1, 7 }
   cout << d.back( ) << "\n";
   d.pop_back( );                // { 3, 1 }
   cout << d.back( ) << "\n";

   cout << "------\n";

   stack<int> s;
   s.push(3);                    // { 3 }
   cout << s.top( ) << "\n";
   s.push(1);                    // { 3, 1 }
   cout << s.top( ) << "\n";
   s.push(7);                    // { 3, 1, 7 }
   cout << s.top( ) << "\n";
   s.pop( );                     // { 3, 1 }
   cout << s.top( ) << "\n";
}
