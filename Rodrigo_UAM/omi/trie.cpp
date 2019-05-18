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
      
      return actual->nivel_.find('\0') != actual->nivel_.end( );
   }
   
   bool elimina(const std::string& s)
   {
      trie* actual = this;
      
      for (int i = 0; i < s.size( ); ++i) {
         std::map<char, trie*>::iterator res = actual->nivel_.find(s[i]);
         
         if (res == actual->nivel_.end( )) {
            return false;
         }

         actual = res->second;
      }
      
      return actual->nivel_.erase('\0') > 0;
   }
   
private:
   std::map<char, trie*> nivel_;
};

int main( )
{
   trie t;
   
   t.inserta("perro");
   t.inserta("paco");
   t.inserta("casa");
   
   std::cout << t.encuentra("beto") << '\n';
   std::cout << t.encuentra("perro") << '\n';
   
   t.elimina("perro");
   
   std::cout << t.encuentra("perro") << '\n';
}