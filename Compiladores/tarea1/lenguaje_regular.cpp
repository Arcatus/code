#include <iostream>
#include <set>
#include <map>
#include <utility>

struct DFA
{
    unsigned int startingState = { 0 };
    std::set<unsigned int> finalStates;
    std::map<std::pair<unsigned int, char>, unsigned int> transitionTable;
};

void dfaAddTransition(DFA* dfa, unsigned int state, char symbol,
                      unsigned int newState)
{
    dfa->transitionTable.emplace(std::make_pair(
        std::pair<unsigned int, char>(state, symbol), newState));
}

void dfaAddFinalState(DFA* dfa, unsigned int state)
{
    dfa->finalStates.emplace(state);
}

bool dfaStart(DFA* dfa, std::istream& inputStream)
{
    unsigned int currentState = dfa->startingState;

    while(inputStream.good())
    {
        char tmp = inputStream.get();

        inputStream.putback(tmp);

        char symbol = inputStream.get();

        if (!inputStream.good()){
            
            if (dfa->finalStates.count(currentState) > 0)
                return true;

            return false;
        }

        std::pair<unsigned int, char> transition = { currentState, symbol };

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
        currentState = dfa->transitionTable[transition];
        if (currentState == 4){
            std::cout << "ERROR" << std::endl;
            return false;
        }
    }

    if(dfa->finalStates.count(currentState) > 0)
    {
        return true;
    }

    return false;
}

int main()
{
    DFA dfa_l1, dfa_l2, dfa_blanks;

    dfaAddTransition(&dfa_l1, 0, 'a', 1);
    dfaAddTransition(&dfa_l1, 0, 'b', 4);
    dfaAddTransition(&dfa_l1, 1, 'a', 2);
    dfaAddTransition(&dfa_l1, 1, 'b', 3);
    dfaAddTransition(&dfa_l1, 2, 'a', 2);
    dfaAddTransition(&dfa_l1, 2, 'b', 3);
    dfaAddTransition(&dfa_l1, 3, 'a', 2);
    dfaAddTransition(&dfa_l1, 3, 'b', 3);
    dfaAddTransition(&dfa_l1, 4, 'a', 4);
    dfaAddTransition(&dfa_l1, 4, 'b', 4);
    
    dfaAddFinalState(&dfa_l1, 2);

    dfaAddTransition(&dfa_l2, 0, 'x', 1);
    dfaAddTransition(&dfa_l2, 0, 'y', 4);
    dfaAddTransition(&dfa_l2, 0, 'z', 4);
    dfaAddTransition(&dfa_l2, 1, 'x', 4);
    dfaAddTransition(&dfa_l2, 1, 'y', 2);
    dfaAddTransition(&dfa_l2, 1, 'z', 3);
    dfaAddTransition(&dfa_l2, 2, 'x', 1);
    dfaAddTransition(&dfa_l2, 2, 'y', 4);
    dfaAddTransition(&dfa_l2, 2, 'z', 4);
    dfaAddTransition(&dfa_l2, 3, 'x', 1);
    dfaAddTransition(&dfa_l2, 3, 'y', 4);
    dfaAddTransition(&dfa_l2, 3, 'z', 4);
    dfaAddTransition(&dfa_l2, 4, 'x', 4);
    dfaAddTransition(&dfa_l2, 4, 'y', 4);
    dfaAddTransition(&dfa_l2, 4, 'z', 4);

    dfaAddFinalState(&dfa_l2, 2);
    dfaAddFinalState(&dfa_l2, 3);

    dfaAddTransition(&dfa_blanks, 0, '\n', 1);
    dfaAddTransition(&dfa_blanks, 0, '\t', 1);
    dfaAddTransition(&dfa_blanks, 0, ' ' , 1);
    dfaAddTransition(&dfa_blanks, 1, '\n', 1);
    dfaAddTransition(&dfa_blanks, 1, '\t', 1);
    dfaAddTransition(&dfa_blanks, 1, ' ' , 1);

    dfaAddFinalState(&dfa_blanks, 1);

    std::istream& inputStream(std::cin);


    while(inputStream.good())
    {
        if ( dfaStart(&dfa_blanks,inputStream )){
            std::cout << "BLANK" << std::endl;

        } else if ( dfaStart(&dfa_l1,inputStream) ){
            std::cout << "L1" << std::endl;

        } else if ( dfaStart(&dfa_l2,inputStream) ){
            std::cout << "L2" << std::endl;
        }

    }

    return 0;
}
