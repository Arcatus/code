#include <cstddef>
#include <iostream>
#include <map>
#include <string>
#include <utility>

class trie {
public:
   bool inserta(const std::string& s)
   {
      trie* actual = this;
      
      for (int i = 0; i < s.size( ); ++i) {
         trie*& siguiente = actual->nivel_[s[i]];
      
         if (siguiente == NULL) {
            siguiente = new trie;     
         }
         
         actual = siguiente;
      }
      
      return actual->nivel_.insert(std::make_pair('\0', static_cast<trie*>(NULL))).second;
   }
   
   bool encuentra(const std::string& s)
   {
      trie* actual = this;
      
      for (int i = 0; i < s.size( ); ++i) {
         std::map<char, trie*>::iterator res = actual->nivel_.find(s[i]);
         
         if (res == actual->nivel_.end( )) {
            return false;
         }

         actual = res->second;
      }

      if ( actual->nivel_ )
      {

      }
      
      return actual->nivel_.find('\0') != actual->nivel_.end( );
   }
   
private:
   std::map<char, trie*> nivel_;
};

int main( )
{
   ios::sync_with_stdio(false);
   cin.tie(0);

   trie t;

   int n;

   cin >> n;
   string buffer;

   for (int i=0;i<n;++i)
   {
      cin >> buffer;
      t.inserta(buffer);
   }

   cin >> buffer;



   return 0;
}