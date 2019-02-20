#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <queue>

using std::make_pair;
using std::string;
using std::pair;
using std::map;
using std::set;
using std::queue;

typedef map<unsigned int,pair<string,string>> typeTable;
typedef map<pair<string,string>,string> mapss;
typedef map<string,string> mss;
typedef queue<pair<string,unsigned int>> qpss;

struct DFA
{
    unsigned int startingState = { 0 };
    set<unsigned int> finalStates;
    map<pair<unsigned int,string>,unsigned int> transitionTable;
};

class Lexer
{
public:
    Lexer();
    ~Lexer();
    void init(typeTable& tabla_simbolos);
    void printTokens();
    void printTablaSimbolos();
    qpss& getTokens();

private:
    bool dfaStart(  DFA* dfa, 
                    std::istream& inputStream, 
                    bool no_alpha = true);
    void dfaAddTransition(  DFA* dfa, 
                            unsigned int state, 
                            string symbol, 
                            unsigned int newState);
    void dfaAddFinalState(  DFA* dfa, 
                            unsigned int state);
    bool new_line;
    unsigned int n_linea;
    int state_save; 
    char symbol;
    string Address;
    string relopAddress;
    string symbol_in;
    string SGN_ANT;
    typeTable tabla_simbolos;
    qpss bolsa_token;
};

#endif // LEXER_H