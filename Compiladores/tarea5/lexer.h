#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <map>
#include <set>
#include <utility>
#include <cctype>
#include <vector>
#include <locale>
#include <queue>

bool new_line = true;

unsigned int n_linea = 1;

int state_save; char symbol;

std::string index_sintax, symbol_in, SGN_ANT;

std::queue<std::string> bolsa_token;

std::istream& inputStream(std::cin);

std::set<std::string> tabla_simbolos;
std::map<std::string, std::string> agrupadores;

std::string getToken()
{
	std::string ret = bolsa_token.front();
	bolsa_token.pop();
	return ret;
}

struct DFA
{
    unsigned int startingState = { 0 };
    std::set<unsigned int> finalStates;
    std::map<std::pair<unsigned int, std::string>, unsigned int> transitionTable;
};

void dfaAddTransition(DFA* dfa, unsigned int state, std::string symbol,
                      unsigned int newState)
{
    dfa->transitionTable.emplace(std::make_pair(
        std::pair<unsigned int, std::string >(state, symbol), newState));
}

void dfaAddFinalState(DFA* dfa, unsigned int state)
{
    dfa->finalStates.emplace(state);
}

bool dfaStart(DFA* dfa, std::istream& inputStream, bool no_alpha = true)
{
    unsigned int currentState = dfa->startingState;

    index_sintax = "";
    state_save = 0;

    while(inputStream.good())
    {
        symbol = inputStream.get();

        if ( isalpha(symbol) > 0 && no_alpha)
        {
            symbol_in = "letra"; index_sintax+=symbol;
        } 
        else if ( isdigit(symbol) > 0 )
        {
            symbol_in = "digit"; index_sintax+=symbol;
        } 
        else 
        {
            symbol_in = symbol;
        } 

        std::pair<unsigned int, std::string> transition = {currentState, symbol_in};

        if(dfa->transitionTable.count(transition) == 0 )
        {
            inputStream.putback(symbol);

            if(dfa->finalStates.count(currentState) > 0 )
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        state_save = currentState;
        SGN_ANT = symbol;

        currentState = dfa->transitionTable[transition];
    }

    if(dfa->finalStates.count(currentState) > 0)
    {
        return true;
    }
    return false;
}


#endif // LEXER_H

